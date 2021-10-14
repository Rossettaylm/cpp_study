#include <iostream>
using namespace std;

class LibMat
{
private:
    /* data */
public:
    LibMat() { cout << "LibMat::LibMat() default constructor!\n"; }
    // 基类的析构函数一般需要用虚函数，在程序结束时动态调用子类的析构函数，防止内存泄漏
    virtual ~LibMat() { cout << "LibMat::~LibMat() destructor!\n"; }
    virtual void print() const { cout << "LibMat::print() -- I am a LibMat object!\n"; }
};

class Book : public LibMat //定义一个LibMat抽象基类的继承类，使用public继承
{
protected:
    string _title, _author;

public:
    Book(const string &title, const string &author) : _title(title), _author(author)
    {
        cout << "Book:Book( " << _title
             << ", " << _author << " ) constructor\n";
    }
    virtual ~Book()
    {
        cout << "Book:~Book() destructor!\n";
    }
    virtual void print() const
    {
        cout << "Book::print() -- I am a Book object!\n"
             << "My title is: " << _title << '\n'
             << "My author is: " << _author << endl;
    }
    const string &title() const { return _title; }
    const string &author() const { return _author; }
};

class AudioBook : public Book
{
protected:
    string _narrator;

public:
    // Book定义的各项数据和函数都可以被直接调用
    AudioBook(const string &title, const string &author, const string &narrator)
        : Book(title, author), _narrator(narrator)
    {
        cout << "AudioBook::AudioBook( " << _title
             << ", " << _author
             << ", " << _narrator
             << " ) constructor\n";
    }
    ~AudioBook()
    {
        cout << "AudioBook::~AudioBook destructor!\n";
    }
    void print() const
    {
        cout << "AudioBook::print() -- I am an AudioBook object!\n"
             //_title和_author都直接访问继承来的
             << "My title is: " << _title << '\n'
             << "My author is: " << _author << '\n'
             << "My narrator is:" << _narrator << endl;
    }
    const string &narrator() const { return _narrator; }
};

void print(const LibMat &mat)
{
    cout << "in global print(): about to print mat.print()\n";
    // 形参为抽象基类，可以传入其子类
    // 下一行依据mat实际指向的对象
    // 解析该执行哪一个print() member function
    mat.print();
}
int main()
{
    // LibMat libmat;
    // print(libmat); // LibMat::LibMat() --> print() --> LibMat::print() --> LibMat::~LibMat()
    // Book book1("c++ primer", "stanley");
    // print(book1);
    AudioBook book("c++ primer", "stanley lippman", "Rossetta");
    print(book);
}