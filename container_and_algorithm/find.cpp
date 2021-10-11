#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};

    vector<int> ivec(ia, ia + asize);
    list<int> ilist(ia, ia + asize);

    // 传入指针寻找
    int *pia = find(ia, ia + asize, 8);
    if (pia != ia + asize)
    {
        /* 找到了元素value */
    }

    // 传入iterator寻找
    vector<int>::iterator iter_v = find(ivec.begin(), ivec.end(), 1024);
    if (iter_v != ivec.end())
    {
        /* 找到了元素value */
    }

    list<int>::iterator iter_l = find(ilist.begin(), ilist.end(), 1024);
    if (iter_l != ilist.end())
    {
        /* 找到了元素value */
    }

    return 0;
}
