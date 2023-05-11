#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed {
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copy);
		Fixed &operator = (const Fixed &copy);
		~Fixed();

		bool	operator > (const Fixed &src) const;
		bool	operator < (const Fixed &src) const;
		bool	operator <= (const Fixed &src) const;
		bool	operator >= (const Fixed &src) const;
		bool	operator == (const Fixed &src) const;
		bool	operator != (const Fixed &src) const;

		Fixed	operator + (const Fixed &src) const;
		Fixed	operator - (const Fixed &src) const;
		Fixed	operator * (const Fixed &src) const;
		Fixed	operator / (const Fixed &src) const;

		Fixed	&operator ++ (void); // pre increment
		Fixed	&operator -- (void); // pre decrement
		Fixed	operator ++ (int); // post increment
		Fixed	operator -- (int); // post decrement

		static Fixed		&min(Fixed &f1, Fixed &f2);
		const static Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		const static Fixed	&max(const Fixed &f1, const Fixed &f2);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_fixedPointValue;
		static const int	_fractionalBitCount = 8;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif