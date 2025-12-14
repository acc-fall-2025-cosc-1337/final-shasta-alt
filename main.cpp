#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include "Die.h"
#include "Shooter.h"

int main()
{
    srand(time(0));

    Die die1;
    Die die2;
    Shooter shooter;

    for(int i = 0; i < 10; i++)
    {
        Roll* roll = shooter.throw_dice(die1, die2);
        int value = roll->roll_value();
        std::cout << value << std::endl;
        assert(value >= 2 && value <= 12);
    }

    std::cout << "Question 3 test passed" << std::endl;
    return 0;
}
