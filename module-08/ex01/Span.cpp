#include "Span.hpp"

Span::Span() : _maxSize(0), _currentSize(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _maxSize(N), _currentSize(0)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &src) : _vector(src._vector), _maxSize(src._maxSize), _currentSize(src._currentSize)
{
	std::cout << "Span copy constructor called" << std::endl;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

Span	&Span::operator=(const Span &rhs)
{
	this->_vector = rhs._vector;
	this->_maxSize = rhs._maxSize;
	this->_currentSize = rhs._currentSize;
	return (*this);
}

void	Span::addNumber(const int n)
{
	if (this->_currentSize == this->_maxSize)
		throw FullException();
	this->_vector.push_back(n);
	++this->_currentSize;
}

unsigned int	Span::longestSpan() const
{
	if (this->_currentSize <= 1)
		throw NoSpansException();
	std::pair<std::vector<const int>::iterator, std::vector<const int>::iterator> minMax = std::minmax_element(this->_vector.begin(), this->_vector.end());
	return (*minMax.second - *minMax.first);
}

unsigned int	Span::shortestSpan() const
{
	if (this->_currentSize <= 1)
		throw NoSpansException();

	{
		std::vector<int>	sorted = this->_vector;
		int					shortest;

		sort(sorted.begin(), sorted.end());
		std::vector<int>::iterator	current = sorted.begin();
		std::vector<int>::iterator	next = current;

		++next;
		shortest = *next - *current;
		while (next != sorted.end())
		{
			if ((*next - *current) < shortest)
				shortest = *next - *current;
			++current;
			++next;
		}
		if (shortest < 0)
			shortest *= -1;
		return (shortest);
	}
}