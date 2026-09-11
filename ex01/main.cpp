#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	try {
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Basic example " << std::endl;
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;

		std::cout << "\n10,000 numbers " << std::endl;
		Span bigSpan(10001);
		for (int i = 0; i < 10001; ++i)
			bigSpan.addNumber(i);

		std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;

		std::vector<int> v;
		v.push_back(1);
		v.push_back(100);
		v.push_back(50);

		Span sp2(5);
		sp2.addNumbers<std::vector<int> >(v.begin(), v.end());

		std::cout << "\nIterator example" << std::endl;
		std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp2.longestSpan() << std::endl;

	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
