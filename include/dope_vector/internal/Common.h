// Copyright (c) 2016 Giorgio Marcias & Maurizio Kovacic
//
// This source code is part of DopeVector header library
// and it is subject to Apache 2.0 License.
//
// Author: Giorgio Marcias
// email: marcias.giorgio@gmail.com
// Author: Maurizio Kovacic
// email: maurizio.kovacic@gmail.com

#ifndef INCLUDE_DOPE_VECTOR_INTERNAL_COMMON_H_
#define INCLUDE_DOPE_VECTOR_INTERNAL_COMMON_H_

#include <cstdlib>

#ifndef _SIZETYPE_
#define DOPE_SIZETYPE std::size_t
#endif

namespace dope {

/**
 * @brief SizeType is a common type for indexes. It is possible to change
 *        this by changing the define above: just define _SIZETYPE_ before
 *        including this file.
 */
using SizeType = std::make_unsigned<DOPE_SIZETYPE>::type;

}  // namespace dope

#endif  // INCLUDE_DOPE_VECTOR_INTERNAL_COMMON_H_
