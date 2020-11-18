#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__

#include "container.hpp"
#include "base.hpp"
using namespace std;

class VectorContainer : public Container
{
	private:
		vector<Base*> vec;
	protected:
		Sort* sort_function;
	public:
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
			else
			{
				cout << "No sort function has been specified. Please specify a sort function through set_sort_function to proceed. " << endl;
			}
		}

		virtual void swap(int i, int j)
		{
			Base* temp1 = vec[i];
			vec[i] = vec[j];
			vec[j] = temp1;
			delete temp1;
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

#endif //__VECTORCONTAINER_HPP__
