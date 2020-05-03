#include <benchmark/benchmark.h>

#include <vector>
#include <set>
#include <cmath> // pow


#include "utils.hpp"
#include "stl_algorithms.hpp"


template<class Container, ExecutionPolicy policy>
void fill(benchmark::State& state) {
  // Perform setup here
  while (state.KeepRunning()) {
  	state.PauseTiming();
    Container v;
    v.reserve(state.range(0));
    // This code gets timed
    state.ResumeTiming();
    generate_random<Container, policy>(v, state.range(0));
  }
}

template<class Container, ExecutionPolicy policy>
void sort(benchmark::State& state) {
  // Perform setup here
  while (state.KeepRunning()) {
  	state.PauseTiming();
    Container v(state.range(0));
    generate_random<Container>(v, state.range(0));
    // This code gets timed
    state.ResumeTiming();
    sort_container<Container, policy>(v);
  }
}



BENCHMARK_TEMPLATE2(sort, std::vector<int>, seq)
	->Unit(benchmark::kMillisecond)
	->RangeMultiplier(2)
	->Range(pow(2,1),pow(2,10))
	;

BENCHMARK_TEMPLATE2(sort, std::vector<int>, par)
	->Unit(benchmark::kMillisecond)
	->RangeMultiplier(2)
	->Range(pow(2,1),pow(2,10))
	;

BENCHMARK_TEMPLATE2(sort, std::vector<int>, unseq)
	->Unit(benchmark::kMillisecond)
	->RangeMultiplier(2)
	->Range(pow(2,1),pow(2,10))
	;

BENCHMARK_TEMPLATE2(sort, std::vector<int>, par_unseq)
	->Unit(benchmark::kMillisecond)
	->RangeMultiplier(2)
	->Range(pow(2,1),pow(2,10))
	;

// Run the benchmark
BENCHMARK_MAIN();
