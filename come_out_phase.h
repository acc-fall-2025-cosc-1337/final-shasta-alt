#ifndef COME_OUT_PHASE_H
#define COME_OUT_PHASE_H

#include "phase.h"  // MUST include phase.h to know RollOutcome

class ComeOutPhase : public Phase
{
public:
    RollOutcome get_outcome(Roll* roll) override;
};

#endif
