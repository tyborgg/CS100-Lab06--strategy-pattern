#ifndef __POSMOCKPOW_HPP__
#define __POSMOCKPOW_HPP__

#include "base.hpp"

using namespace std;

class PosPowMock: public Base {
    public:
        PosPowMock() { }

        virtual double evaluate() { return 9;}
        virtual string stringify() { return "3 ** 2"; }
};
#endif

