using namespace std;
class num_sequence
{
    //    elem(pos): 返回pos位置上的元素
    //    gen_elems(pos): 产生直到pos位置的所有元素
    //    what_am_i(): 返回确切的数列类型
    //    print(os): 将所有元素写入os
    //    check_integrity(pos): 检查pos是否为有效位置
    //    max_elems(): 返回所支持的最大位置值
public:
    virtual ~num_sequence() {}

    virtual int elem(int pos) const = 0; // 函数对于抽象基类无意义，定义为纯虚函数，留待派生类完善定义
    virtual const char *what_am_i() const = 0;
    static int max_elems() { return _max_elems; }
    virtual ostream &print(ostream &os = cout) const = 0;

protected:
    virtual void gen_elems(int pos) const = 0;
    virtual bool check_integrity(int pos, int size) const;
    const static int _max_elems = 1024;
};

bool num_sequence::check_integrity(int pos, int size) const
{
    if (pos <= 0 || pos > _max_elems)
    {
        cerr << "!! invalid position: " << pos
             << " Cannot honor request!\n";
        return false;
    }
    if (pos > size)
    {
        // gen_elems()通过虚拟机制调用
        gen_elems(pos);
    }

    return true;
}

ostream &operator<<(ostream &os, const num_sequence &ns)
{
    return ns.print(os);
}