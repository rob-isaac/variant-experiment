#pragma once

#include <cstddef>
#include <tuple>

namespace vxp {

template <class T, class Tuple>
struct TupleIndex;

template <class T, class... Types>
struct TupleIndex<T, std::tuple<T, Types...>> {
  static const size_t value = 0;
};

template <class T, class U, class... Types>
struct TupleIndex<T, std::tuple<U, Types...>> {
  static const size_t value = 1 + TupleIndex<T, std::tuple<Types...>>::value;
};

}  // namespace vxp
