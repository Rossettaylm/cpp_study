//
// Created by DELL on 2021/10/19.
//

#include "Pell.h"

std::vector<int> Pell::_elems;

void Pell::gen_elems(int pos) const {
    if (_elems.empty())
    {
        _elems.push_back(1); _elems.push_back(2);
    }
    if (pos > _elems.size())
    {
        int i = _elems.size();
        int n2 = _elems[i - 2];
        int n1 = _elems[i - 1];
        for(; i < pos; ++i)
        {
            int elem = n2 + 2*n1;
            _elems.push_back(elem);
            n2 = n1; n1 = elem;
        }
    }
}