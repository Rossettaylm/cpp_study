#include <iostream>
using namespace std;

int *getArray();

int main(){
    int *p;
    p = getArray();
    for (int i = 0; i < 10; ++i) {
        cout << *(p + i) << endl;
    }

    return 0;
}

// 利用指针返回一个数组
int *getArray(){
    static int r[10];
    for (int i = 0; i < 10; ++i) {
        r[i] = i;
    }
    return r;
}


