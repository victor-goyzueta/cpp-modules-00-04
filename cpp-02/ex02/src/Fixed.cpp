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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_nValue = copy._nValue;
	return (*this);
}

bool	Fixed::operator>( const Fixed&other ) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<( const Fixed&other ) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=( const Fixed&other ) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=( const Fixed&other ) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==( const Fixed&other ) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=( const Fixed&other ) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+( const Fixed& other ) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-( const Fixed& other ) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*( const Fixed& other ) const
{
	Fixed	result;

	result.setRawBits((this->getRawBits() * other.getRawBits()) >> _nFractBits);
	return (result);
}

Fixed	Fixed::operator/( const Fixed& other ) const
{
	Fixed	result;

	if (other._nValue == 0)
	{
		std::cout << "Fixed::operator/: division by zero" << std::endl;
		return result;
	}
	result.setRawBits((this->getRawBits() << _nFractBits) / other.getRawBits());
	return (result);
}

Fixed&	Fixed::operator++( void )
{
	this->_nValue++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed tmp(*this);

    this->_nValue++;
    return (tmp);
}

Fixed&	Fixed::operator--( void )
{
	this->_nValue--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed tmp(*this);

    this->_nValue--;
    return (tmp);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
    return ((a < b) ? a : b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
    return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
    return ((a > b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
    return ((a > b) ? a : b);
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

std::ostream& operator<<(std::ostream& out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
