#[cfg(all(
    not(feature = "byte"),
    not(feature = "64"),
    not(feature = "word_sse41")
))]
compile_error!("at least one of the features: byte, 64, word_sse41 must be enabled");

#[cfg(all(feature = "word_sse41", not(target_feature = "sse4.1")))]
compile_error!("sse4.1 must be enabled for the word_sse41 feature");

use std::env;
use std::path::{Path, PathBuf};

fn main() {
    let mut c = cc::Build::new();
    let root = PathBuf::from(env::var_os("CARGO_MANIFEST_DIR").unwrap());
    let src = dunce::canonicalize(root.join("src")).unwrap();
    let vendor = dunce::canonicalize(root.join("vendor")).unwrap();

    println!(
        "cargo:include={}",
        env::join_paths([&src, &vendor]).unwrap().to_str().unwrap()
    );
    println!(
        "cargo:rerun-if-changed={}/rans_byte_wrapper.c",
        src.to_str().unwrap()
    );
    println!(
        "cargo:rerun-if-changed={}/rans_byte_wrapper.h",
        src.to_str().unwrap()
    );
    println!(
        "cargo:rerun-if-changed={}/rans_64_wrapper.c",
        src.to_str().unwrap()
    );
    println!(
        "cargo:rerun-if-changed={}/rans_64_wrapper.h",
        src.to_str().unwrap()
    );
    println!(
        "cargo:rerun-if-changed={}/rans_word_sse41_wrapper.c",
        src.to_str().unwrap()
    );
    println!(
        "cargo:rerun-if-changed={}/rans_word_sse41_wrapper.h",
        src.to_str().unwrap()
    );
    c.include(&src);
    c.include(&vendor);
    c.pic(true);

    if let Ok(target_features) = env::var("CARGO_CFG_TARGET_FEATURE") {
        if target_features.split(',').any(|x| x == "sse4.1") {
            c.flag_if_supported("-msse4.1");
        }
    }

    c.warnings(false);

    let files: Vec<&str> = vec![
        #[cfg(feature = "byte")]
        "src/rans_byte_wrapper.c",
        #[cfg(feature = "64")]
        "src/rans_64_wrapper.c",
        #[cfg(feature = "word_sse41")]
        "src/rans_word_sse41_wrapper.c",
    ];

    for file in files {
        c.file(file);
    }

    c.compile("ryg_rans");

    #[cfg(feature = "byte")]
    gen_bindings(&src, &vendor, "rans_byte");
    #[cfg(feature = "64")]
    gen_bindings(&src, &vendor, "rans_64");
    #[cfg(feature = "word_sse41")]
    gen_bindings(&src, &vendor, "rans_word_sse41");
}

fn gen_bindings(src: &Path, vendor: &Path, mod_name: &str) {
    let bindings = bindgen::Builder::default()
        .clang_arg(format!("-I{}", vendor.to_str().unwrap()))
        .header(format!("{}/{}_wrapper.h", src.to_str().unwrap(), mod_name))
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
        .allowlist_function("rans_.*")
        .allowlist_type("Rans.*")
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join(format!("{}.rs", mod_name)))
        .expect("Couldn't write bindings!");
}
