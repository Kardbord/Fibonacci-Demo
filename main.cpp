#include "Fibonacci.hpp"
#include "ArgParser.hpp"

#include <iostream>
#include <cstdlib>
#include <sstream>

int main(int argc, char *argv[]) {
  auto p_args = ArgParser::BuildArgParser(argc, argv);
  if (p_args == nullptr) {
    std::cerr << "Error constructing ArgParser\n";
    return EXIT_FAILURE;
  }

  std::cout << p_args->getProgramName() << "\n";
  return EXIT_SUCCESS;
}
