// 成员函数指针

#include <vector>
#include <iostream>

using namespace std;

class num_sequence
{
public:
    // 将PtrType声明为一个指针，指向num_sequence的成员函数，后者的返回类型为void，输入参数列表为int
    typedef void (num_sequence::*PtrType)(int);

    // _pmf 可以指向以下任何一个函数
    void fibonacci(int);
    void pell(int);
    void lucas(int);
    void triangular(int);
    void sequare(int);
    void pentagonal(int);

private:
    PtrType _pmf;
    PtrType pm = &num_sequence::fibonacci; // 对函数取地址赋给函数指针PtrType
    vector<int> *_elems;                   // 指向目前所用的vector
    static const int num_seq = 7;
    static PtrType func_tbl[num_seq]; // 建立一个存放成员函数指针的静态数组
    static vector<vector<int>> seq;   //表示存放各个序列vector的总vector，后两个> >之间一定要有空格
};

int main()
{
}