#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					_fixedPointValue;
		static const int	_fractionalBitCount = 8;

};

#endif