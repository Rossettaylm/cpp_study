#include <iostream>
#include <vector>
#include "num_sequence.h"
using namespace std;

#ifndef REFACTOR_FIBONACCI_H
#define REFACTOR_FIBONACCI_H

class Fibonacci : public num_sequence, public error_code {
public:
    Fibonacci(int len = 1, int beg_pos = 1) : num_sequence(len, beg_pos, _elems) {}
    virtual ~Fibonacci() {}
    virtual const char *what_am_i() const { return "Fibonacci"; }

protected:
    virtual void gen_elems(int pos) const;
    static vector<int> _elems;
};

#endif

