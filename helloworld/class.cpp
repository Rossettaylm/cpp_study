#include <iostream>
using namespace std;

class Box
{
public:
    double length, breadth, height;
    double get(void);
    void set(double len, double bre, double hei);
};

double Box::get(void)
{
    cout << "The length of box: " << length << endl;
    cout << "The breadth of box: " << breadth << endl;
    cout << "The height of box: " << height << endl;
    return length * breadth * height;
}

void Box::set(double len, double bre, double hei)
{
    length = len;
    height = hei;
    breadth = bre;
}

int main(int argc, char const *argv[])
{
    Box box;
    double volume = 0.0;
    box.length = 3.0;
    box.breadth = 4.0;
    box.height = 5.0;
    volume = box.get();

    cout << "The volume of box: " << volume << endl;
    return 0;
}
