#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <class T>
void	swap (T &a, T &b)
{
	T buf = a;
	a = b;
	b = buf;
}

template <class T>
T	&min (T &a, T &b)
{
	return (a < b ? a : b);
}

template <class T>
T	&max (T &a, T &b)
{
	return (a > b ? a : b);
}

#endif