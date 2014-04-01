/*  Copyright (C) 2013-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_F_ABS_H
#define LIBSIMDPP_SIMDPP_CORE_F_ABS_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/expr/f_abs.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif


/** Computes absolute value of floating point values.

    @code
    r0 = abs(a0)
    ...
    rN = abs(aN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-AVX2, 1-2}
    @icost{ALTIVEC, 1-2}

    @par 256-bit version:
    @icost{SSE2-SSE4.1, 2-3}
    @icost{NEON, 2}
    @icost{AVX-AVX2, 1-2}
    @icost{ALTIVEC, 2-3}
*/
template<unsigned N, class E>
float32<N, expr_abs<float32<N,E>>> abs(float32<N,E> a)
{
    return { { a }, 0 };
}

/** Computes absolute value of floating point values.

    @code
    r0 = abs(a0)
    ...
    rN = abs(aN)
    @endcode

    @par 128-bit version:
    @novec{NEON, ALTIVEC}
    @icost{SSE2-AVX2, 1-2}

    @par 256-bit version:
    @novec{NEON, ALTIVEC}
    @icost{SSE2-SSE4.1, 2-3}
    @icost{AVX-AVX2, 1-2}
*/
template<unsigned N, class E>
float64<N, expr_abs<float64<N,E>>> abs(float64<N,E> a)
{
    return { { a }, 0 };
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

