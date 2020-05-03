 #pragma once

#include <vector>
#include <iostream>
#include <execution> // requires link with tbb

#include "utils.hpp"

template<typename Type>
struct RndIntGen
{
  RndIntGen(Type l, Type h): low(l), high(h) { }
  Type operator()() const {
    return low + (std::rand() % ((high - low) + 1));
  }
private:
  Type low;
  Type high;
};

// Enum to represent execution policies
// As values and not type
enum ExecutionPolicy {seq, par, par_unseq, unseq};

// Execute a lambda function with the appropriate policy
template<class LambdaFunction>
inline auto launch_lambda_with_policy(LambdaFunction f, ExecutionPolicy p) {
  switch(p) {
  	case seq: 		return f(std::execution::seq);
  	case par: 		return f(std::execution::par);
  	case par_unseq: return f(std::execution::par_unseq);
  	case unseq: 	return f(std::execution::unseq);
  	default: 		return f(std::execution::seq);
  }
}


template<class Container, ExecutionPolicy policy = ExecutionPolicy::par>
void generate_random(Container& container, std::size_t rng) {
	launch_lambda_with_policy(
		[&](auto &std_policy) { return std::generate(std_policy, std::begin(container), std::end(container), RndIntGen<std::size_t>(0, rng)); }
		, policy
	);
}

template<class Container, ExecutionPolicy policy = ExecutionPolicy::par>
void sort_container(Container& container) {
	launch_lambda_with_policy(
		[&](auto &std_policy) { return std::sort(std_policy, std::begin(container), std::end(container)); }
		, policy
	);
}