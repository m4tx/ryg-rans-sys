#[cfg(all(
    not(feature = "byte"),
    not(feature = "64"),
    not(feature = "word_sse41")
))]
compile_error!("at least one of the features: byte, 64, word_sse41 must be enabled");

use std::env;
use std::path::PathBuf;

fn main() {
    let mut c = cc::Build::new();
    let root = PathBuf::from(env::var_os("CARGO_MANIFEST_DIR").unwrap());
    let src = dunce::canonicalize(root.join("src")).unwrap();
    let vendor = dunce::canonicalize(root.join("vendor")).unwrap();

    println!(
        "cargo:include={}",
        env::join_paths(&[&src, &vendor]).unwrap().to_str().unwrap()
    );
    println!("cargo:rerun-if-changed=src/*.c");
    println!("cargo:rerun-if-changed=src/*.h");
    c.include(&src);
    c.include(&vendor);
    c.pic(true);

    if let Ok(target_cpu) = env::var("TARGET_CPU") {
        c.flag_if_supported(&format!("-march={}", target_cpu));
    }

    c.warnings(false);

    let mut files: Vec<&str> = Vec::new();
    #[cfg(feature = "byte")]
    files.push("src/rans_byte_wrapper.c");
    #[cfg(feature = "64")]
    files.push("src/rans64_wrapper.c");
    #[cfg(feature = "word_sse41")]
    files.push("src/rans_word_sse41_wrapper.c");

    for file in files {
        c.file(file);
    }

    c.compile("ryg_rans");

    #[cfg(feature = "byte")]
    gen_bindings(&src, &vendor, "rans_byte");
    #[cfg(feature = "64")]
    gen_bindings(&src, &vendor, "rans64");
    #[cfg(feature = "word_sse41")]
    gen_bindings(&src, &vendor, "rans_word_sse41");
}

fn gen_bindings(src: &PathBuf, vendor: &PathBuf, mod_name: &str) {
    let bindings = bindgen::Builder::default()
        .clang_arg(format!("-I{}", vendor.to_str().unwrap()))
        .header(format!("{}/{}_wrapper.h", src.to_str().unwrap(), mod_name))
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .allowlist_function("rans_.*")
        .allowlist_type("Rans.*")
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join(format!("{}.rs", mod_name)))
        .expect("Couldn't write bindings!");
}
