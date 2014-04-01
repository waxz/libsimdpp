/*  Copyright (C) 2013-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_I_ADD_SAT_H
#define LIBSIMDPP_SIMDPP_CORE_I_ADD_SAT_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/expr/i_add_sat.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif


/** Adds and saturates signed 8-bit integer values.

    @code
    r0 = signed_saturate(a0 + b0)
    ...
    rN = signed_saturate(aN + bN)
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
template<unsigned N, class E1, class E2>
int8<N, expr_add_sat<int8<N,E1>,
                     int8<N,E2>>> add_sat(int8<N,E1> a,
                                          int8<N,E2> b)
{
    return { { a, b }, 0 };
}

/** Adds and saturates signed 16-bit integer values.

    @code
    r0 = signed_saturate(a0 + b0)
    ...
    rN = signed_saturate(aN + bN)
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
template<unsigned N, class E1, class E2>
int16<N, expr_add_sat<int16<N,E1>,
                      int16<N,E2>>> add_sat(int16<N,E1> a,
                                            int16<N,E2> b)
{
    return { { a, b }, 0 };
}

/** Adds and saturates unsigned 8-bit integer values.

    @code
    r0 = unsigned_saturate(a0 + b0)
    ...
    rN = unsigned_saturate(aN + bN)
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
template<unsigned N, class E1, class E2>
uint8<N, expr_add_sat<uint8<N,E1>,
                      uint8<N,E2>>> add_sat(uint8<N,E1> a,
                                            uint8<N,E2> b)
{
    return { { a, b }, 0 };
}

/** Adds and saturates unsigned 16-bit integer values.

    @code
    r0 = unsigned_saturate(a0 + b0)
    ...
    rN = unsigned_saturate(aN + bN)
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
template<unsigned N, class E1, class E2>
uint16<N, expr_add_sat<uint16<N,E1>,
                       uint16<N,E2>>> add_sat(uint16<N,E1> a,
                                              uint16<N,E2> b)
{
    return { { a, b }, 0 };
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

