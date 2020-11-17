#ifndef __SEVENMOCKOP_HPP__
#define __SEVENMOCKOP_HPP__

#include "base.hpp"

using namespace std;

class SevenOpMock: public Base {
    public:
        SevenOpMock() { }

        virtual double evaluate() { return 7;}
        virtual string stringify() { return "7"; }
};
#endif
