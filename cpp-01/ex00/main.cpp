#include "inc/Zombie.hpp"

int main(void)
{
    Zombie *heapZ = newZombie("HeapZombie");
    
    heapZ->announce();
    delete (heapZ);
    
    randomChump("StackZombie");
    
    return (0);
}
