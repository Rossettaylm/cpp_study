#include <iostream>
#include "Fibonacci.h"
#include "Pell.h"

int main() {
    Fibonacci fib(10, 1);
    std::cout << fib << std::endl;
    Pell pell(6, 4);
    std::cout << pell << std::endl;
    return 0;
}
