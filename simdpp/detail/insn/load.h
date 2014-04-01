/*  Copyright (C) 2011-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_DETAIL_INSN_LOAD_H
#define LIBSIMDPP_SIMDPP_DETAIL_INSN_LOAD_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/types/traits.h>
#include <simdpp/detail/align.h>
#include <simdpp/detail/insn/mem_unpack.h>
#include <simdpp/adv/transpose.h>
#include <simdpp/null/memory.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif
namespace detail {

template<class V>
struct is_expr_vec_load { static const bool value = false; };
template<>
struct is_expr_vec_load<expr_vec_load> { static const bool value = true; };

namespace insn {

// collect some boilerplate here
template<class V>
void v_load(V& a, const char* p);

inline void i_load(uint8x16& a, const char* p)
{
    p = detail::assume_aligned(p, 16);
#if SIMDPP_USE_NULL
    null::load(a, p);
#elif SIMDPP_USE_SSE2
    a = _mm_load_si128(reinterpret_cast<const __m128i*>(p));
#elif SIMDPP_USE_NEON
    a = vreinterpretq_u32_u64(vld1q_u64(reinterpret_cast<const uint64_t*>(p)));
#elif SIMDPP_USE_ALTIVEC
    a = vec_ldl(0, reinterpret_cast<const uint8_t*>(p));
#endif
}

inline void i_load(uint16x8& a, const char* p) { uint8x16 r; i_load(r, p); a = r;  }
inline void i_load(uint32x4& a, const char* p) { uint8x16 r; i_load(r, p); a = r;  }
inline void i_load(uint64x2& a, const char* p) { uint8x16 r; i_load(r, p); a = r;  }

inline void i_load(float32x4& a, const char* p)
{
    const float* q = reinterpret_cast<const float*>(p);
    q = detail::assume_aligned(q, 16);
#if SIMDPP_USE_NULL
    null::load(a, q);
#elif SIMDPP_USE_SSE2
    a = _mm_load_ps(q);
#elif SIMDPP_USE_NEON
    a = vld1q_f32(q);
#elif SIMDPP_USE_ALTIVEC
    a = vec_ldl(0, q);
#endif
}

inline void i_load(float64x2& a, const char* p)
{
    const double* q = reinterpret_cast<const double*>(p);
    q = detail::assume_aligned(q, 16);
#if SIMDPP_USE_NULL || SIMDPP_USE_ALTIVEC || SIMDPP_USE_NEON
    null::load(a, q);
#elif SIMDPP_USE_SSE2
    a = _mm_load_pd(q);
#endif
}

#if SIMDPP_USE_AVX2
inline void i_load(uint8x32& a,  const char* p)
{
    a = _mm256_load_si256(reinterpret_cast<const __m256i*>(p));
}
inline void i_load(uint16x16& a, const char* p)
{
    a = _mm256_load_si256(reinterpret_cast<const __m256i*>(p));
}
inline void i_load(uint32x8& a,  const char* p)
{
    a = _mm256_load_si256(reinterpret_cast<const __m256i*>(p));
}
inline void i_load(uint64x4& a,  const char* p)
{
    a = _mm256_load_si256(reinterpret_cast<const __m256i*>(p));
}
#endif
#if SIMDPP_USE_AVX
inline void i_load(float32x8& a, const char* p)
{
    a = _mm256_load_ps(reinterpret_cast<const float*>(p));
}
inline void i_load(float64x4& a, const char* p)
{
    a = _mm256_load_pd(reinterpret_cast<const double*>(p));
}
#endif

template<unsigned N>
void i_load(uint8<N>& a,  const char* p) { v_load(a, p); }
template<unsigned N>
void i_load(uint16<N>& a, const char* p) { v_load(a, p); }
template<unsigned N>
void i_load(uint32<N>& a, const char* p) { v_load(a, p); }
template<unsigned N>
void i_load(uint64<N>& a, const char* p) { v_load(a, p); }
template<unsigned N>
void i_load(float32<N>& a, const char* p){ v_load(a, p); }
template<unsigned N>
void i_load(float64<N>& a, const char* p){ v_load(a, p); }

template<class V>
void v_load(V& a, const char* p)
{
    unsigned veclen = sizeof(typename V::base_vector_type);

    for (unsigned i = 0; i < V::vec_length; ++i) {
        i_load(a[i], p);
        p += veclen;
    }
}

template<class V>
struct i_load_dispatch {
    static V run(const char* p)
    {
        V r;
        i_load(r, p);
        return r;
    }
};

template<>
struct i_load_dispatch<expr_vec_load> {
    static expr_vec_load run(const char* p)
    {
        expr_vec_load r;
        r.a = p;
        return r;
    }
};

} // namespace insn

template<class V>
void construct_eval(V& v, const expr_vec_load& e)
{
    typename detail::remove_sign<V>::type r;
    insn::i_load(r, e.a);
    v = r;
}

} // namespace detail
#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

