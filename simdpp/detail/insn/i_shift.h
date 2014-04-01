/*  Copyright (C) 2011-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_DETAIL_INSN_I_SHIFT_H
#define LIBSIMDPP_SIMDPP_DETAIL_INSN_I_SHIFT_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif

template<unsigned N, class E>
uint8<N, uint8<N>> shift_l(uint8<N,E> a, unsigned count);
template<unsigned N, class E>
uint16<N, uint16<N>> shift_l(uint16<N,E> a, unsigned count);
template<unsigned N, class E>
uint32<N, uint32<N>> shift_l(uint32<N,E> a, unsigned count);
template<unsigned N, class E>
uint64<N, uint64<N>> shift_l(uint64<N,E> a, unsigned count);

template<unsigned count, unsigned N, class E>
uint8<N, uint8<N>> shift_l(uint8<N,E> a);
template<unsigned count, unsigned N, class E>
uint16<N, uint16<N>> shift_l(uint16<N,E> a);
template<unsigned count, unsigned N, class E>
uint32<N, uint32<N>> shift_l(uint32<N,E> a);
template<unsigned count, unsigned N, class E>
uint64<N, uint64<N>> shift_l(uint64<N,E> a);

template<unsigned N, class E>
int8<N, int8<N>> shift_r(int8<N,E> a, unsigned count);
template<unsigned N, class E>
int16<N, int16<N>> shift_r(int16<N,E> a, unsigned count);
template<unsigned N, class E>
int32<N, int32<N>> shift_r(int32<N,E> a, unsigned count);
template<unsigned N, class E>
int64<N, int64<N>> shift_r(int64<N,E> a, unsigned count);

template<unsigned count, unsigned N, class E>
int8<N, int8<N>> shift_r(int8<N,E> a);
template<unsigned count, unsigned N, class E>
int16<N, int16<N>> shift_r(int16<N,E> a);
template<unsigned count, unsigned N, class E>
int32<N, int32<N>> shift_r(int32<N,E> a);
template<unsigned count, unsigned N, class E>
int64<N, int64<N>> shift_r(int64<N,E> a);

template<unsigned N, class E>
uint8<N, uint8<N>> shift_r(uint8<N,E> a, unsigned count);
template<unsigned N, class E>
uint16<N, uint16<N>> shift_r(uint16<N,E> a, unsigned count);
template<unsigned N, class E>
uint32<N, uint32<N>> shift_r(uint32<N,E> a, unsigned count);
template<unsigned N, class E>
uint64<N, uint64<N>> shift_r(uint64<N,E> a, unsigned count);

template<unsigned count, unsigned N, class E>
uint8<N, uint8<N>> shift_r(uint8<N,E> a);
template<unsigned count, unsigned N, class E>
uint16<N, uint16<N>> shift_r(uint16<N,E> a);
template<unsigned count, unsigned N, class E>
uint32<N, uint32<N>> shift_r(uint32<N,E> a);
template<unsigned count, unsigned N, class E>
uint64<N, uint64<N>> shift_r(uint64<N,E> a);

namespace detail {
namespace insn {

template<unsigned count, class V>
struct shift_u8_mask;

template<class V>
struct shift_u8_mask<0,V> { V operator()() { return make_uint(0x00); } };
template<class V>
struct shift_u8_mask<1,V> { V operator()() { return make_uint(0x01); } };
template<class V>
struct shift_u8_mask<2,V> { V operator()() { return make_uint(0x03); } };
template<class V>
struct shift_u8_mask<3,V> { V operator()() { return make_uint(0x07); } };
template<class V>
struct shift_u8_mask<4,V> { V operator()() { return make_uint(0x0f); } };
template<class V>
struct shift_u8_mask<5,V> { V operator()() { return make_uint(0x1f); } };
template<class V>
struct shift_u8_mask<6,V> { V operator()() { return make_uint(0x3f); } };
template<class V>
struct shift_u8_mask<7,V> { V operator()() { return make_uint(0x7f); } };
template<class V>
struct shift_u8_mask<8,V> { V operator()() { return make_uint(0xff); } };

} // namespace detail
} // namespace insn
#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

