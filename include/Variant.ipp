#pragma once

#include "VariantImpls.h"

template <typename Func>
decltype(auto)
vxp::Variant::RunOnDerived(Func&& func) {
  switch (tag_) {
  case 0:
    return func(reinterpret_cast<std::tuple_element_t<0, VariantImpls>*>(this));
  case 1:
    return func(reinterpret_cast<std::tuple_element_t<1, VariantImpls>*>(this));
  }
  std::abort();
}

inline size_t
vxp::Variant::foo() {
  return RunOnDerived([](auto* derived) { return derived->foo(); });
}
