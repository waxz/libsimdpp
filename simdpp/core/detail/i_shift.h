/*  libsimdpp
    Copyright (C) 2013  Povilas Kanapickas povilas@radix.lt
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_DETAIL_I_SHIFT_H
#define LIBSIMDPP_SIMDPP_CORE_DETAIL_I_SHIFT_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif

// forward declarations
inline int16x8 shift_r(int16x8, unsigned);
inline uint16x8 shift_r(uint16x8, unsigned);
inline basic_int16x8 shift_l(basic_int16x8, unsigned);
inline int64x2 shift_r(int64x2, unsigned);
inline uint64x2 shift_r(uint64x2, unsigned);
inline basic_int64x2 shift_l(basic_int64x2, unsigned);
template<unsigned count> int16x8 shift_r(int16x8);
template<unsigned count> uint16x8 shift_r(uint16x8);
template<unsigned count> basic_int16x8 shift_l(basic_int16x8);
template<unsigned count> int32x4 shift_r(int32x4);

inline int16x16 shift_r(int16x16, unsigned);
inline uint16x16 shift_r(uint16x16, unsigned);
inline basic_int16x16 shift_l(basic_int16x16, unsigned);
inline int64x4 shift_r(int64x4, unsigned);
inline uint64x4 shift_r(uint64x4, unsigned);
inline basic_int64x4 shift_l(basic_int64x4, unsigned);
template<unsigned count> int16x16 shift_r(int16x16);
template<unsigned count> uint16x16 shift_r(uint16x16);
template<unsigned count> basic_int16x16 shift_l(basic_int16x16);
template<unsigned count> int32x8 shift_r(int32x8);


namespace detail {

template<unsigned count, class V>
struct shift_u8_mask;

template<class V>
struct shift_u8_mask<0,V> { V operator()() { return V::make_const(0x00); } };
template<class V>
struct shift_u8_mask<1,V> { V operator()() { return V::make_const(0x01); } };
template<class V>
struct shift_u8_mask<2,V> { V operator()() { return V::make_const(0x03); } };
template<class V>
struct shift_u8_mask<3,V> { V operator()() { return V::make_const(0x07); } };
template<class V>
struct shift_u8_mask<4,V> { V operator()() { return V::make_const(0x0f); } };
template<class V>
struct shift_u8_mask<5,V> { V operator()() { return V::make_const(0x1f); } };
template<class V>
struct shift_u8_mask<6,V> { V operator()() { return V::make_const(0x3f); } };
template<class V>
struct shift_u8_mask<7,V> { V operator()() { return V::make_const(0x7f); } };
template<class V>
struct shift_u8_mask<8,V> { V operator()() { return V::make_const(0xff); } };

} // namespace detail
#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

