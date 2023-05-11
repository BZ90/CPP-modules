#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBitCount;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (int)(roundf(floatValue * (1 << this->_fractionalBitCount)));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = copy.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = copy.getRawBits();
	return (*this);
}

/* Comparison Operators */

bool	Fixed::operator>(const Fixed &src) const 
{
	return (this->_fixedPointValue > src.getRawBits());
}

bool	Fixed::operator<(const Fixed &src) const
{
	return (this->_fixedPointValue < src.getRawBits());
}

bool	Fixed::operator<=(const Fixed &src) const
{
	return (this->_fixedPointValue <= src.getRawBits());
}

bool	Fixed::operator>=(const Fixed &src) const
{
	return (this->_fixedPointValue >= src.getRawBits());
}

bool	Fixed::operator==(const Fixed &src) const
{
	return (this->_fixedPointValue == src.getRawBits());
}

bool	Fixed::operator!=(const Fixed &src) const
{
	return (this->_fixedPointValue != src.getRawBits());
}

/* Arithmetic Operators */

Fixed	Fixed::operator+(const Fixed &src) const
{
	Fixed	ret;
	ret.setRawBits(this->_fixedPointValue + src.getRawBits());
	return (ret);
}

Fixed	Fixed::operator-(const Fixed &src) const
{
	Fixed	ret;
	ret.setRawBits(this->_fixedPointValue - src.getRawBits());
	return (ret);
}

Fixed	Fixed::operator*(const Fixed &src) const
{
	Fixed	ret;
	ret.setRawBits((this->_fixedPointValue * src.getRawBits()) >> this->_fractionalBitCount);
	return (ret);
}

Fixed	Fixed::operator/(const Fixed &src) const
{
	Fixed	ret;
	ret.setRawBits((this->_fixedPointValue << this->_fractionalBitCount) / src.getRawBits());
	return (ret);
}

/* Pre/Post Increment and Decrement */

Fixed	&Fixed::operator++(void)
{
	++this->_fixedPointValue;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	--this->_fixedPointValue;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);
	++this->_fixedPointValue;
	return (ret);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);
	--this->_fixedPointValue;
	return (ret);
}

/* min and max static functions */

Fixed		&Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}
const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}
Fixed		&Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}
const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

/* Get and Set rawBits functions */

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const newRawBits)
{
	this->_fixedPointValue = newRawBits;
}

/* Conversion functions */

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (1 << this->_fractionalBitCount));
}

int	Fixed::toInt(void) const
{
	return ((int)(this->_fixedPointValue >> this->_fractionalBitCount));
}

/* ostream Insertion Operator */

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}