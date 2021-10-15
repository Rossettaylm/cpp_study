#include <iostream>
#include <string>
#include "class.h"

string Box::name = "magic"; // 类中静态变量的初始化

int main()
{
    Box box1(3.0, 4.0, 5.0);
    // Box box2(box1); // 运用copy_constructor初始化box2
    Box box2;
    box2.copy(box1); // 运用copy函数初始化box2

    double length = box2.getLength();
    cout << showpoint << "The length of box2: " << length << endl;

    box1.displayVolume();
    box2.displayVolume();

    Box::printtype();
    Box::displayname();

    return 0;
}
