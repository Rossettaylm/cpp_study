#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    string string1 = "ylm";
    string string2 = "rossetta";
    string str3;
    int len;

    // 复制
    str3 = string1;
    cout << "After duplicate: " << str3 << endl;

    // 拼接
    str3 = string1 + string2;
    cout << "After cat: " << str3 << endl;

    // 总长度
    len = str3.size();
    cout << "The length of str3: " << len << endl;
    cout << setiosflags(ios::left | ios::showpoint);
    cout << resetiosflags(ios::left);

    typedef long int *pint32;
    pint32 x;

    long int *x;

    return 0;
}
