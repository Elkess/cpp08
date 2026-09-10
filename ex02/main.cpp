#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    MutantStack<int> ms;

    ms.push(7);
    ms.push(1);

    std::cout << "Size: " << ms.size() << std::endl;
    std::cout << "Top ele: " << ms.top() << std::endl;

    ms.push(1337);
    ms.push(42);
    ms.push(443);
    ms.push(0);
    ms.push(3000);

    MutantStack<int>::iterator it = ms.begin();

    MutantStack<int>::iterator end = ms.end();

    while (it != end)
    {
        std::cout << *it << std::endl;
        it++;
    }

    std::stack<int> s(ms);

    std::cout << "\nComparing with std::list" << std::endl;

    std::list<int> slist;
    
    slist.push_back(7);
    slist.push_back(1);
    slist.push_back(1337);
    slist.push_back(42);
    slist.push_back(443);
    slist.push_back(0);
    slist.push_back(3000);
    
    std::list<int>::iterator ls_it = slist.begin();
    std::list<int>::iterator ls_end = slist.end();


    while (ls_it != ls_end)
    {
        std::cout << *ls_it << std::endl;
        ++ls_it;
    }

}