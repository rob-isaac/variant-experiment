#pragma once

#include <cassert>
#include <vector>

#include "VariantSlow.h"

namespace vxp {

class VariantSlowImpl1 : public VariantSlow {
public:
  VariantSlowImpl1(size_t counter) : VariantSlow(this), counter_(counter) {}
  size_t foo() { return counter_++; }

private:
  size_t counter_{};
};

class VariantSlowImpl2 : public VariantSlow {
public:
  VariantSlowImpl2(size_t size) : VariantSlow(this), vec_(size) {
    assert(size != 0);
  }
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
