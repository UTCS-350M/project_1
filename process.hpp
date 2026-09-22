//
//  process.hpp
//  Processor Scheduler
//
//  Created by ELMOOTAZBELLAH ELNOZAHY on 9/13/26.
//

#ifndef process_hpp
#define process_hpp

#include "interfaces.h"

class Process {
public:
    Process(Time_t arr, Time_t quanta, ProcessId_t pid) : remaining(quanta), arrival(arr), process_id(pid) {}
    ProcessId_t GetPid()                                        { return process_id; }
    Time_t GetRemaining()                                       { return remaining; }
    bool IsCompleted()                                          { return remaining == 0; }
    void SetRemainingTime(Time_t r_time)                        { (remaining = r_time)? : completed = Now(); /* SimOutput("Task::SetRemainingInstructions for task " + to_string(taskId) + " Remaining instruction " + to_string(r_instr), 4); */}
private:
    Time_t remaining;                       // How much time is remaining
    Time_t arrival;                         // When it arrived
    Time_t completed;                       // When it was completed
    ProcessId_t process_id;                 // Identifier that is set by the scheduler when the process is created
};

#endif /* process_hpp */
