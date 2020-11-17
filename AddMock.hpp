#ifndef __ADD_MOCK_HPP__
#define __ADD_MOCK_HPP__
#include "base.hpp"
#include <string>
class AddMock: public Base
{
        public:
                AddMock() {};
                virtual double evaluate() {return 9.000000;}
                virtual std::string stringify() {return "6.000000 + 3.000000";}

};

#endif //__MULT_MOCK_HPP__
