//
//  simulator.hpp
//  Processor Scheduler
//
//  Created by ELMOOTAZBELLAH ELNOZAHY on 9/13/26.
//

#ifndef simulator_hpp
#define simulator_hpp

#include <iostream>
#include <queue>
#include <memory>

#include "interfaces.h"
#include "sim_types.h"

class Event {
public:
    Event(Time_t t) : time(t)                       {}
    Time_t GetEventTime()                           { return time; }
    virtual void Execute() = 0;
protected:
    Time_t time;
};

class CreateProcessEvent : public Event {
public:
    CreateProcessEvent(Time_t time, ProcessId_t pid) : Event(time), process_id(pid) {}
    void Execute() override { CreateProcess(process_id); }
private:
    ProcessId_t process_id;
};

class ExitProcessEvent : public Event {
public:
    ExitProcessEvent(Time_t time, ProcessId_t pid) : Event(time), process_id(pid) {}
    void Execute() override { ExitProcess(process_id); }
private:
    ProcessId_t process_id;
};

class TimerEvent: public Event {
public:
    TimerEvent(Time_t time) : Event(time)  {}
    void Execute() override { CoresHandleTimer(time>>2); }
};

class Simulator {
public:
    Simulator()                                 { now = Time_t(0); }
    void AddEvent(std::shared_ptr<Event> event) { eventQueue.push(event); }
    Time_t Now()                                { return now; }
    void Simulate();
private:
    struct EventComparator {
        bool operator()(const std::shared_ptr<Event>& e1, const std::shared_ptr<Event>& e2) const {
            return e1->GetEventTime() > e2->GetEventTime();
        }
    };
    std::priority_queue<std::shared_ptr<Event>, std::vector<std::shared_ptr<Event>>, EventComparator> eventQueue;
    Time_t now;
};

#endif /* simulator_hpp */
