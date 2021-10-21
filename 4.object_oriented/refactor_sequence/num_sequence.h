//
// Created by DELL on 2021/10/19.
//

#ifndef SEQUENCE_NUM_SEQUENCE_H
#define SEQUENCE_NUM_SEQUENCE_H

#include <iostream>
#include <vector>

class num_sequence {
// elem(int pos) 输入位置获得序列的元素
// check_integrity(int pos, int size) 检查位置是否在合法范围内，并且检查序列的大小
// print() 打印当前数列并输出到ostream
// gen_elems(int pos) 产生直到pos位置的数列
// who_am_i() 返回一个字符串代表序列名字
public:
    virtual ~num_sequence() {}
    virtual const char *who_am_i() const = 0;
    int elem(int pos) const;
    int length() const { return _length; }
    int begin_pos() const { return _begin_pos; }
    static int max_elem() { return _max_size; }     // 类静态方法只能访问类静态成员，但是可以被类和对象调用
    std::ostream &print(std::ostream &os = std::cout) const;

protected:
    int _length, _begin_pos;
    std::vector<int> &_r_elems; // 定义一个对派生类序列vector的引用
    static const int _max_size = 100;

    // 实例对象不能直接访问的放到protected
    num_sequence(int length, int begin_pos, std::vector<int> &r_elems)
            : _length(length), _begin_pos(begin_pos), _r_elems(r_elems) {}
    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos, int size) const;

};

std::ostream &operator<<(std::ostream &os, const num_sequence &ns);


#endif //SEQUENCE_NUM_SEQUENCE_H
