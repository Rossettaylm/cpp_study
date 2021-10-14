#include <iostream>
#include "Fibonacci.h"
using namespace std;

int main()
{
    Fibonacci fib;
    cout << fib << endl;
    Fibonacci fib2(16);
    cout << fib2 << endl;
    Fibonacci fib3(8, 12);
    cout << fib3 << endl;
}