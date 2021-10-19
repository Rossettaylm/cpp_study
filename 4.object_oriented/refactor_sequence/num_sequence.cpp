//
// Created by DELL on 2021/10/19.
//

#include "num_sequence.h"

int num_sequence::elem(int pos) const {
    if(!check_integrity(pos, _r_elems.size()))
        return 0;
    return _r_elems[pos-1];
}

std::ostream &num_sequence::print(std::ostream &os) const {
    int elem_pos = _begin_pos - 1;
    int end_pos = elem_pos + _length;
    if(check_integrity(end_pos, _r_elems.size()))
    for (; elem_pos < end_pos; ++elem_pos) {
        os << _r_elems[elem_pos] << ' ';
    }
    return os;
}

bool num_sequence::check_integrity(int pos, int size) const {
    if (pos <= 0 || pos > _max_size) {
        std::cerr << "Invalid position: " << pos << std::endl;
        return false;
    }
    if (pos > size)
        gen_elems(pos);
    return true;
}

inline int num_sequence::length() const {
    return _length;
}

inline int num_sequence::begin_pos() const {
    return _begin_pos;
}

inline int num_sequence::max_elem() const {
    return _max_size;
}

std::ostream &operator<<(std::ostream &os, const num_sequence &ns) {
    return ns.print();
}
