/* 泛型算法需要包括algorithm头文件，即#include <algorithm>
所有搜索算法需要提供表示范围的iterator以及value
1. find()用于搜索无序集合中是否存在某值。iterator find(range_begin, range_end, value)
2. binary_search()用于有序集合的搜索，排序责任由程序员承担。bool binary_search(range_begin, range_end, value)
3. count()返回数值相符的元素数目。
4. search()比对某个容器内是否存在某个子序列，并返回子序列起始处，不存在则返回序列末尾。*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 3, 5};
    vector<int> vec(a, a + 5);
    vector<int>::iterator begin = vec.begin(), end = vec.end();
    vector<int>::iterator it1;

    // find()
    it1 = find(begin, end, 3);
    cout << *it1 << endl;

    // binary_search()
    if (binary_search(begin, end, 3))
        cout << "3 is in vec.\n";

    // count()
    int cnt = count(begin, end, 3);
    cout << cnt << endl;

    // search()
    vector<int> sub_vec(2, 3);
    vector<int>::iterator it2 = search(begin, end, sub_vec.begin(), sub_vec.end());
    cout << *it2 << ' ' << *(it2 + 1) << endl;

    return 0;
}
