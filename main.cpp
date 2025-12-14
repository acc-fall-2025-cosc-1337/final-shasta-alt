#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Die.h"
#include "Roll.h"
#include "Shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main()
{
    // Initialize random seed
    srand(time(0));

    // Create two dice
    Die die1, die2;

    // Create a shooter
    Shooter shooter;

    // Pointer to Roll
    Roll* roll = nullptr;

    // Come Out Phase
    ComeOutPhase come_out_phase;

    std::cout << "Come Out Phase:" << std::endl;

    // Loop until natural or craps is NOT rolled
    do
    {
        roll = shooter.throw_dice(die1, die2);
        int value = roll->roll_value();

        RollOutcome outcome = come_out_phase.get_outcome(roll);
        std::cout << "Rolled " << value << std::endl;

        if(outcome == RollOutcome::natural || outcome == RollOutcome::craps)
            std::cout << "Roll again" << std::endl;

    } while(come_out_phase.get_outcome(roll) == RollOutcome::natural || 
            come_out_phase.get_outcome(roll) == RollOutcome::craps);

    int point_value = roll->roll_value();
    std::cout << "Start of Point Phase with point = " << point_value << std::endl;
    std::cout << "Roll until " << point_value << " or 7 is rolled." << std::endl;

    // Point Phase
    PointPhase point_phase(point_value);

    while(true)
    {
        roll = shooter.throw_dice(die1, die2);
        int value = roll->roll_value();
        RollOutcome outcome = point_phase.get_outcome(roll);

        std::cout << "Rolled " << value << std::endl;

        if(outcome == RollOutcome::point)
        {
            std::cout << "End of Point Phase - Player wins!" << std::endl;
            break;
        }
        else if(outcome == RollOutcome::seven_out)
        {
            std::cout << "End of Point Phase - Player loses!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Roll again" << std::endl;
        }
    }

    // Display all rolled values
    std::cout << "\nAll rolled values:" << std::endl;
    shooter.display_rolled_values();

    return 0;
}
