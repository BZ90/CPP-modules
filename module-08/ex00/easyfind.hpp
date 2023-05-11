#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <stdexcept>

template <class Container>
typename Container::iterator	easyfind(Container c, int to_find);

#include "easyfind.tpp"

#endif