/* 泛用的filter函数实现 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> //function object -- less<int>()
#include <iterator>   //insertion adapter
using namespace std;

template <typename inputIterator, typename outputIterator, typename elemType, typename comp>
outputIterator filter(inputIterator first, inputIterator last, outputIterator at, const elemType &val, comp pred);
template <typename elemIterator>
void print(elemIterator begin, elemIterator end);

int main(int argc, char const *argv[])
{
    const int elem_size = 8;
    // 原始的待过滤的vector
    int origin_ia[elem_size] = {3, 5, 20, 6, 10, 50, 34, 2};
    vector<int> origin_ivec(origin_ia, origin_ia + elem_size);

    // 存放过滤后的vector
    int output_ia[elem_size];
    vector<int> output_ivec(elem_size);
    vector<int> output_ivec_insert; // 定义一个空的vector，调用insertion adapter

    // 打印初始vector
    cout << "The origin_ia and origin_ivec: ";
    print(origin_ia, origin_ia + elem_size);
    cout << '\n';

    cout << "After filter, the output_ia: ";
    int *p_output_ia_end = filter(origin_ia, origin_ia + elem_size, output_ia, 10, less<int>());
    print(output_ia, p_output_ia_end);
    cout << '\n';

    cout << "After filter, the output_ivec: ";
    vector<int>::iterator iter_outputIvec_end =
        filter(origin_ivec.begin(), origin_ivec.end(), output_ivec.begin(), 10, greater_equal<int>());
    print(output_ivec.begin(), iter_outputIvec_end);
    cout << '\n';

    cout << "After filter, the output_ivec_insert: ";
    filter(origin_ivec.begin(), origin_ivec.end(), back_inserter(output_ivec_insert), 10, greater_equal<int>());
    // back_inserter()是一种insertion adapter，采用插入运算代替赋值运算，不用预先定义容器的大小
    print(output_ivec_insert.begin(), output_ivec_insert.end());

    return 0;
}

template <typename inputIterator, typename outputIterator, typename elemType, typename comp>
outputIterator filter(inputIterator first, inputIterator last, outputIterator at, const elemType &val, comp pred)
{
    while ((first = find_if(first, last, bind2nd(pred, val))) != last)
    // bind2nd是一个bind adapter，将val绑定到pred的第二个参数中
    {
        // cout << "Found elem: " << *first << endl;
        *(at++) = *(first++); // 赋值操作
    }
    return at; // 返回输出数组的尾地址
}

template <typename elemIterator>
void print(elemIterator begin, elemIterator end)
{
    while (begin != end)
    {
        cout << *begin << ' ';
        ++begin;
    }
    cout << endl;
}