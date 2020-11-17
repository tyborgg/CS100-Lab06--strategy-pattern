#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Rand : public Base {
    public:
	double random;
        Rand() : Base(){
		random = rand() % 100;
	}
        virtual double evaluate(){
		return random;
	}
        virtual string stringify(){
		string str = "";
		str = to_string(random);
		return str;
	}
};

#endif //__RAND_HPP__
