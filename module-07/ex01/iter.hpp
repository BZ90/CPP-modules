#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class T>
void	iter(T array[], unsigned int len, void (*f)(T &val))
{
	for (unsigned int i = 0; i < len; i++)
	{
		(*f)(array[i]);
	}
}

template <class T>
void	test(T &val)
{
	std::cout << val << std::endl;
}

#endif