#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &con, int n)
{
	typename T::iterator it = std::find(con.begin(), con.end(), n);
	if (it == con.end())
		throw std::runtime_error("Value not found in container");
	return it;
}

template<typename T>
typename T::const_iterator easyfind(const T &con, int n)
{
	typename T::const_iterator it = std::find(con.begin(), con.end(), n);
	if (it == con.end())
		throw std::runtime_error("Value not found in container");
	return it;
}
#endif