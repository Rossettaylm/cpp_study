/* 对于每个子类通用的函数，都放到抽象基类中 */
#include <iostream>
#include <vector>
using namespace std;

class num_sequence
{
public:
    virtual ~num_sequence() {}
    virtual char *what_am_i() const = 0;
    static int max_elem() { return _max_elem; }
    int length() const { return _length; }
    int begin_pos() const { return _begin_pos; }
    int elem(int pos) const;
    ostream &print(ostream &os = cout) const;

protected:
    int _length, _begin_pos;
    static const int _max_elem = 64;
    vector<int> &_relems; // 定义一个reference指向派生类中存放数列的静态vector
    num_sequence(int length, int begin_pos, vector<int> &re)
        : _length(length), _begin_pos(begin_pos), _relems(re) {}
    virtual void gen_elems(int pos) const = 0;
    virtual bool check_integrity(int pos, int size) const;
};

bool num_sequence::check_integrity(int pos, int size) const
{
    if (pos <= 0 || pos > _max_elem)
    {
        cerr << "Error! Invalid position: " << pos << endl;
        return false;
    }
    if (pos > size)
    {
        gen_elems(pos);
    }
}

int num_sequence::elem(int pos) const
{
    if (!check_integrity(pos, _relems.size()))
        return 0;
    return _relems[pos - 1];
}

ostream &num_sequence::print(ostream &os = cout) const
{
    int elem_pos = _begin_pos - 1;
    int end_pos = elem_pos + _length;
    if (end_pos > _relems.size())
    {
        gen_elems(end_pos);
    }
    while (elem_pos != end_pos)
    {
        cout << _relems[elem_pos++] << ' ';
    }
}

ostream &operator<<(ostream &os, const num_sequence &ns)
{
    return ns.print(os);
}