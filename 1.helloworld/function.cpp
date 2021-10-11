#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;
// overload + function template 即函数重载 + 模板函数
// 当需要进行函数重载时，可以采用模板函数预留输入的数据类型
template <typename elemType>
void display_message(const string &, const vector<elemType> &);

/* 不同容器之间如vector和list，可以overload模板函数 */
// template <typename elemType>
// void display_message(const string &, const vector<elemType> &);
// template <typename elemType>
// void display_message(const string &, const list<elemType> &);

int main()
{
    const string msg = "Requested message is not supported";

    int vec_int_array[] = {1, 2, 3, 4, 5};
    double vec_double_array[] = {2.3, 3.2, 4.4, 1.1, 5.0};
    string vec_string_array[] = {"daraole", "jiuzhe", "azhe", "dongle", "keyi"};
    vector<int> vec_int(vec_int_array, vec_int_array + 5);
    vector<double> vec_double(vec_double_array, vec_double_array + 5);
    vector<string> vec_string(vec_string_array, vec_string_array + 5);

    display_message(msg, vec_int);
    display_message(msg, vec_double);
    display_message(msg, vec_string);

    return 0;
}

/* typename定义了一个占位符elemType表示类型, elemType也可以是其他如elem, t...
当传入类型不同时，自动按照其不同的类型生成一个函数实例 */

template <typename elemType>
void display_message(const string &msg, const vector<elemType> &vec)
{
    cout << msg << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
}