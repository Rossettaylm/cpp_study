#include <iostream>
#include "Fibonacci.h"
using namespace std;

int main()
{
    Fibonacci fib(10, 1);
    cout << fib.what_am_i() << endl;
    cout << fib.length();
    cout << fib << endl;
    return 0;
}