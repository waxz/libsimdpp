/*  Copyright (C) 2013-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_DETAIL_INSN_F_RCP_E_H
#define LIBSIMDPP_SIMDPP_DETAIL_INSN_F_RCP_E_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#if SIMDPP_USE_NULL || SIMDPP_USE_NEON || SIMDPP_USE_ALTIVEC
    #include <cmath>
    #include <simdpp/null/foreach.h>
    #include <simdpp/null/math.h>
#endif

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif
namespace detail {
namespace insn {


inline float32x4 i_rcp_e(float32x4 a)
{
#if SIMDPP_USE_NULL || (SIMDPP_USE_NEON && !SIMDPP_USE_NEON_FLT_SP)
    return null::foreach<float32x4>(a, [](float a){ return 1.0f / a; });
#elif SIMDPP_USE_SSE2
    return _mm_rcp_ps(a);
#elif SIMDPP_USE_NEON_FLT_SP
    return vrecpeq_f32(a);
#elif SIMDPP_USE_ALTIVEC
    return vec_re((__vector float)a);
#endif
}

#if SIMDPP_USE_AVX
inline float32x8 i_rcp_e(float32x8 a)
{
    return _mm256_rcp_ps(a);
}
#endif

template<unsigned N>
float32<N> i_rcp_e(float32<N> a)
{
    SIMDPP_VEC_ARRAY_IMPL1(float32<N>, i_rcp_e, a);
}

} // namespace insn
} // namespace detail
#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

