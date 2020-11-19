#include "sort.hpp"
#include "container.hpp"
#include "base.hpp"
#include <iostream>
using namespace std;
class SelectionSort : public Sort
{
        public:


                virtual void sort(Container* container)
                {
                        int i, j, first;
                        int containerSize = int(container->size());
			
                        for(i = containerSize - 1; i > 0; i--) //used to be containerSize - 1
                        {
                                first = 0;
                                for(j = 1; j <= i; j++)
                                {
                                        if((container->at(j))->evaluate() < (container->at(first))->evaluate())
                                        {
                                                first = j;
                                        }
                                }
                                container->swap(first,i);
                        }
                }



};

