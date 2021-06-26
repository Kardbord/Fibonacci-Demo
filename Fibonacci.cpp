#include "Fibonacci.hpp"

#include <stdexcept>
#include <unordered_map>
#include <sstream>

namespace {

  const std::unordered_map<Fibonacci::FibStrat, std::string> FibStratStrMap{
    {Fibonacci::FibStrat::RECURSIVE, "RECURSIVE"}
  };

  auto recursiveFib(const uint32_t n) -> uint64_t {
    if (n < 2) return n;
    return recursiveFib(n - 1) + recursiveFib(n - 2);
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
        break;
      default:
        std::stringstream s;
        s << fibStratStr(impl) << ": " << static_cast<uint32_t>(impl);
        throw std::invalid_argument(s.str());
    }
  }

} // namespace Fibonacci
