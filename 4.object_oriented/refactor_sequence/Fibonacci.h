//
// Created by DELL on 2021/10/19.
//

#ifndef SEQUENCE_FIBONACCI_H
#define SEQUENCE_FIBONACCI_H

#include "num_sequence.h"

class Fibonacci: public num_sequence{
public:
    // 传递_elems给基类，得到父类对子类的引用来初始化父类
    Fibonacci(int length, int begin_pos): num_sequence(length, begin_pos, _elems) {}
    virtual ~Fibonacci() {}
    virtual const char *who_am_i() const {return "Fibonacci";}

protected:
    static std::vector<int> _elems; // 类静态变量在类外定义，为类共有
    virtual void gen_elems(int pos) const override;

};



#endif //SEQUENCE_FIBONACCI_H
