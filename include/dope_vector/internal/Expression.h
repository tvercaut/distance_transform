// Copyright (c) 2016 Giorgio Marcias & Maurizio Kovacic
//
// This source code is part of DopeVector header library
// and it is subject to Apache 2.0 License.
//
// Author: Giorgio Marcias
// email: marcias.giorgio@gmail.com
// Author: Maurizio Kovacic
// email: maurizio.kovacic@gmail.com

#ifndef INCLUDE_DOPE_VECTOR_INTERNAL_EXPRESSION_H_
#define INCLUDE_DOPE_VECTOR_INTERNAL_EXPRESSION_H_

#include <array>
#include <functional>

#include "dope_vector/internal/Common.h"

namespace dope {

namespace internal {

template <class E, typename T, SizeType Dimension>
class StaticArrayExpression {
 public:
  inline T getAt(const SizeType i) const;

  inline operator E const &() const;

  inline operator E &();
};

template <class E, typename T, SizeType Dimension, typename Op>
class StaticArrayUnaryExpression
    : public StaticArrayExpression<
          StaticArrayUnaryExpression<E, T, Dimension, Op>, T, Dimension> {
 private:
  const E &_e;
  mutable std::array<std::function<T()>, Dimension> _values;
  static const Op _op;

 public:
  inline explicit StaticArrayUnaryExpression(const E &e);

  inline T operator[](const SizeType i) const;
};

template <class El, class Er, typename T, SizeType Dimension, typename Op>
class StaticArrayBinaryExpression
    : public StaticArrayExpression<
          StaticArrayBinaryExpression<El, Er, T, Dimension, Op>, T, Dimension> {
 private:
  const El &_el;
  const Er &_er;
  mutable std::array<std::function<T()>, Dimension> _values;
  static const Op _op;

 public:
  inline StaticArrayBinaryExpression(const El &el, const Er &er);

  inline T operator[](const SizeType i) const;
};

template <class E, typename T, SizeType Dimension>
inline StaticArrayUnaryExpression<E, T, Dimension, std::negate<T>> operator-(
    const StaticArrayExpression<E, T, Dimension> &e);

template <class El, class Er, typename T, SizeType Dimension>
inline StaticArrayBinaryExpression<El, Er, T, Dimension, std::plus<T>>
operator+(const StaticArrayExpression<El, T, Dimension> &el,
          const StaticArrayExpression<Er, T, Dimension> &er);

template <class El, class Er, typename T, SizeType Dimension>
inline StaticArrayBinaryExpression<El, Er, T, Dimension, std::minus<T>>
operator-(const StaticArrayExpression<El, T, Dimension> &el,
          const StaticArrayExpression<Er, T, Dimension> &er);

template <class El, class Er, typename T, SizeType Dimension>
inline StaticArrayBinaryExpression<El, Er, T, Dimension, std::multiplies<T>>
operator*(const StaticArrayExpression<El, T, Dimension> &el,
          const StaticArrayExpression<Er, T, Dimension> &er);

template <class El, class Er, typename T, SizeType Dimension>
inline StaticArrayBinaryExpression<El, Er, T, Dimension, std::divides<T>>
operator/(const StaticArrayExpression<El, T, Dimension> &el,
          const StaticArrayExpression<Er, T, Dimension> &er);

template <class El, class Er, typename T, SizeType Dimension>
inline StaticArrayBinaryExpression<El, Er, T, Dimension, std::modulus<T>>
operator%(const StaticArrayExpression<El, T, Dimension> &el,
          const StaticArrayExpression<Er, T, Dimension> &er);

}  // namespace internal

}  // namespace dope

#include "dope_vector/internal/inlines/Expression.hpp"

#ifdef DOPE_USE_EIGEN
#include "dope_vector/internal/eigen_support/EigenExpression.h"
#endif

#endif  // INCLUDE_DOPE_VECTOR_INTERNAL_EXPRESSION_H_
