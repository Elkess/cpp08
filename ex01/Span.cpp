#include "Span.hpp"
#include <algorithm>
	
Span::Span()
{
	N = 0;
}

Span::Span(const Span &other)
{
	N = other.N;
	numbers = other.numbers;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)	
	{
		N = other.N;
		numbers = other.numbers;
	}
	return *this;
}

Span::Span(unsigned int n)
{
	N = n;
}

Span::~Span() {}

unsigned int Span::getN() const
{
	return N;
}

void	Span::addNumber(const int &number)
{
	if (numbers.size() >= N)
		throw std::runtime_error("Cannot add more numbers, container is full");

	numbers.push_back(number);	
}

int		Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::sort(numbers.begin(), numbers.end());
	int shortest = numbers[1] - numbers[0];
	for (size_t i = 1; i < numbers.size(); ++i)
	{
		int span = numbers[i] - numbers[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

int		Span::longestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::sort(numbers.begin(), numbers.end());
	int min = numbers[0];
	int max = numbers[numbers.size() - 1];
	return max - min;
}




