#include <iostream>
#include <vector>
#include "num_sequence.h"
using namespace std;

class Fibonacci : public num_sequence
{
public:
    Fibonacci(int len = 1, int beg_pos = 1) : num_sequence(len, beg_pos, _elems) {}
    ~Fibonacci() {}
    virtual char *what_am_i() const { return "Fibonacci"; }

protected:
    virtual void gen_elems(int pos) const;
    static vector<int> _elems;
};

void Fibonacci::gen_elems(int pos) const
{
    if (_elems.empty())
    {
        _elems.push_back(1);
        _elems.push_back(1);
    }
    if (_elems.size() < pos)
    {
        int i = _elems.size();
        int n2 = _elems[i - 2];
        int n1 = _elems[i - 1];
        for (; i <= pos; i++)
        {
            int elem = n2 + n1;
            _elems.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
}

vector<int> Fibonacci::_elems;
