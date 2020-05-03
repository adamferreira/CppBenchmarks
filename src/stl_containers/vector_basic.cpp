#include <benchmark/benchmark.h>

#include <vector>
#include <iostream>
#include <cmath>

template<typename type>
class VertorBenchTool : public benchmark::Fixture {
public:
	std::vector<type> _vector;
	int cpt;

	VertorBenchTool(): _vector() {}

  void SetUp(const ::benchmark::State& state) {}
  void TearDown(const ::benchmark::State& state) {}
};


BENCHMARK_TEMPLATE_F(VertorBenchTool, IntTest, int)(benchmark::State& st) {
  for (auto _ : st) {
  	_vector.clear();
  	_vector.push_back(5);
  }
}


void push_back(benchmark::State& state) {
  // Perform setup here
  while (state.KeepRunning()) {
  	state.PauseTiming();
    std::vector<int> v;
    // This code gets timed
    state.ResumeTiming();

    for(auto i(0); i < state.range(0); ++i){
    	v.push_back(static_cast<int>(i));
    }
  }
}

void push_back_size(benchmark::State& state) {
  // Perform setup here
  while (state.KeepRunning()) {
  	state.PauseTiming();
    std::vector<int> v(state.range(0));
    // This code gets timed
    state.ResumeTiming();

    for(auto i(0); i < state.range(0); ++i){
    	v.push_back(static_cast<int>(i));
    }
  }
}

void push_back_reserve(benchmark::State& state) {
  // Perform setup here
  while (state.KeepRunning()) {
  	state.PauseTiming();
    std::vector<int> v;
    v.reserve(state.range(0));
    // This code gets timed
    state.ResumeTiming();

    for(auto i(0); i < state.range(0); ++i){
    	v.push_back(static_cast<int>(i));
    }
  }
}

void push_back_reserve_2(benchmark::State& state) {
  // Perform setup here
  while (state.KeepRunning()) {
  	state.PauseTiming();
    std::vector<int> v;
    v.reserve(state.range(0));
    // This code gets timed
    state.ResumeTiming();

    for(auto i(0); i < state.range(0); ++i){
    	v[std::min(static_cast<size_t>(0),v.size()-1)] = static_cast<int>(i);
    }
  }
}

void insert(benchmark::State& state) {
  // Perform setup here
  while (state.KeepRunning()) {
  	state.PauseTiming();
    std::vector<int> v;
    v.reserve(state.range(0));
    // This code gets timed
    state.ResumeTiming();

    for(auto i(0); i < state.range(0); ++i){
    	v.insert(std::end(v), static_cast<int>(i));
    }
  }
}


BENCHMARK(push_back)->RangeMultiplier(2)->Range(pow(2,10),pow(2,20));
BENCHMARK(push_back_size)->RangeMultiplier(2)->Range(pow(2,10),pow(2,20));
BENCHMARK(push_back_reserve)->RangeMultiplier(2)->Range(pow(2,10),pow(2,20));
BENCHMARK(push_back_reserve_2)->RangeMultiplier(2)->Range(pow(2,10),pow(2,20));
BENCHMARK(insert)->RangeMultiplier(2)->Range(pow(2,10),pow(2,20));


// Run the benchmark
BENCHMARK_MAIN();
