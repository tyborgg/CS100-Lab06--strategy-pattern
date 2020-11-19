#include "base.hpp"
#include "container.hpp"
#include "sort.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class VectorContainer : public Container
{
        private:
                vector<Base*> vec;
        protected:
                Sort* sort_function;
        public:
	//	void set_sort_function(Sort* sort_function) : Container::set_sort_function(Sort* sort_function);
		VectorContainer() {}
		VectorContainer(Sort* func)
		{
			sort_function = func;
		}
                virtual void add_element(Base* element)
                {
                        vec.push_back(element);
                }

                virtual void print()
                {
                        for(int i = 0; i < vec.size(); i++)
                        {
                                cout << vec.at(i)->stringify() << endl;
                        }
                }

                virtual void sort()
                {
                        if(sort_function != NULL)
                        {
                               sort_function->sort(this);
                        }
                        if(sort_function == NULL)
                        {
                                cout << "No sort function has been specified. Please specify a sort function through set_sort_function to proceed. " << endl;
                        }
                }

                virtual void swap(int i, int j)
                {
                        iter_swap(vec.begin()+i,vec.begin()+j);
                }

                virtual Base* at(int i)
                {
                        return vec[i];
                }

                virtual int size()
                {
                        return int(vec.size());
                }

};

