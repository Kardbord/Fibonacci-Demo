#include "Fibonacci.hpp"
#include "ArgParser.hpp"

#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace Fibonacci;

auto printFibonacci(const uint32_t n, const FibStrat strat) -> void {
  using std::chrono::duration_cast;
  using std::chrono::steady_clock;
  using std::chrono::milliseconds;

  auto start = steady_clock::now();
  auto ans = Fibonacci::fibonacci(n, strat);
  auto end = steady_clock::now();
  auto diff_ms = duration_cast<milliseconds>(end - start).count();
  std::cout << "Used the " << fibStratStr(strat) 
    << " strategy to calculate fibonacci(" << n << ")=" 
    << ans << " in " << diff_ms << "ms\n";
}

// TODO: add a usage
int main(int argc, char *argv[]) {
  const auto p_args = ArgParser::BuildArgParser(argc, argv);
  if (p_args == nullptr) {
    std::cerr << "Error constructing ArgParser\n";
    return EXIT_FAILURE;
  }
  const uint32_t n = p_args->getArgAsUint32(1);

  // TODO: Allow user to choose algorithm via cmd line args
  FibStrat fibstrat = FibStrat::DYNAMIC;
  printFibonacci(n, fibstrat);

  fibstrat = FibStrat::RECURSIVE;
  printFibonacci(n, fibstrat);

  return EXIT_SUCCESS;
}
