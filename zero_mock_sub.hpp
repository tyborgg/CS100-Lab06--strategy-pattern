#ifndef __ZEROMOCKSUB_HPP__
#define __ZEROMOCKSUB_HPP__

#include "base.hpp"

using namespace std;

class ZeroSubMock: public Base {
    public:
        ZeroSubMock() { }

        virtual double evaluate() { return 0;}
        virtual string stringify() { return "(5 - 5)"; }
};
#endif

