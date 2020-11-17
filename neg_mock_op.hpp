#ifndef __NEGMOCKOP_HPP__
#define __NEGMOCKOP_HPP__

#include "base.hpp"

using namespace std;

class NegOpMock: public Base {
    public:
        NegOpMock() { };

        virtual double evaluate() { return -7; }
        virtual string stringify() { return "-7"; }
};

#endif
