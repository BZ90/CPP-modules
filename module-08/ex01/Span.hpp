#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <iostream>
# include <algorithm>
# include <utility>
# include <typeinfo>

class	Span
{
	public:
	Span();
	Span(unsigned int N);
	Span(const Span &src);
	~Span();
	Span	&operator=(const Span &rhs);

	void			addNumber(const int n);

	unsigned int	longestSpan() const;
	unsigned int	shortestSpan() const;


	class	FullException : public std::exception
	{
		virtual const char *what() const throw() {return ("FullException: Span is full, cannot add number");}
	};

	class	NoSpansException : public std::exception
	{
		virtual const char *what() const throw() {return ("NoSpansException: Not enough members to find a span");}
	};

	class	InvalidIteratorException : public std::exception
	{
		virtual const char *what() const throw() {return ("InvalidIteratorException: Invalid iterator, expected int");}
	};


	template <class Iterator>
	void	addNumbers(Iterator start, Iterator end);

	private:
		std::vector<int>	_vector;
		unsigned int		_maxSize;
		unsigned int		_currentSize;

};

template <class Iterator>
void	Span::addNumbers(Iterator start, Iterator end)
{
	if (typeid(*start) != typeid(int))
	{
		throw InvalidIteratorException();
	}
	if (this->_currentSize == this->_maxSize)
		throw FullException();
	while (start != end && this->_currentSize < this->_maxSize)
	{
		this->_vector.push_back(*start);
		++this->_currentSize;
		++start;
	}
}

#endif