#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include <string>

namespace Fibonacci {
  enum class FibStrat : uint32_t {
    RECURSIVE
  };

  auto fibStratStr(const FibStrat impl) -> std::string;

  auto fibonacci(const uint32_t n, const FibStrat strat) -> uint64_t;
}

#endif
