#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

int main() {
	std::cout << "My own tests" << std::endl;
	{
		MutantStack<int> empty;
		std::cout << "is Empty: " << empty.empty() << " size : " << empty.size() << std::endl;

		MutantStack<int> ms;
		ms.push(1337);ms.push(42);ms.push(443);

		MutantStack<int> copy(ms);
		copy.push(3000);
		
		std::cout << "ms size: " << ms.size() << "; copy size: " << copy.size() << std::endl;

		MutantStack<int>::iterator it = ms.begin();

		std::cout << "it[0] = " << it[0] << "; it[len -1] = " << it[ms.size() -1] << std::endl;

		MutantStack<int> sorted_copy(copy);

		std::sort(sorted_copy.begin(), sorted_copy.end());

		MutantStack<int>::iterator sorted_it = sorted_copy.begin();
		for (; sorted_it != sorted_copy.end(); sorted_it++)
			std::cout << *sorted_it << " ";
		std::cout << std::endl;
	}

	std::cout << "Subject tests" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

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
