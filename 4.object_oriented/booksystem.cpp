#include <iostream>
using namespace std;

class LibMat
{
private:
    /* data */
public:
    LibMat() { cout << "LibMat::LibMat() default constructor!\n"; }
    virtual ~LibMat() { cout << "LibMat::~LibMat() destructor!\n"; }
    virtual void print() const { cout << "LibMat::print() -- I am a LibMat object!\n"; }
};

void print(const LibMat &mat)
{
    cout << "in global print(): about to print mat.print()\n";
    // 下一行依据mat实际指向的对象
    // 解析该执行哪一个print() member function
    mat.print();
}

int main()
{
    LibMat(libmat);
    print(libmat); // LibMat::LibMat() --> print() --> LibMat::print() --> LibMat::~LibMat()
}