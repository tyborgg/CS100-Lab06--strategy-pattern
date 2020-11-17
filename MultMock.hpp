#ifndef __MULT_MOCK_HPP__
#define __MULT_MOCK_HPP__
#include "base.hpp"
#include <string>
class MultMock: public Base
{
	public:
		MultMock() {};
		virtual double evaluate() {return 12.000000;}
		virtual std::string stringify() {return "3.000000 * 4.000000";}

};

#endif //__MULT_MOCK_HPP__
