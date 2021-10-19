//
// Created by DELL on 2021/10/19.
//

#ifndef SEQUENCE_PELL_H
#define SEQUENCE_PELL_H

#include "num_sequence.h"

class Pell: public num_sequence{
public:
    Pell(int length, int begin_pos): num_sequence(length, begin_pos, _elems) {}
    virtual ~Pell() {}
    virtual const char *who_am_i() const {return "Pell";}

protected:
    static std::vector<int> _elems;
    virtual void gen_elems(int pos) const override;
};


#endif //SEQUENCE_PELL_H
