#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
	private:
		unsigned int	N;
		std::vector<int>	numbers;
	public:
		Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		Span(unsigned int n);
		unsigned int getN() const;
	
		void	addNumber(const int &number);
		int		shortestSpan();
		int		longestSpan();
		template <typename T>
		void	addNumbers(typename T::iterator begin, typename T::iterator end)
		{
			if (numbers.size() + std::distance(begin, end) > N)
				throw std::runtime_error("Cannot add more numbers, container is full");
			numbers.insert(numbers.end(), begin, end);
		}
		~Span();
};

#endif
