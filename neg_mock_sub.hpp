#ifndef __NEGMOCKSUB_HPP__
#define __NEGMOCKSUB_HPP__

#include "base.hpp"

using namespace std;

class NegSubMock: public Base {
    public:
        NegSubMock() { }

        virtual double evaluate() { return -4;}
        virtual string stringify() { return "(1 - 5)"; }
};
#endif

