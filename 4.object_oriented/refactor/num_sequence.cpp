//
// Created by DELL on 2021/10/17.
//

#include "num_sequence.h"

bool num_sequence::check_integrity(int pos, int size) const
{
    if (pos <= 0 || pos > _max_elem)
    {
        cerr << "Error! Invalid position: " << pos << endl;
        return false;
    }
    if (pos > size)
    {
        gen_elems(pos);
    }
}

int num_sequence::elem(int pos) const
{
    if (!check_integrity(pos, _relems.size()))
        return 0;
    return _relems[pos - 1];
}

ostream &num_sequence::print(ostream &os) const
{
    int elem_pos = _begin_pos - 1;
    int end_pos = elem_pos + _length;
    if (end_pos > _relems.size())
    {
        gen_elems(end_pos);
    }
    while (elem_pos != end_pos)
    {
        cout << _relems[elem_pos++] << ' ';
    }
}

ostream &operator<<(ostream &os, const num_sequence &ns);

ostream &operator<<(ostream &os, const num_sequence &ns) {
    return ns.print(os);
}
