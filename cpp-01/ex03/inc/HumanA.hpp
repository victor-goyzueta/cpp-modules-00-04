#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "../inc/Weapon.hpp"
# include <iostream>
# include <string>

class HumanA
{
	private:
		Weapon	_weapon;
		std::string	_name;

	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA();
		void	attack();
};

#endif
