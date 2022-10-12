#pragma once

#include <cstddef>
#include <cstdlib>
#include <tuple>

#include "Utils.h"

namespace vxp {
using VariantImpls = std::tuple<class VariantImpl1, class VariantImpl2>;

class Variant {
public:
  template <typename Impl>
  Variant(Impl* /*unused*/) : tag_(TupleIndex<Impl, VariantImpls>::value) {}
  size_t foo();
  template <typename Func>
  decltype(auto) RunOnDerived(Func&& func);

private:
  size_t tag_{};
};
}  // namespace vxp

#include "Variant.ipp"
