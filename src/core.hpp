//
//  core.hpp
//  Processor Scheduler
//
//  Created by ELMOOTAZBELLAH ELNOZAHY on 9/13/26.
//

#ifndef core_hpp
#define core_hpp

#include <stdio.h>

#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "interfaces.h"

#define QUANTUM 1000
typedef enum {BIG_CORE, SMALL_CORE} CPUType_t;

class CPU {
public:
    CPU(CPUType_t core_type, CPUId_t c_id)
    : coreType(core_type), cid(c_id), pState(P0), cState(C1), startMeter(0), startRun(0), energyConsumed(0.0), state_transition(false), processId(0) {}
    double GetEnergy()                      { ComputeEnergy(); return energyConsumed; }
    void SetCState(CState_t cstate);
    void SetPState(PState_t pstate);
    void Run();
    void LoadContext(ProcessId_t pid);
    void SaveContext(ProcessId_t pid);
    void BeforeScheduler();
    void AfterScheduler();
private:
    // Intrinsic
    CPUId_t cid;
    CPUType_t coreType;
    Time_t startRun;                        // For tracking execution
    ProcessId_t processId;                  // Which process is running?
    // Energy
    void ComputeEnergy();                   // Update the energy consumption. Must be called whenever P or C state changes
    Time_t startMeter;                      // For tracking energy consumption
    double energyConsumed;                  // A counter of the joules consumed, initialized to 0
    CState_t cState;                        // Current C state, initialized to C1 (idle)
    PState_t pState;                        // Current P state, initialized to P0
    // To mimic the time it takes for a CPU to start up
    bool state_transition;
    Time_t ticks_until_transition;
    CState_t target_cstate;
 };
#endif /* core_hpp */

