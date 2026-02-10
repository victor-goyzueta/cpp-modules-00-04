#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_nValue;
		static const int	_nFractBits = 8;

	public:
		Fixed( void );
		Fixed( const Fixed& copy );
		Fixed& operator=( const Fixed& copy );
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
