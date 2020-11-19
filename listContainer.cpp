#include "listContainer.hpp"		
			
		ListContainer::ListContainer(){}

		ListContainer::ListContainer(Sort* func){
                        sort_function = func;
                }

	
                void ListContainer::add_element(Base* element){
                        list1.push_back(element);
                }

                void ListContainer::print(){
                        for (auto v : list1)
                                cout << v->stringify() << "\n";
                }

                void ListContainer::sort(){
                        if(sort_function != NULL){
                                sort_function->sort(this);
                        }
                }

                void ListContainer::swap(int i, int j){
                                list<Base*>::iterator it1 = list1.begin();
                                advance(it1, i);
                                list<Base*>::iterator it2 = list1.begin();
                                advance(it2, j);

                                std::swap(*it1, *it2);
                }

                Base* ListContainer::at(int i){
                        int count  = 0;
                        list<Base*>::iterator j = list1.begin();
                        while(count != i){
                                j++;
                                count++;
                        }

                        return *j;
                }

                int ListContainer::size(){
                        return list1.size();
                }

