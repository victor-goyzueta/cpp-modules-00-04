#include <iostream>
#include <string>

#include "inc/AMateria.hpp"
#include "inc/Character.hpp"
#include "inc/ICharacter.hpp"
#include "inc/MateriaSource.hpp"
#include "inc/IMateriaSource.hpp"
#include "inc/Ice.hpp"
#include "inc/Cure.hpp"


/*SUBJECT MAIN*/
// int main()
// {
// 	IMateriaSource* src = new MateriaSource();

// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;

// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);

// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;

// 	return 0;
// }


/*OWN MAIN*/
int	main()
{
	ICharacter*	me = new  Character("me");
	IMateriaSource*	m = new MateriaSource();

	m->learnMateria(new Ice());
	m->learnMateria(new Ice());
	m->learnMateria(new Ice());
	m->learnMateria(new Ice());
	m->learnMateria(new Cure());

	AMateria*	tmp;

	tmp = m->createMateria("cure");
	me->equip(tmp);

	tmp = m->createMateria("ice");
	me->equip(tmp);

	tmp = m->createMateria("ice");
	me->equip(tmp);

	tmp = m->createMateria("ice");
	me->equip(tmp);

	tmp = m->createMateria("cure");
	me->equip(tmp);

	me->unequip(0);
	
	ICharacter* enemy = new Character("enemy");
	me->use(0, *enemy);
	me->use(1, *enemy);
	me->use(2, *enemy);
	me->use(3, *enemy);
	me->use(4, *enemy);

	delete me;
	delete m;
	delete enemy;

	return 0;
}
