#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__


#include "sort.hpp"
#include "container.hpp"
#include <iostream>
#include <list>
#include "base.hpp"

using namespace std;

class ListContainer : public Container{
	public:
		list<Base*> list1;

		ListContainer();
		ListContainer(Sort* func);

		void add_element(Base* element);	
		void print();

		void sort();

		void swap(int i, int j);

		Base* at(int i);

		int size();



};
#endif

