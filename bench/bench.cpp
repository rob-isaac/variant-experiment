#include <iostream>
#include <memory>

#include <benchmark/benchmark.h>

#include "Abstract.h"
#include "AbstractImpls.h"
#include "Variant.h"
#include "VariantSlow.h"
#include "VariantSlowImpls.h"

using namespace vxp;

namespace {

void
AbstractCalls1(benchmark::State& state) {
  std::unique_ptr<Abstract> abstract =
      std::make_unique<AbstractImpl1>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(abstract->foo());
  }
}

void
AbstractImplCalls1(benchmark::State& state) {
  std::unique_ptr<AbstractImpl1> impl =
      std::make_unique<AbstractImpl1>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(impl->foo());
  }
}

void
VariantCalls1(benchmark::State& state) {
  std::unique_ptr<Variant> abstract =
      std::make_unique<VariantImpl1>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(abstract->foo());
  }
}

void
VariantImplCalls1(benchmark::State& state) {
  std::unique_ptr<VariantImpl1> impl =
      std::make_unique<VariantImpl1>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(impl->foo());
  }
}

void
VariantSlowCalls1(benchmark::State& state) {
  std::unique_ptr<VariantSlow> abstract =
      std::make_unique<VariantSlowImpl1>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(abstract->foo());
  }
}

void
VariantSlowImplCalls1(benchmark::State& state) {
  std::unique_ptr<VariantSlowImpl1> impl =
      std::make_unique<VariantSlowImpl1>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(impl->foo());
  }
}

void
AbstractCalls2(benchmark::State& state) {
  std::unique_ptr<Abstract> abstract =
      std::make_unique<AbstractImpl2>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(abstract->foo());
    benchmark::ClobberMemory();
  }
}

void
AbstractImplCalls2(benchmark::State& state) {
  std::unique_ptr<AbstractImpl2> impl =
      std::make_unique<AbstractImpl2>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(impl->foo());
    benchmark::ClobberMemory();
  }
}

void
VariantCalls2(benchmark::State& state) {
  std::unique_ptr<Variant> abstract =
      std::make_unique<VariantImpl2>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(abstract->foo());
    benchmark::ClobberMemory();
  }
}

void
VariantImplCalls2(benchmark::State& state) {
  std::unique_ptr<VariantImpl2> impl =
      std::make_unique<VariantImpl2>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(impl->foo());
    benchmark::ClobberMemory();
  }
}

void
VariantSlowCalls2(benchmark::State& state) {
  std::unique_ptr<VariantSlow> abstract =
      std::make_unique<VariantSlowImpl2>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(abstract->foo());
    benchmark::ClobberMemory();
  }
}

void
VariantSlowImplCalls2(benchmark::State& state) {
  std::unique_ptr<VariantSlowImpl2> impl =
      std::make_unique<VariantSlowImpl2>(state.range());
  for (auto _ : state) {
    benchmark::DoNotOptimize(impl->foo());
    benchmark::ClobberMemory();
  }
}
}  // namespace

// The Calls1 functions are benchmarking a simple counter
// increment by either 1 or 4
BENCHMARK(AbstractCalls1)->Range(1, 1 << 2);         //NOLINT
BENCHMARK(AbstractImplCalls1)->Range(1, 1 << 2);     //NOLINT
BENCHMARK(VariantCalls1)->Range(1, 1 << 2);          //NOLINT
BENCHMARK(VariantImplCalls1)->Range(1, 1 << 2);      //NOLINT
BENCHMARK(VariantSlowCalls1)->Range(1, 1 << 2);      //NOLINT
BENCHMARK(VariantSlowImplCalls1)->Range(1, 1 << 2);  //NOLINT

// The Calls2 functions are benchmarking a function
// which on each call increments the value at the current
// position in a vector of size 1<<16 or 1<<18 and then
// increments the position-pointer
BENCHMARK(AbstractCalls2)->Range(1 << 16, 1 << 18);         //NOLINT
BENCHMARK(AbstractImplCalls2)->Range(1 << 16, 1 << 18);     //NOLINT
BENCHMARK(VariantCalls2)->Range(1 << 16, 1 << 18);          //NOLINT
BENCHMARK(VariantImplCalls2)->Range(1 << 16, 1 << 18);      //NOLINT
BENCHMARK(VariantSlowCalls2)->Range(1 << 16, 1 << 18);      //NOLINT
BENCHMARK(VariantSlowImplCalls2)->Range(1 << 16, 1 << 18);  //NOLINT

BENCHMARK_MAIN();
