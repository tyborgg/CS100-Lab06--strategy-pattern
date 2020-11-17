#ifndef __ZEROMOCKPOW_HPP__
#define __ZEROMOCKPOW_HPP__

#include "base.hpp"

using namespace std;

class ZeroPowMock: public Base {
    public:
        ZeroPowMock() { }

        virtual double evaluate() { return 0;}
        virtual string stringify() { return "0 ** 2"; }
};
#endif

