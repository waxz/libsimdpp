/*  Copyright (C) 2013-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_TO_INT64_H
#define LIBSIMDPP_SIMDPP_CORE_TO_INT64_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/core/i_shift_r.h>
#include <simdpp/core/move_l.h>
#include <simdpp/core/zip_lo.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif

/// @{
/** Extends the values of a signed int32x4 vector to 64-bits

    @code
    r0 = (int64_t) a0
    ...
    r3 = (int64_t) a3
    @endcode

    @icost{SSE2-SSSE3, 5}
    @icost{SSE4.1-AVX, 3}
    @icost{NEON, 2}
    @icost{ALTIVEC, 3-4}
*/
inline uint64x4 to_int64(int32x4 a)
{
#if SIMDPP_USE_NULL
    int64x4 r;
    r[0].el(0) = int64_t(a.el(0));
    r[0].el(1) = int64_t(a.el(1));
    r[1].el(0) = int64_t(a.el(2));
    r[1].el(1) = int64_t(a.el(3));
    return r;
#elif SIMDPP_USE_AVX2
    return _mm256_cvtepi32_epi64(a);
#elif SIMDPP_USE_SSE4_1
    uint64x2 r1, r2;
    r1 = _mm_cvtepi32_epi64(a);
    r2 = _mm_cvtepi32_epi64(move4_r<2>(a).eval());
    return combine(r1, r2);
#elif SIMDPP_USE_SSE2 || SIMDPP_USE_ALTIVEC
    int32x4 u;
    u = shift_r(a, 31);
    return (uint64x4) combine(zip4_lo(a, u), zip4_hi(a, u));
#elif SIMDPP_USE_NEON
    int64x2 r1, r2;
    r1 = vmovl_s32(vget_low_s32(a));
    r2 = vmovl_s32(vget_high_s32(a));
    return combine(r1, r2);
#endif
}

// TODO support arbitrary length vectors

/// @{
/** Extends the values of an unsigned int32x4 vector to 64-bits

    @code
    r0 = (uint64_t) a0
    ...
    r3 = (uint64_t) a3
    @endcode

    @icost{SSE2-AVX, 3}
    @icost{NEON, ALTIVEC, 2}
*/
inline uint64x4 to_int64(uint32x4 a)
{
#if SIMDPP_USE_NULL
    uint64x4 r;
    r[0].el(0) = uint64_t(a.el(0));
    r[0].el(1) = uint64_t(a.el(1));
    r[1].el(0) = uint64_t(a.el(2));
    r[1].el(1) = uint64_t(a.el(3));
    return r;
#elif SIMDPP_USE_AVX2
    return _mm256_cvtepu32_epi64(a);
#elif SIMDPP_USE_SSE4_1
    uint64x2 r1, r2;
    r1 = _mm_cvtepu32_epi64(a);
    r2 = _mm_cvtepu32_epi64(move4_r<2>(a).eval());
    return combine(r1, r2);
#elif SIMDPP_USE_SSE2 || SIMDPP_USE_ALTIVEC
    return (uint64x4) combine(zip4_lo(a, uint32x4::zero()),
                              zip4_hi(a, uint32x4::zero()));
#elif SIMDPP_USE_NEON
    int64x2 r1, r2;
    r1 = vmovl_u32(vget_low_u32(a));
    r2 = vmovl_u32(vget_high_u32(a));
    return combine(r1, r2);
#endif
}
/// @}

// TODO support arbitrary length vectors

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

