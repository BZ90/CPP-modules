#include "easyfind.hpp"

template <class Container>
typename Container::iterator	easyfind(Container c, int to_find)
{
	typename Container::iterator	iter = std::find(c.begin(), c.end(), to_find);
	if (iter == c.end())
		throw std::out_of_range("Easyfind could not find passed value");
	return (iter);
}