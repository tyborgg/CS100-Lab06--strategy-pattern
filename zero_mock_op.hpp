#ifndef __ZEROMOCKOP_HPP__
#define __ZEROMOCKOP_HPP__

#include "base.hpp"

using namespace std;

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { };

        virtual double evaluate() { return 0; }
        virtual string stringify() { return "0"; }
};

#endif

