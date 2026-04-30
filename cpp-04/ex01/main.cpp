#include "inc/Animal.hpp"
#include "inc/Dog.hpp"
#include "inc/Cat.hpp"
#include "inc/Brain.hpp"

#include <iostream>
#include <string>

#define size 4

int main(void)
{
	{		
		std::cout << "----- TESTING LEAKS -----" << std::endl;

		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		delete j;
		delete i;

		std::cout << std::endl;
	}
	{
		std::cout << "----- TESTING INSTANCES -----" << std::endl;
		
		Animal*	animals[size];

		for (size_t i = 0; i < size / 2; i++)
			animals[i] = new Dog;
		for (size_t i = size / 2; i < size; i++)
			animals[i] = new Cat;

		for (size_t i = 0; i < size; i++)
			animals[i]->makeSound();
		
		for (size_t i = 0; i < size; i++)
			delete animals[i];
		
		std::cout << std::endl;
	}
	{
		std::cout << "----- TESTING DEEP COPIES -----" << std::endl;
		
		Dog original;
		original.getBrain().setIdea("I want a bone", 0);

		Dog copy(original);
		copy.getBrain().setIdea("I want a steak", 0);

		std::cout << "Original idea: "
				<< original.getBrain().getIdea(0) << std::endl;
		std::cout << "Copy idea: "
				<< copy.getBrain().getIdea(0) << std::endl;
		std::cout << std::endl;
	}
	return (0);
}

// INSTANTIABLE CLASS //

// int main(void)
// {
// 	const Animal*	i = new Animal();

// 	i->getType();
// 	i->makeSound();

// 	delete	i;

// 	return (0);
// }
