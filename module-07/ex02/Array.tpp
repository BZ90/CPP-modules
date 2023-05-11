#include "Array.hpp"

template <class T>
Array<T>::Array() : _array(new T()), _size(0)
{
	std::cout << "Array default constructor called" << std::endl;
}

template <class T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
	std::cout << "Array constructor called" << std::endl;
}

template <class T>
Array<T>::Array(const Array &src) : _size(src._size)
{
	std::cout << "Array copy constructor called" << std::endl;
	this->_array = new T[this->_size]();
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
}

template <class T>
Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;
	delete this->_array;
}

template <class T>
Array<T>	&Array<T>::operator=(const Array &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_size = rhs._size;
	delete this->_array;
	this->_array = new T[this->_size]();
	for (int i = 0; i < this->_size; i++)
		this->_array[i] = rhs._array[i];
	return (*this);
}

template <class T>
T	&Array<T>::operator[](unsigned int n)
{
	if (n >= this->_size)
		throw (OutOfBoundsException());
	return (this->_array[n]);
}

template <class T>
const T	&Array<T>::operator[](unsigned int n) const
{
	if (n >= this->_size)
		throw (OutOfBoundsException());
	return (this->_array[n]);
}

template <class T>
unsigned int	Array<T>::size() const {return (this->_size);}