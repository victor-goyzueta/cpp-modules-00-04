#include "../inc/Fixed.hpp"

# include <iostream>
# include <cmath>

Fixed::Fixed() : _nValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_nValue = copy._nValue;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_nValue = value << _nFractBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_nValue = roundf(value * (1 << _nFractBits));
}

Fixed&	Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_nValue = copy._nValue;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nValue);	
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nValue = raw;	
}

int		Fixed::toInt( void ) const
{
	return ( _nValue >> _nFractBits);
}

float	Fixed::toFloat( void ) const
{
	return( (float)_nValue / (1 << _nFractBits) );
}
