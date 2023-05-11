#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <class T>
class	Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();
		Array	&operator=(const Array &rhs);

		class	OutOfBoundsException : public std::exception
		{
			virtual const char *what() const throw() {return ("OUT OF BOUNDS EXCEPTION");}
		};

		T	&operator[](unsigned int n);
		const T	&operator[](unsigned int n) const;

		unsigned int	size() const;
	private:
		T *_array;
		unsigned int _size;
};

#include "Array.tpp"

#endif