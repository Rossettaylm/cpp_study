#include <iostream>
#include <vector>
using namespace std;

bool is_size_ok(int size);
const vector<int> *fibon_seq(int size);
bool fibon_elem(int pos, int &elem);
void printfib(int size);

int main()
{
    int pos, elem;
    cout << "please input a position: ";
    cin >> pos;
    printfib(pos);
    return 0;
}

bool is_size_ok(int size)
// 判定所求的位置的数是否超出了范围
{
    const int max_size = 1024;
    bool ret = true;
    if (size <= 0 || size > max_size)
    {
        ret = false;
    }
    return ret;
}

const vector<int> *fibon_seq(int size)
// 生成一个size大小的fibnacci序列并且返回它的指针
{
    static vector<int> elems;
    if (!is_size_ok(size))
    {
        return 0; //返回空指针
    }
    for (int i = elems.size(); i < size; i++)
    {
        if (i == 0 || i == 1)
        {
            elems.push_back(1);
        }
        else
            elems.push_back(elems[i - 1] + elems[i - 2]);
    }
    return &elems;
}

bool fibon_elem(int pos, int &elem)
//得到fibnacci序列上pos位置上的数赋给elem，如果超出范围，返回false
{
    const vector<int> *p_seq = fibon_seq(pos);
    if (!p_seq)
    {
        elem = 0;
        return false;
    }
    else
    {
        elem = (*p_seq)[pos - 1];
    }
    return true;
}

void printfib(int size)
{
    const vector<int> *p_seq = fibon_seq(size);
    cout << "序列前" << size << "个数为: ";
    for (int i = 0; i < size; i++)
    {
        cout << (*p_seq)[i] << ' ';
    }
}