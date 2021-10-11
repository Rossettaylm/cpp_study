#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    map<string, int> words; // 定义一个map容器，key为string类型且value为int类型，代表每个key出现的次数
    //// 统计程序
    string tword;
    while (cin >> tword)
    {
        words[tword]++;
    }

    //// 遍历words中的key和value
    map<string, int>::iterator it = words.begin();
    for (; it != words.end(); it++)
    {
        cout << "key: " << it->first
             << "value: " << it->second << endl;
    }

    //// map查询法
    // 1. 直接通过key访问
    int count = 0;
    if (!(count = words["vermeer"]))
    {
        //缺点：当vermeer不存在于words内时，这个key会被加入words中，并设value为int类型的默认值0
    }
    // 2. 利用map中的find函数
    map<string, int>::iterator it;
    it = words.find("vermeer");
    if (it != words.end())
    {
        count = it->second;
    }
    // 3. 利用map的count函数
    string search_word("vermeer");
    if (words.count(search_word))
    {
        count = words[search_word];
    }

    return 0;
}
