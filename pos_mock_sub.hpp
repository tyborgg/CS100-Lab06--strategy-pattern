#ifndef __POSMOCKSUB_HPP__
#define __POSMOCKSUB_HPP__

#include "base.hpp"

using namespace std;

class PosSubMock: public Base {
    public:
        PosSubMock() { }

        virtual double evaluate() { return 4;}
        virtual string stringify() { return "(5 - 1)"; }
};
#endif

