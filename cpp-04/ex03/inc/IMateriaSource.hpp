#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>

class IMateriaSource
{
	private:

	public:
		IMateriaSource();
		IMateriaSource( const IMateriaSource& copy );
		~IMateriaSource();

		IMateriaSource& operator=( const IMateriaSource& copy );
};

#endif