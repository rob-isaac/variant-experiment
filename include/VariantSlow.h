#pragma once

#include <cstddef>
#include <cstdlib>
#include <tuple>

#include "Utils.h"
namespace vxp {

using VariantSlowImpls =
    std::tuple<class VariantSlowImpl1, class VariantSlowImpl2>;

class VariantSlow {
public:
  template <typename Impl>
  VariantSlow(Impl* /*unused*/)
      : tag_(TupleIndex<Impl, VariantSlowImpls>::value) {}
  size_t foo();
  template <typename Func>
  decltype(auto) RunOnDerived(Func&& func) {
    switch (tag_) {
    case 0:
      return func(
          reinterpret_cast<std::tuple_element_t<0, VariantSlowImpls>*>(this));
    case 1:
      return func(
          reinterpret_cast<std::tuple_element_t<1, VariantSlowImpls>*>(this));
    }
    std::abort();
  }

private:
  size_t tag_{};
};

}  // namespace vxp
