#include <iostream>
#include "Fibonacci.h"
#include "Pell.h"

int main() {
    Fibonacci fib(10, 1);
    std::cout << fib.who_am_i()
              << ": length="
              << fib.length()
              << ", begin position="
              << fib.begin_pos() << std::endl;
    std::cout << fib << std::endl;

    Pell pell(6, 4);
    std::cout << pell.who_am_i()
              << ": length="
              << pell.length()
              << ", begin position="
              << pell.begin_pos() << std::endl;
    std::cout << pell << std::endl;
    return 0;
}
