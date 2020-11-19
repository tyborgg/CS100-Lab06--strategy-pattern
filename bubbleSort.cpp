#include "sort.hpp"
#include "container.hpp"
#include "base.hpp"
#include <iostream>
using namespace std;
class BubbleSort : public Sort
{
        public:


                virtual void sort(Container* c)
                {
                      	  int i, j;
			  for(i = 0; i < c->size(); i++) {
        			for(j = 0; j < c->size() - 1; j++) {
            				if(c->at(j)->evaluate() > c->at(j+1)->evaluate()) {
                				c->swap(j, j+1);
            				}	
        			}
    			}

                }
};

