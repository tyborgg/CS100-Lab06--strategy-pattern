#ifndef __DIV_MOCK_HPP__
#define __DIV_MOCK_HPP__
#include "base.hpp"
#include <string>
class DivMock: public Base
{
        public:
                DivMock() {};
                virtual double evaluate() {return 2.000000;}
                virtual std::string stringify() {return "8.000000 / 4.000000";}

};

#endif //__DIV_MOCK_HPP__

