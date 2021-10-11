#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    // 1.产生新的容器
    list<string> slist;

    // 2.产生特定大小的容器，以其默认值作为初值
    list<int> ilist(1024);
    vector<string> svec(32);

    // 3.产生特定大小的容器，并为每个元素指定初值
    vector<int> ivec(1024, -1);
    list<string> slist2(16, "unassigned");

    // 4.通过一对iterator产生容器
    int ia[8] = {1, 2, 3, 4, 5, 2, 55, 3};
    vector<int> ivec2(ia, ia + 8);

    // 5.复制某个容器到新容器
    list<string> slist3;
    list<string> slist4(slist3);

    /* vector只有back操作，list和deque提供front操作
    push_back(), push_front(), pop_front(), pop_back()
    back()和front()得到前后端的返回值 */

    return 0;
}
