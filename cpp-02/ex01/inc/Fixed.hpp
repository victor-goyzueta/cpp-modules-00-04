#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int						_nValue;
		static const int		_nFractBits = 8;
		friend std::ostream&	operator<<( std::ostream& os, const Fixed& fixed );

	public:
		Fixed( void );
		Fixed( const Fixed& copy );
		Fixed( const int value );
		Fixed( const float value );
		~Fixed();

		Fixed& operator=( const Fixed& copy );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

#endif
