//
//  sim_types.h
//  Processor Scheduler
//
//  Created by ELMOOTAZBELLAH ELNOZAHY on 9/13/26.
//

#ifndef sim_types_h
#define sim_types_h

#include<iostream>
#include<cstdint>

#define QUANTUM 1000

typedef std::uint32_t CPUId_t;              // Id's from 0 to 3: Big cores. Id's from 4 to 7: Small cores.
typedef std::uint32_t ProcessId_t;
typedef std::int64_t Time_t;

typedef enum{P0, P1, P2, P3, P4} PState_t;                  // DVFS
typedef enum{C0, C1, C2, C3, C4, C5, C6, C7} CState_t;
    // C0: Normal.
    // C1: Pipeline clock gated.
    // C2: Core clock gated.
    // C3: CPU in low-voltage.
    // C4: Even lower voltage.
    // C5: Not used,
    // C6: Core turned off.
    // C7: Core turned off along with L3 cache. All cores are off.

#endif /* sim_types_h */
