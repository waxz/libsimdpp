/*  Copyright (C) 2012  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SSE_MATH_INT_H
#define LIBSIMDPP_SSE_MATH_INT_H
#if SIMDPP_USE_SSE2 || defined(DOXYGEN_SHOULD_READ_THIS)

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/not_implemented.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif
namespace sse {


/** Copies sign from the values of one int8x16 vector to another

    @code
    r0 = (b0 > 0) ? a0 : ((b0 == 0) ? 0 : -a0)
    ...
    r15 = (b15 > 0) ? a15 : ((b15 == 0) ? 0 : -a15)
    @endcode
    @unimp{SSE2, SSE3}
*/
inline int8x16 copysign(int8x16 a, int8x16 b)
{
#if SIMDPP_USE_SSSE3
    return _mm_sign_epi8(a,b);
#else
    return SIMDPP_NOT_IMPLEMENTED2(a,b);
#endif
}

/** Copies sign from the values of one int16x8 vector to another

    @code
    r0 = (b0 > 0) ? a0 : ((b0 == 0) ? 0 : -a0)
    ...
    r7 = (b7 > 0) ? a7 : ((b7 == 0) ? 0 : -a7)
    @endcode
    @unimp{SSE2, SSE3}
*/
inline int16x8 copysign(int16x8 a, int16x8 b)
{
#if SIMDPP_USE_SSSE3
    return _mm_sign_epi16(a,b);
#else
    return SIMDPP_NOT_IMPLEMENTED2(a,b);
#endif
}

/** Copies sign from the values of one int32x4 vector to another

    @code
    r0 = (b0 > 0) ? a0 : ((b0 == 0) ? 0 : -a0)
    r1 = (b1 > 0) ? a1 : ((b1 == 0) ? 0 : -a1)
    r2 = (b2 > 0) ? a2 : ((b2 == 0) ? 0 : -a2)
    r3 = (b3 > 0) ? a3 : ((b3 == 0) ? 0 : -a3)
    @endcode
    @unimp{SSE2, SSE3}
*/
inline int32x4 copysign(int32x4 a, int32x4 b)
{
#if SIMDPP_USE_SSSE3
    return _mm_sign_epi32(a, b);
#else
    return SIMDPP_NOT_IMPLEMENTED2(a,b);
#endif
}

/** Adds values in adjacent pairs of two int16x8 vectors

    @code
    r0 = a0 + a1
    ...
    r3 = a6 + a7
    r4 = b0 + b1
    ...
    r7 = b6 + b7
    @endcode
    @unimp{SSE2, SSE3}
*/
inline uint16x8 hadd2(uint16x8 a, uint16x8 b)
{
#if SIMDPP_USE_SSSE3
    return _mm_hadd_epi16(a, b);
#else
    return SIMDPP_NOT_IMPLEMENTED2(a,b);
#endif
}

/** Adds values in adjacent pairs of two int32x4 vectors

    @code
    r0 = a0 + a1
    r1 = a2 + a3
    r2 = b0 + b1
    r3 = b2 + b3
    @endcode
    @unimp{SSE2, SSE3}
*/
inline uint32x4 hadd2(uint32x4 a, uint32x4 b)
{
#if SIMDPP_USE_SSSE3
    return _mm_hadd_epi32(a, b);
#else
    return SIMDPP_NOT_IMPLEMENTED2(a,b);
#endif
}

/** Adds values in adjacent pairs of two int64x2 vectors

    @code
    r0 = a0 + a1
    r1 = b0 + b1
    @endcode
    @icost{3}
*/
inline uint64x2 hadd2(uint64x2 a, uint64x2 b)
{
    uint64x2 ia, ib;
    ia = zip2_lo(a, b);
    ib = zip2_hi(a, b);
    ia = add(ia, ib);
    return ia;
}

/** Adds and saturates values in adjacent pairs of two signed int16x8 vectors

    @code
    r0 = signed_saturate(a0 + a1)
    ...
    r3 = signed_saturate(a6 + a7)
    r4 = signed_saturate(b0 + b1)
    ...
    r7 = signed_saturate(b6 + b7)
    @endcode
    @unimp{SSE2, SSE3}
*/
inline int16x8 hadds2(int16x8 a, int16x8 b)
{
#if SIMDPP_USE_SSSE3
    return _mm_hadds_epi16(a, b);
#else
    return SIMDPP_NOT_IMPLEMENTED2(a,b);
#endif
}

/** Sums the values within each of four int32x4 vector

    @code
    r0 = a0 + a1 + a2 + a3
    r1 = b0 + b1 + b2 + b3
    r2 = c0 + c1 + c2 + c3
    r3 = d0 + d1 + d2 + d3
    @endcode
    @unimp{SSE2, SSE3}
    @icost{3}
*/
inline uint32x4 hadd4(uint32x4 a, uint32x4 b, uint32x4 c, uint32x4 d)
{
#if SIMDPP_USE_SSSE3
    a = hadd2(a, b);
    c = hadd2(c, d);
    a = hadd2(a, c);
    return a;
#else
    return SIMDPP_NOT_IMPLEMENTED4(a, b, c, d);
#endif
}

/** Subtracts values in adjacent pairs of two int16x8 vectors

    @code
    r0 = a0 - a1
    ...
    r3 = a6 - a7
    r4 = b0 - b1
    ...
    r7 = b6 - b7
    @endcode
    @unimp{SSE2, SSE3}
*/
inline uint16x8 hsub2(uint16x8 a, uint16x8 b)
{
#if SIMDPP_USE_SSSE3
    return _mm_hsub_epi16(a, b);
#else
    return SIMDPP_NOT_IMPLEMENTED2(a,b);
#endif
}

/** Subtracts values in adjacent pairs of two int32x4 vectors

    @code
    r0 = a0 - a1
    r1 = a2 - a3
    r2 = b0 - b1
    r3 = b2 - b3
    @endcode
    @unimp{SSE2, SSE3}
*/
inline uint32x4 hsub2(uint32x4 a, uint32x4 b)
{
#if SIMDPP_USE_SSSE3
    return _mm_hsub_epi32(a, b);
#else
    return SIMDPP_NOT_IMPLEMENTED2(a,b);
#endif
}

/** Subtracts values in adjacent pairs of two int64x2 vectors

    @code
    r0 = a0 - a1
    r1 = b0 - b1
    @endcode
    @icost{3}
*/
inline uint64x2 hsub2(uint64x2 a, uint64x2 b)
{
#if SIMDPP_USE_SSSE3
    uint64x2 ia, ib;
    ia = zip2_lo(a, b);
    ib = zip2_hi(a, b);
    ia = sub(ia, ib);
    return ia;
#else
    return SIMDPP_NOT_IMPLEMENTED2(a,b);
#endif
}

/** Subtracts and saturates values in adjacent pairs of two signed int16x8 vectors

    @code
    r0 = signed_saturate(a0 - a1)
    ...
    r3 = signed_saturate(a6 - a7)
    r4 = signed_saturate(b0 - b1)
    ...
    r7 = signed_saturate(b6 - b7)
    @endcode
    @unimp{SSE2, SSE3}
*/
inline int16x8 hsubs2(int16x8 a, int16x8 b)
{
#if SIMDPP_USE_SSSE3
    return _mm_hsubs_epi16(a, b);
#else
    return SIMDPP_NOT_IMPLEMENTED2(a,b);
#endif
}

} // namespace sse
#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif
#endif
