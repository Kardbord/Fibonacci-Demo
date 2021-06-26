#include "Fibonacci.hpp"
#include "ArgParser.hpp"

#include <iostream>
#include <cstdlib>

using namespace Fibonacci;

auto printStrat(const FibStrat strat, const uint32_t n) -> void {
  std::cout << "Using the " << fibStratStr(strat)
    << " strategy to calculate fibonacci(" << n << ")\n";
}

int main(int argc, char *argv[]) {
  const auto p_args = ArgParser::BuildArgParser(argc, argv);
  if (p_args == nullptr) {
    std::cerr << "Error constructing ArgParser\n";
    return EXIT_FAILURE;
  }
  std::cout << "Launching " << p_args->getProgramName() << "!\n";

  const uint32_t n = p_args->getArgAsUint32(1);

  FibStrat fibstrat = FibStrat::RECURSIVE;
  printStrat(fibstrat, n);;
  std::cout << "fibonacci(" << n << ")=" << Fibonacci::fibonacci(n, fibstrat) << "\n";
  

  return EXIT_SUCCESS;
}
