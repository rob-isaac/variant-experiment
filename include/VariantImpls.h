#pragma once

#include <cassert>
#include <vector>

#include "Variant.h"

namespace vxp {
class VariantImpl1 : public Variant {
public:
  VariantImpl1(size_t counter) : Variant(this), counter_(counter) {}
  size_t foo() { return counter_++; }

private:
  size_t counter_{};
};

class VariantImpl2 : public Variant {
public:
  VariantImpl2(size_t size) : Variant(this), vec_(size) { assert(size != 0); }
  size_t foo() {
    auto ret = vec_[idx_++];
    if (idx_ == vec_.size()) {
      idx_ = 0;
    }
    return ret;
  }

private:
  std::vector<size_t> vec_{};
  size_t idx_{};
};
}  // namespace vxp
