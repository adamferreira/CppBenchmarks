#include <benchmark/benchmark.h>
#include <iostream>
#include <fstream>


// g++ mybenchmark.cpp -std=c++2a -isystem ${GOOGLE_BENCH_SRC}/include   -Lbenchmark/build/src lib/libbenchmark.a -lpthread -o mybenchmark
// --benchmark_format=<console|json|csv>
// --benchmark_out_format=<console|json|csv>
// --benchmark_out=<filename>
// ./mybenchmark --benchmark_counters_tabular=true --benchmark_format=csv --benchmark_out=bench.csv


void HelloWord1(std::ofstream& myfile) {
	myfile << "Hello World" << std::endl;
}

void HelloWord2(std::ofstream& myfile) {
	myfile << "Hello World\n";
}

void HelloWord3(std::ofstream& myfile) {
  myfile << "Hello World" << '\n';
}

void HelloWord4(std::ofstream& myfile) {
  myfile << "Hello World" << "\n";
}

void BM_HelloWord_1(benchmark::State& state) {
  // Perform setup here
  std::ofstream myfile("example1.txt", std::ios::out | std::ios::app | std::ios::binary);
  for (auto _ : state) {
    // This code gets timed
    HelloWord1(myfile);
  }
  myfile.close();
}

void BM_HelloWord_2(benchmark::State& state) {
  // Perform setup here
  std::ofstream myfile("example2.txt", std::ios::out | std::ios::app | std::ios::binary);
  for (auto _ : state) {
    // This code gets timed
    HelloWord2(myfile);
  }
  myfile.close();
}

void BM_HelloWord_3(benchmark::State& state) {
  // Perform setup here
  std::ofstream myfile("example3.txt", std::ios::out | std::ios::app | std::ios::binary);
  for (auto _ : state) {
    // This code gets timed
    HelloWord3(myfile);
  }
  myfile.close();
}

void BM_HelloWord_4(benchmark::State& state) {
  // Perform setup here
  std::ofstream myfile("example4.txt", std::ios::out | std::ios::app | std::ios::binary);
  for (auto _ : state) {
    // This code gets timed
    HelloWord4(myfile);
  }
  myfile.close();
}

// Register the function as a benchmark
BENCHMARK(BM_HelloWord_1);
BENCHMARK(BM_HelloWord_2);
BENCHMARK(BM_HelloWord_4);
BENCHMARK(BM_HelloWord_3);
// Run the benchmark
BENCHMARK_MAIN();
