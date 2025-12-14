#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include "Die.h"
#include "Roll.h"

int main()
{
    srand(time(0));

    Die die1;
    Die die2;
    Roll roll(die1, die2);

    for(int i = 0; i < 10; i++)
    {
        roll.roll_dice();
        int value = roll.roll_value();
        std::cout << value << std::endl;
        assert(value >= 2 && value <= 12);
    }

    std::cout << "Question 2 test passed" << std::endl;
    return 0;
}
