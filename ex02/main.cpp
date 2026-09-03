#include "MutantStack.hpp"
#include <iostream>
#include <list>

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other): std::stack<T, Container>(other){}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack(){}

template<typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack& other)
{
    if (this != &other)
        std::stack<T, Container>::operator=(other);
    return *this;
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() { 
    return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() { 
    return this->c.end();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const { 
    return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const { 
    return this->c.end();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() { 
    return this->c.rbegin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() { 
    return this->c.rend();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const { 
    return this->c.rbegin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const { 
    return this->c.rend();
}

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