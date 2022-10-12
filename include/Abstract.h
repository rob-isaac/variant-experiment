#pragma once

#include <cstddef>

namespace vxp {

class Abstract {
public:
  virtual ~Abstract() = default;
  Abstract(const Abstract& other) = delete;
  Abstract(Abstract&& other) = delete;
  Abstract& operator=(const Abstract& other) = delete;
  Abstract& operator=(Abstract&& other) = delete;
  Abstract() = default;
  virtual size_t foo() = 0;
};

}  // namespace vxp
