#include "iterator_class.h"
using namespace std;

class Box
{
    // 直接将Triangular_iterator类声明为friend，可访问其private成员
    friend class Triangular_iterator;
    // 声明Triangular_iterator类中的某个函数为friend
    friend bool Triangular_iterator::operator!=(const Triangular_iterator &) const;

private:
    double *_ptr;
    double _width;
    double _height;

public:
    static string name; // 所有类成员共用的静态变量

    typedef Triangular_iterator iterator;

    Box(double length = 1.0, double width = 1.0, double height = 1.0); // 普通构造函数 constructor
    Box(const Box &obj);                                               // 拷贝构造函数 copy_constructor
    ~Box();                                                            // 析构函数 destructor

    double getLength() const { return *_ptr; } // 直接在class内部定义函数，视为inline。const表示函数不改变class object的内容
    double getWidth() const { return _width; }
    double getHeight() const { return _height; }

    static void displayname() { cout << "The type of Box is " << name << endl; }
    static void printtype() { cout << "The box type is rossetta." << endl; } // 静态成员函数 -> python中的staticmethod

    void displayVolume() const;
    Box &copy(const Box &obj);
};

Box::Box(double length, double width, double height) : _ptr(new double), _width(width), _height(height) // 成员初始化列表
{
    *_ptr = length;
}

Box::Box(const Box &obj) : _ptr(new double), _width(obj._width), _height(obj._height)
{
    *_ptr = *obj._ptr; // 传值操作，有指针或者动态分配时必须用copy_constructor，防止不同对象共用指针
}

Box::~Box()
{
    delete _ptr;
}

void Box::displayVolume() const
{
    cout << "The volume of box: " << getLength() * getWidth() * getHeight() << endl;
}

Box &Box::copy(const Box &obj)
/* 传入一个实例对象，将其属性复制给自身 */
{
    // 检查两个对象是否相同
    if (this != &obj)
    {
        *_ptr = *obj._ptr;
        _width = obj._width;
        _height = obj._height;
    }
    return *this; // this指针指代整个对象，若要返回整个对象只需对其进行提领操作
}