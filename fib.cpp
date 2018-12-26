#include <iostream>
#include <cstdlib>
#include <exception>
#include <string>

using _uint_ = uint64_t;

const _uint_ fibTo40 [] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
                            1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025,
                            121393, 196418, 317811, 514229, 832040, 1346269,
                            2178309, 3524578, 5702887, 9227465, 14930352, 24157817,
                            39088169, 63245986, 102334155
                          };

// Validates command line input.
// Checks that at least one argument is provided,
// and that it successfully converts into an integer.
// If the conversion is successful, the integer value
// will be stored in $n.
//
// Arguments:
//  argc  : Number of command line arguments provided.
//  argv  : Array of command line arguments.
//  n     : A reference to an integer;
//          $argv[1] will be converted to an
//          integer and stored here.
// return : true if $argv[1] exists and successfully converts to an integer,
//          false otherwise
bool validInput(int const & argc, char ** const argv, int & n) {
    if (argc < 2) {
        return false;
    }
    try {
        n = std::stoi(argv[1]);
    } catch (std::exception e) {
        return false;
    }
    if (n < 0) return false;
    return true;
}

// Computes the $n'th fibonacci number.
// O(n) time complexity.
// O(1) space complexity.
//
// Arguments:
//  n      : the n'th fibonacci number to be computed.
//  return : the $n'th fibonacci number.
_uint_ fib(int const & n) {
    _uint_ seq [] = {0, 1};

    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0) {
            seq[0] = seq[0] + seq[1];
        } else {
            seq[1] = seq[0] + seq[1];
        }
    }

    return (n % 2 == 0) ? seq[0] : seq[1];
}

// Computes a number in the fibonacci sequence
//
// Command Line Arguments:
//     $1 (required) : The n'th fibonacci number to be computed.
//                     Numbers greater than or equal to 0 are valid.
//     $2 (optional) : Will be ignored.
//     .
//     .
//
int main(int argc, char ** argv) {
    int n;
    if (!validInput(argc, argv, n)) {
        std::cout << "Please provide a valid command line argument.\n"
                  << "Valid arguments numbers greater than or equal to 0.\n";
        return EXIT_FAILURE;
    }

    _uint_ fibn = fib(n);
    std::cout << "fib(" << n << ") = " << fibn << "\n";

    std::cout << "Computation is correct : ";

    if (n > 40) std::cout << "unknown\n";
    else {
        if (fibTo40[n] == fibn) std::cout << "true\n";
        else std::cout << "false\n";
    }

    return EXIT_SUCCESS;
}

