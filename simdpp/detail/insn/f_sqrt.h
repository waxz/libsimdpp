/*  Copyright (C) 2011-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_DETAIL_INSN_F_SQRT_H
#define LIBSIMDPP_SIMDPP_DETAIL_INSN_F_SQRT_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <cmath>
#include <simdpp/types.h>
#include <simdpp/core/f_rsqrt_e.h>
#include <simdpp/core/f_rsqrt_rh.h>
#include <simdpp/null/foreach.h>
#include <simdpp/null/math.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif
namespace detail {
namespace insn {


inline float32x4 i_sqrt(float32x4 a)
{
#if SIMDPP_USE_NULL || (SIMDPP_USE_NEON && !SIMDPP_USE_NEON_FLT_SP)
    return null::foreach<float32x4>(a, [](float a){ return std::sqrt(a); });
#elif SIMDPP_USE_SSE2
    return _mm_sqrt_ps(a);
#elif SIMDPP_USE_NEON_FLT_SP || SIMDPP_USE_ALTIVEC
    float32x4 x;
    x = rsqrt_e(a);
    x = rsqrt_rh(x, a);
    return mul(a, x);
#endif
}

#if SIMDPP_USE_AVX
inline float32x8 i_sqrt(float32x8 a)
{
    return _mm256_sqrt_ps(a);
}
#endif

template<unsigned N>
float32<N> i_sqrt(float32<N> a)
{
    SIMDPP_VEC_ARRAY_IMPL1(float32<N>, i_sqrt, a);
}

// -----------------------------------------------------------------------------

inline float64x2 i_sqrt(float64x2 a)
{
#if SIMDPP_USE_NULL || SIMDPP_USE_NEON || SIMDPP_USE_ALTIVEC
    return null::foreach<float64x2>(a, [](double a){ return std::sqrt(a); });
#elif SIMDPP_USE_SSE2
    return _mm_sqrt_pd(a);
#endif
}

#if SIMDPP_USE_AVX
inline float64x4 i_sqrt(float64x4 a)
{
    return _mm256_sqrt_pd(a);
}
#endif

template<unsigned N>
float64<N> i_sqrt(float64<N> a)
{
    SIMDPP_VEC_ARRAY_IMPL1(float64<N>, i_sqrt, a);
}


} // namespace insn
} // namespace detail
#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

