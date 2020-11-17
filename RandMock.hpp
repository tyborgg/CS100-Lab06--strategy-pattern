#ifndef __RAND_MOCK_HPP__
#define __RAND_MOCK_HPP__
#include "base.hpp"
#include <string>
class RandMock: public Base
{
        public:
                RandMock() {};
                virtual double evaluate() {return 11.000000;}
                virtual std::string stringify() {return "11.000000";}

};

#endif //__RAND_MOCK_HPP__


