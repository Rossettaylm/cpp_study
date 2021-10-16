#include <iostream>
// #include "Fibonacci.h"
#include "Pell.h"
using namespace std;

int main()
{
    // Fibonacci fib;
    // cout << "Default fibonacci: ";
    // cout << fib << endl;

    // Fibonacci fib2(16);
    // cout << "A Fibonacci which length is 16: ";
    // cout << fib2 << endl;

    // Fibonacci fib3(8, 12);
    // cout << "A Fibonacci which length is 8, begin position is 12: ";
    // cout << fib3 << endl;

    Pell pel(10);
    cout << "A Pell sequence which length is 10, begin position is 1: ";
    cout << pel << endl;
}