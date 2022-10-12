#pragma once

#include <cassert>
#include <vector>

#include "Abstract.h"

namespace vxp {

class AbstractImpl1 : public Abstract {
public:
  AbstractImpl1(size_t counter) : counter_(counter) {}
  size_t foo() final { return counter_++; }

private:
  size_t counter_{};
};

class AbstractImpl2 : public Abstract {
public:
  AbstractImpl2(size_t size) : vec_(size) { assert(size != 0); }
  size_t foo() final {
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
