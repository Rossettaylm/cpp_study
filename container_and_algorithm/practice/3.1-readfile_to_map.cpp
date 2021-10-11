#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    /* 1.定义input文件及其first和last指针，和words字典 */
    ifstream infile("input_file.txt");
    map<string, int> words;

    /* 2.定义word_exclusions的set */
    string sa[] = {"in", "an", "or", "and", "end", "the"};
    // set<string> words_exclusion(sa, sa + 6);
    set<string> words_exclusion;
    words_exclusion.insert(sa, sa + 6);
    // copy(sa, sa + 6, inserter(words_exclusion, words_exclusion.begin()));

    /* 3.将某单字放进字典时，先确定在不在排除字典里 */
    string word;
    while (infile >> word)
    {
        if (!words_exclusion.count(word))
        {
            words[word]++;
        }
    }

    /* 4.当文件读取完毕时，显示一份单字清单并显示单字的出现次数 */
    map<string, int>::iterator it = words.begin();
    for (; it != words.end(); it++)
    {
        cout << "key: " << it->first << '\t'
             << "value: " << it->second << endl;
    }

    return 0;
}
