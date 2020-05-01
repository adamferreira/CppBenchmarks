cmake_minimum_required(VERSION 3.13)

project(CppBenchmarkFun)

# Look for google-benchmark git source directory
# Add add it here as 'benchmark' to build
# then target_link_libraries(target benchmark) should work
add_subdirectory(googletest)
add_subdirectory(benchmark)

macro(add_benchmark_exe Name)
    add_executable(${Name} src/${Name}.cpp)
    target_link_libraries(${Name} benchmark)
endmacro()


add_benchmark_exe(helloword)