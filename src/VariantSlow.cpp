#include "VariantSlow.h"

#include "VariantSlowImpls.h"

size_t
vxp::VariantSlow::foo() {
  return RunOnDerived([](auto* derived) { return derived->foo(); });
}
