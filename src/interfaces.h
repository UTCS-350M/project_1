//
//  interfaces.h
//  Processor Scheduler
//
//  Created by ELMOOTAZBELLAH ELNOZAHY on 9/13/26.
//

#ifndef interfaces_h
#define interfaces_h

#include <iostream>
#include <random>
#include <vector>
#include <string>

#include "sim_types.h"

std::string FormatTime(Time_t now);

void SimOutput(std::string msg, unsigned level);
void ThrowException(std::string err_msg);

void GenerateProcesses(unsigned seed);


void Simulate();
void ScheduleNewProcess(Time_t time, ProcessId_t pid);
void ScheduleExitProcess(Time_t time, ProcessId_t pid);
void ScheduleTimer(Time_t time);
Time_t Now();

void CreateProcess(ProcessId_t pid);
void ExitProcess(ProcessId_t pid);

// core.cpp
void InitCores();
void CoresHandleTimer(Time_t now);
double GetTotalEnergyConsumed();
void LoadContext(ProcessId_t pid, CPUId_t core);
void SaveContext(ProcessId_t pid, CPUId_t core);
void RunCore(CPUId_t core);

// process.cpp
void AddProcess(Time_t arrival, Time_t quanta);
ProcessId_t InvalidProcessId();
Time_t GetRemaining(ProcessId_t pid);
void SetRemainingTime(ProcessId_t pid, Time_t remaining);
unsigned GetActiveProcesses();
void CompleteProcess(ProcessId_t pid);
void SetPState(CPUId_t cpu_id, PState_t p_state);
void SetCState(CPUId_t cpu_id, CState_t c_state);


void CStateTransitionComplete(CPUId_t core_id);
void TimerInterrupt(Time_t now);




void SimulationComplete(Time_t now);

#endif /* interfaces_h */
