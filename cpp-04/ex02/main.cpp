#include "inc/AAnimal.hpp"
#include "inc/Dog.hpp"
#include "inc/Cat.hpp"
#include "inc/Brain.hpp"

#include <iostream>
#include <string>

#define size 4

// INSTANTIABLE CLASS //

// int main(void)
// {
// 	const AAnimal*	i = new AAnimal();

// 	i->getType();
// 	i->makeSound();

// 	delete	i;

// 	return (0);
// }

// 	ABSTRACT CLASS //

int main(void)
{
	const AAnimal*	i = new Dog();

	i->getType();
	i->makeSound();

	delete	i;

	return (0);
}

// 	ABSTRACT CLASS more thorough //

// int main(void)
// {
// 	{		
// 		std::cout << "----- TESTING LEAKS -----" << std::endl;

// 		const AAnimal*	j = new Dog();
// 		const AAnimal*	i = new Cat();

// 		delete j;
// 		delete i;

// 		std::cout << std::endl;
// 	}
// 	{
// 		std::cout << "----- TESTING INSTANCES -----" << std::endl;
		
// 		AAnimal*	AAnimals[size];

// 		for (size_t i = 0; i < size / 2; i++)
// 			AAnimals[i] = new Dog;
// 		for (size_t i = size / 2; i < size; i++)
// 			AAnimals[i] = new Cat;

// 		for (size_t i = 0; i < size; i++)
// 			AAnimals[i]->makeSound();
		
// 		for (size_t i = 0; i < size; i++)
// 			delete AAnimals[i];
		
// 		std::cout << std::endl;
// 	}
// 	{
// 		std::cout << "----- TESTING DEEP COPIES -----" << std::endl;
		
// 		Dog original;
// 		original.getBrain().setIdea("I want a bone", 0);

// 		Dog copy(original);
// 		copy.getBrain().setIdea("I want a steak", 0);

// 		std::cout << "Original idea: "
// 				<< original.getBrain().getIdea(0) << std::endl;
// 		std::cout << "Copy idea: "
// 				<< copy.getBrain().getIdea(0) << std::endl;
// 		std::cout << std::endl;
// 	}
// 	return (0);
// }
