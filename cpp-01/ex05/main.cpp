# include "inc/Harl.hpp"

int main ( void )
{
    Harl harl;
    
    std::cout << "Calling harl to complain about debug"
              << std::endl;
    harl.complain("DEBUG");
    std::cout << "Calling harl to complain about info"
              << std::endl;
    harl.complain("INFO");
    std::cout << "Calling harl to complain about warning"
              << std::endl;
    harl.complain("WARNING");
    std::cout << "Calling harl to complain about error"
              << std::endl;
    harl.complain("ERROR");
    std::cout << "Calling harl to a unknowed parameter"
              << std::endl;
    harl.complain("42");
    return ( 0 );
}
