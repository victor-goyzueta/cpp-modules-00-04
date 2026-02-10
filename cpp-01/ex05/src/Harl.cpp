#include "../inc/Harl.hpp"

#include <iostream>
#include <string>

Harl::Harl () {}

Harl::~Harl	() {}

void	Harl::complain( std::string level)
{
    typedef void (Harl::*HarlFunc)();
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    HarlFunc funcs[] = 
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    for (int i = 0; i < 4; ++i)
    {
        if (levels[i] == level)
        {
            (this->*funcs[i])();
            return ;
        }
    }
    std::cout << "[ Harl does not understand this order ]" 
              << std::endl;
}

void    Harl::debug( void )
{
    std::cout << "[ DEBUG MESSAGE ]" 
              << std::endl 
              << "This is a debug message from my friend Harl"
              << std::endl;
}

void    Harl::info( void )
{
    std::cout << "[ INFO MESSAGE ]" 
              << std::endl 
              << "This is an info message from my friend Harl"
              << std::endl;   
}

void    Harl::warning( void )
{
    std::cout << "[ WARNING MESSAGE ]"
              << std::endl
              << "This is a warning message from my friend Harl"
              << std::endl;    
}

void    Harl::error( void )
{
    std::cout << "[ ERROR MESSAGE ]"
              << std::endl 
              << "This is an error message from my friend Harl"
              << std::endl;
}