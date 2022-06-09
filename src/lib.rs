#![allow(deref_nullptr)]
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

#[cfg(feature = "byte")]
pub mod rans_byte {
    include!(concat!(env!("OUT_DIR"), "/rans_byte.rs"));
}

#[cfg(feature = "64")]
pub mod rans_64 {
    include!(concat!(env!("OUT_DIR"), "/rans64.rs"));
}

#[cfg(feature = "word_sse41")]
pub mod rans_word_sse41 {
    include!(concat!(env!("OUT_DIR"), "/rans_word_sse41.rs"));
}
