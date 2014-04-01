/*  Copyright (C) 2013  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef SIMDPP_TEST_COMMON_VECTORS_H
#define SIMDPP_TEST_COMMON_VECTORS_H

#include <simdpp/simd.h>

namespace SIMDPP_ARCH_NAMESPACE {

template<unsigned L>
struct Vectors {
    static constexpr unsigned length = L;

    union {
        uint8_t c[L];
        uint8_t pu8[L];
        uint16_t pu16[L/2];
        uint32_t pu32[L/4];
        uint64_t pu64[L/8];
        int8_t pi8[L];
        int16_t pi16[L/2];
        int32_t pi32[L/4];
        int64_t pi64[L/8];
        float pf32[L/4];
        double pf64[L/8];
        simdpp::uint8x16 u8[L/16];
        simdpp::uint16x8 u16[L/16];
        simdpp::uint32x4 u32[L/16];
        simdpp::uint64x2 u64[L/16];
        simdpp::int8x16 i8[L/16];
        simdpp::int16x8 i16[L/16];
        simdpp::int32x4 i32[L/16];
        simdpp::int64x2 i64[L/16];
        simdpp::float32x4 f32[L/16];
        simdpp::float64x2 f64[L/16];
        simdpp::uint8x32 du8[L/32];
        simdpp::uint16x16 du16[L/32];
        simdpp::uint32x8 du32[L/32];
        simdpp::uint64x4 du64[L/32];
        simdpp::int8x32 di8[L/32];
        simdpp::int16x16 di16[L/32];
        simdpp::int32x8 di32[L/32];
        simdpp::int64x4 di64[L/32];
        simdpp::float32x8 df32[L/32];
        simdpp::float64x4 df64[L/32];
    };

    Vectors() { reset(); }

    void reset()
    {
        for (unsigned i = 0; i < L; i++) {
            c[i] = i%256;
        }
    }

    void zero()
    {
        for (unsigned i = 0; i < L; i++) {
            c[i] = 0;
        }
    }
};

} // namespace SIMDPP_ARCH_NAMESPACE

#endif
