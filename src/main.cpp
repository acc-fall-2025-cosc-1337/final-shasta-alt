#include <iostream>
#include <cassert>
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
    srand(time(0));

    Die die1, die2;
    Shooter shooter;

    ComeOutPhase come_out_phase;
    std::cout << "ComeOutPhase rolls:" << std::endl;
    for(int i = 0; i < 10; i++)
    {
        Roll* roll = shooter.throw_dice(die1, die2);
        RollOutcome outcome = come_out_phase.get_outcome(roll);
        int value = roll->roll_value();
        std::cout << value << " ";
        assert(outcome == RollOutcome::natural || outcome == RollOutcome::craps || outcome == RollOutcome::point);
    }
    std::cout << std::endl;

    PointPhase point_phase(5);
    std::cout << "PointPhase rolls:" << std::endl;
    for(int i = 0; i < 10; i++)
    {
        Roll* roll = shooter.throw_dice(die1, die2);
        RollOutcome outcome = point_phase.get_outcome(roll);
        int value = roll->roll_value();
        std::cout << value << " ";
        assert(outcome == RollOutcome::point || outcome == RollOutcome::seven_out || outcome == RollOutcome::nopoint);
    }
    std::cout << std::endl;

    std::cout << "Question 4 test passed" << std::endl;
    return 0;
}
