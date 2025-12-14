#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include "Die.h"

int main()
{
    srand(time(0));

    Die die;

    for(int i = 0; i < 10; i++)
    {
        int value = die.roll();
        std::cout << value << std::endl;
        assert(value >= 1 && value <= 6);
    }

    std::cout << "Question 1 test passed" << std::endl;
    return 0;
}
