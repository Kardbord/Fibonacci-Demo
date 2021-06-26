#include "Fibonacci.hpp"

#include <stdexcept>
#include <unordered_map>
#include <sstream>

namespace {

  const std::unordered_map<Fibonacci::FibStrat, std::string> FibStratStrMap{
    {Fibonacci::FibStrat::RECURSIVE, "RECURSIVE"},
    {Fibonacci::FibStrat::DYNAMIC  , "DYNAMIC"}
  };

  auto recursiveFib(const uint32_t n) -> uint64_t {
    if (n < 2) return n;
    return recursiveFib(n - 1) + recursiveFib(n - 2);
  }

  auto dynamicFib(const uint32_t n) -> uint64_t {
    if (n < 2) return n;
    uint64_t fib1 = 0;
    uint64_t fib2 = 1;
    for (uint32_t i = 0; i < n - 1; ++i) {
      fib2 = fib2 + fib1;
      fib1 = fib2 - fib1;
    }
    return fib2;
  }

} // anonymous namespace

namespace Fibonacci {

  auto fibStratStr(const FibStrat impl) -> std::string {
    if (FibStratStrMap.count(impl) > 0) {
      return FibStratStrMap.at(impl);
    }
    return "UNKNOWN";
  }

  auto fibonacci(const uint32_t n, const FibStrat impl) -> uint64_t {
    switch (impl) {
      case FibStrat::RECURSIVE:
        return recursiveFib(n);
      case FibStrat::DYNAMIC:
        return dynamicFib(n);
      default:
        std::stringstream s;
        s << fibStratStr(impl) << " FibStrat: " << static_cast<uint32_t>(impl);
        throw std::invalid_argument(s.str());
    }
  }

} // namespace Fibonacci
