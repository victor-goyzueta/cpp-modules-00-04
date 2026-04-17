#include "inc/Animal.hpp"
#include "inc/Dog.hpp"
#include "inc/Cat.hpp"

#include <iostream>

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSoundq();

	delete(meta);
	delete(j);
	delete(i);

	return (0);
}
