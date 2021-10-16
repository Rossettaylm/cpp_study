#include "num_sequence.h"
#include <vector>

class Fibonacci : public num_sequence
{
public:
    Fibonacci(int len = 1, int begin_pos = 1)
        : _length(len), _begin_pos(begin_pos) {}
    ~Fibonacci() {}
    virtual int elem(int pos) const;
    virtual const char *what_am_i() const { return "Fibonacci"; }
    virtual ostream &print(ostream &os = cout) const;
    // length()和begin_pos()非基类提供的接口一员，无法通过其pointer和reference调用
    int length() const { return _length; }
    int begin_pos() const { return _begin_pos; }

protected:
    int _length;
    int _begin_pos;
    static vector<int> _elems_fibonacci;
    virtual void gen_elems(int pos) const;
};

// 对静态变量进行初始化
vector<int> Fibonacci::_elems_fibonacci;

// 虚函数在类外定义时不需要加virtual关键字
int Fibonacci::elem(int pos) const
{
    if (!check_integrity(pos, _elems_fibonacci.size()))
        return 0;
    return _elems_fibonacci[pos - 1];
}

void Fibonacci::gen_elems(int pos) const
{
    if (_elems_fibonacci.empty())
    {
        _elems_fibonacci.push_back(1);
        _elems_fibonacci.push_back(1);
    }
    if (_elems_fibonacci.size() < pos)
    {
        int i = _elems_fibonacci.size();
        int n2 = _elems_fibonacci[i - 2];
        int n1 = _elems_fibonacci[i - 1];
        for (; i <= pos; ++i)
        {
            int elem = n2 + n1;
            _elems_fibonacci.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
}

ostream &Fibonacci::print(ostream &os) const
{
    int elem_pos = _begin_pos - 1;
    int end_pos = elem_pos + _length;
    if (end_pos > _elems_fibonacci.size())
    {
        Fibonacci::gen_elems(end_pos);
    }
    while (elem_pos < end_pos)
    {
        os << _elems_fibonacci[elem_pos++] << ' ';
    }
    return os;
}
