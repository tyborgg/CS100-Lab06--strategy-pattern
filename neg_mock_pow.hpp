#ifndef __NEGMOCKPOW_HPP__
#define __NEGMOCKPOW_HPP__

#include "base.hpp"

using namespace std;

class NegPowMock: public Base {
    public:
        NegPowMock() { }

        virtual double evaluate() { return 9;}
        virtual string stringify() { return "-3 ** 2"; }
};
#endif

