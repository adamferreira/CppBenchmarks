cmake_minimum_required(VERSION 3.13)

project(CppBenchmarkFun)

# Look for google-benchmark git source directory
# Add add it here as 'benchmark' to build
# then target_link_libraries(target benchmark) should work
add_subdirectory(googletest)
add_subdirectory(benchmark)

include_directories(src/include)

macro(add_benchmark_exe Name)
    add_executable(${Name} src/${Name}.cpp)
    target_link_libraries(${Name} benchmark)
endmacro()

add_cxx_compiler_flag(-std=c++2a)
add_benchmark_exe(helloword)

add_executable(vector_basic src/stl_containers/vector_basic.cpp)
target_link_libraries(vector_basic benchmark)

add_executable(fill src/stl_algorithms/fill.cpp)
target_link_libraries(fill benchmark tbb)