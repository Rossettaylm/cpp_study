/* 类似vector<int>::iterator it的操作，为了定义类的迭代器，需要定义!=, *, ++ 运算符
运算符函数不用指定名称，而是在运算符前加上operator关键字 */

class Triangular_iterator
{
private:
    int _index;

public:
    Triangular_iterator(int index) { _index = index - 1; }
    ~Triangular_iterator() {}

    bool operator==(const Triangular_iterator &) const;
    bool operator!=(const Triangular_iterator &) const;
};

inline bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const
{
    return _index == rhs._index;
}

inline bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const
{
    return !(*this == rhs);
}