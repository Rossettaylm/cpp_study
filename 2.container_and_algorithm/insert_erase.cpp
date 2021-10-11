#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template <typename elemtype>
void print(list<elemtype>);

int main(int argc, char const *argv[])
{
    int seq[] = {1, 2, 3, 4, 5};
    list<int> ilist(seq, seq + 5);
    // 打印初始列表
    print(ilist);

    // 找到3的iterator并在其之前插入3
    list<int>::iterator iter = find(ilist.begin(), ilist.end(), 3);
    ilist.insert(iter, 3);
    print(ilist);

    // 删除第一位之后的所有数
    ilist.erase(++ilist.begin(), ilist.end());
    print(ilist);

    return 0;
}

template <typename elemtype>
void print(list<elemtype> ilist)
{
    list<int>::iterator first = ilist.begin();
    list<int>::iterator last = ilist.end();
    while (first != last)
    {
        cout << *first << ' ';
        first++;
    }
    cout << endl;
}