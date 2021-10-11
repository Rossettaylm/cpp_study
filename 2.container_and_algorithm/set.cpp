/* set由一群key组合形成，如果我们想知道某值是否存在于某个集合内，就可以使用set
set是集合，每个元素只能存在一次，且按照less-than顺序，即从小到大排列 */

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    map<string, int> words;
    set<string> word_exclusion;
    string tword;

    /* 输入一个字符串，若不在word_exclusion中，就加入到words内 */
    // while (cin >> tword)
    // {
    //     if (word_exclusion.count(tword))
    //     {
    //         // 如果tword涵盖于“排除子集word_exclusion”内，跳过此次迭代剩余部分
    //         continue;
    //     }
    //     words[tword]++;
    // }

    /* set的初始化 */
    int ia[10] = {1, 3, 5, 8, 5, 3, 1, 5, 8, 1};
    set<int> iset(ia, ia + 10);

    /* set的插入 */
    int val = 10;
    iset.insert(val); // 传一个值
    int ib[5] = {2, 4, 6, 8, 10};
    iset.insert(ib, ib + 5); // 传入指针范围

    /* set的遍历 */
    set<int>::iterator ps = iset.begin();
    for (; ps != iset.end(); ++ps)
    {
        cout << *ps << ' ';
    }

    return 0;
}
