#ifndef CPUScheduler_CPP
#define CPUScheduler_CPP

#include <iostream>
#include "queue.cpp"

using namespace std;

class Process{
    int burst_time;
    int arrival_time;
    int priority;
    int waitingTime;

public:
    Process() {
        this->burst_time=0;
        this->arrival_time=0;
        this->priority=0;
        this->waitingTime = 0;
    }

    void setBurstTime(int burstTime) {
        burst_time = burstTime;
    }

    void setArrivalTime(int arrivalTime) {
        arrival_time = arrivalTime;
    }

    void setPriority(int p) {
        this->priority = p;
    }

    int getBurstTime() const {
        return burst_time;
    }

    int getArrivalTime() const {
        return arrival_time;
    }

    int getPriority() const {
        return priority;
    }

    void resetWatingTime(){
        waitingTime = 0;
    }

    int getWaitingTime() const{
        return waitingTime;
    }

    void incrementWaiting(){
        this->waitingTime++;
    }

    friend ostream& operator << (ostream& out, Process& p){
        out << p.burst_time << ',' << p.arrival_time << ',' << p.priority << " W: " << p.waitingTime <<  endl;
        return out;
    }
};

class CPU_Sheduler{
    Process **processes;
    int process_no;

public:
    explicit CPU_Sheduler(int size){
        processes = new Process*[size];
        process_no = 0;
    }

    void Add_Process(int b, int a, int p){
        Process *process;
        process = new Process;
        process->setBurstTime(b);
        process->setArrivalTime(a);
        process->setPriority(p);
        processes[process_no++] = process;
    }

    static bool Compare(Process p1, Process p2, int mode){
        if(mode == 1) {
            if (p1.getBurstTime() > p2.getBurstTime())
                return true;
        }

        else if(mode == 2){
            if (p1.getArrivalTime() > p2.getArrivalTime())
                return true;
        }
        return false;
    }

    static void insertionSort(Process **arr, int n, int mode)
    {
        int i, j;
        Process key;
        for (i = 1; i < n; i++){
            key = *arr[i];
            j = i - 1;

            // Move elements of arr[0..i-1],
            // that are greater than key, to one
            // position ahead of their
            // current position
            while (j >= 0 && Compare(*arr[j],key,mode)){
                //mode will tell what data member is to be comapred
                //in case of mode = 1, compare burst time
                //in case of mode = 2, compare arrival time

                *arr[j + 1] = *arr[j];
                j = j - 1;
            }
            *arr[j + 1] = key;
        }
    }

    int getSumBurstTime(){
        int sum = 0, i;
        for(i=0; i<process_no; i++){
            sum += processes[i]->getBurstTime();
        }
        return sum;
    }

    int getMaxArrivalTime(){
        int max = 0, i;
        for(i=0; i<process_no; i++){
            if(max < processes[i]->getArrivalTime())
                max = processes[i]->getArrivalTime();
        }
        return max;
    }

    int getArivingProcesses(int arr){
        int i;
        for(i=0; i<process_no && processes[i]->getArrivalTime() <= arr; i++);
        return i-1;
    }

    void resetWaitingTime(){
        int i;
        for(i=0; i<process_no; i++)
            processes[i]->resetWatingTime();
    }

    void FCFS(ostream& out){
        Queue<Process*> q;
        Process* p = nullptr;
        int i, maxCounter, index, j, burst = 0, start = 0;

        resetWaitingTime();
        insertionSort(processes,process_no,2);
        maxCounter = getMaxArrivalTime() + getSumBurstTime();

        for(i=0; i<maxCounter; i++){
            index = getArivingProcesses(i);

            if(index >= start) {
                for (j = start; j <= index; j++)
                    q.enqueue(processes[j], processes[j]->getArrivalTime());
                start = index + 1;
            }

            if(p == nullptr || p->getBurstTime() == burst) {
                p = q.dequeue();
                burst = 0;
            }
            q.addWaitTime();
            burst++;
        }
        Print_FCFS_waiting_time(out);
    }

    void Print_FCFS_waiting_time(ostream& out){
        int sum=0, wait;
        out << "Scheduling Method: First Come First Served\n";
        out << "Process Waiting Times:\n";
        for(int i=0;i<process_no;i++){
            wait = processes[i]->getWaitingTime();
            out << "P" << i+1 << ": " << wait << " ms\n";
            sum = sum+wait;
        }
        out << "Average Waiting Time: " << sum/(process_no*1.0) << " ms\n";
    }

    void SJF(bool isPreemptive, ostream& out){
        Queue<Process*> q;
        Process* p = nullptr;
        int i, maxCounter, index, j, start = 0;
        int burstBackup[process_no];

        for(i=0; i<process_no; i++)
            burstBackup[i] = processes[i]->getBurstTime();

        resetWaitingTime();
        insertionSort(processes,process_no,2);
        maxCounter = getMaxArrivalTime() + getSumBurstTime();

        for(i=0; i<maxCounter; i++){
            index = getArivingProcesses(i);

            if(p != nullptr){
                p->setBurstTime(p->getBurstTime()-1);
                if(isPreemptive  && p->getBurstTime() != 0) {
                    q.enqueue(p, p->getBurstTime());
                }
            }

            if(index >= start) {
                for (j = start; j <= index; j++)
                    q.enqueue(processes[j], processes[j]->getBurstTime());
                start = index + 1;
            }

            if(p == nullptr || p->getBurstTime() == 0 || isPreemptive) {
                p = q.dequeue();
            }

            q.addWaitTime();
        }

        for(i=0; i<process_no; i++)
            processes[i]->setBurstTime(burstBackup[i]);

        Print_SJF_waiting_time(isPreemptive, out);
    }

    void Print_SJF_waiting_time(bool isPreemptive, ostream& out){
        int sum=0, wait;
        out << "Scheduling Method: Shortest Job First ";
        if(isPreemptive)
            out << "- Preemptive\n";
        else
            out << "- Non-Preemptive\n";
        out << "Process Waiting Times:\n";
        for(int i=0;i<process_no;i++){
            wait = processes[i]->getWaitingTime();
            out << "P" << i+1 << ": " << wait << " ms\n";
            sum = sum+wait;
        }
        out << "Average Waiting Time: " << sum/(process_no*1.0) << " ms\n";
    }

    void PS(bool isPreemptive, ostream& out){
        Queue<Process*> q;
        Process* p = nullptr, *p1;
        int i, maxCounter, index, j, start = 0;
        int burstBackup[process_no];

        for(i=0; i<process_no; i++)
            burstBackup[i] = processes[i]->getBurstTime();

        resetWaitingTime();
        insertionSort(processes,process_no,2);
        maxCounter = getMaxArrivalTime() + getSumBurstTime();

        for(i=0; i<maxCounter; i++){
            index = getArivingProcesses(i);

            if(p != nullptr){
                p->setBurstTime(p->getBurstTime()-1);
            }

            if(index >= start) {
                for (j = start; j <= index; j++)
                    q.enqueue(processes[j], processes[j]->getPriority());
                start = index + 1;
            }

            if(p == nullptr || p->getBurstTime() == 0) {
                p = q.dequeue();
            }

            if(isPreemptive) {
                p1 = q.See_First();
                if (p1 != nullptr && p1->getPriority() < p->getPriority()) {
                    q.enqueue(p, p->getPriority());
                    p = q.dequeue();
                }
            }
            q.addWaitTime();
        }

        for(i=0; i<process_no; i++)
            processes[i]->setBurstTime(burstBackup[i]);

        Print_PS_waiting_time(isPreemptive, out);
    }

    void Print_PS_waiting_time(bool isPreemptive, ostream& out){
        int sum=0, wait;
        out << "Scheduling Method: Priority Scheduling ";
        if(isPreemptive)
            out << "- Preemptive\n";
        else
            out << "- Non-Preemptive\n";
        out << "Process Waiting Times:\n";
        for(int i=0;i<process_no;i++){
            wait = processes[i]->getWaitingTime();
            out << "P" << i+1 << ": " << wait << " ms\n";
            sum = sum+wait;
        }
        out << "Average Waiting Time: " << sum/(process_no*1.0) << " ms\n";
    }

    void RRS(int quantum, ostream& out){
        Queue<Process*> q;
        Process* p = nullptr;
        int i, maxCounter, index, j, start = 0, counter = 0, priority = 1;
        int burstBackup[process_no];

        for(i=0; i<process_no; i++)
            burstBackup[i] = processes[i]->getBurstTime();

        resetWaitingTime();
        insertionSort(processes,process_no,2);
        maxCounter = getMaxArrivalTime() + getSumBurstTime();

        for(i=0; i<maxCounter; i++){
            index = getArivingProcesses(i);

            if(index >= start) {
                for (j = start; j <= index; j++)
                    q.enqueue(processes[j], priority++);
                start = index + 1;
            }

            if(p != nullptr){
                p->setBurstTime(p->getBurstTime()-1);
                if(counter == quantum && p->getBurstTime() != 0) {
                    q.enqueue(p, process_no+priority++);
                }
            }

            if(p == nullptr || p->getBurstTime() == 0 || counter == quantum) {
                p = q.dequeue();
                counter = 0;
            }

            q.addWaitTime();
            counter++;
        }

        for(i=0; i<process_no; i++)
            processes[i]->setBurstTime(burstBackup[i]);

        Print_RRS_waiting_time(quantum, out);
    }

    void Print_RRS_waiting_time(int quantum, ostream& out){
        int sum=0, wait;
        out << "Scheduling Method: Round Robin Scheduling - time_quantum=" << quantum << endl;
        out << "Process Waiting Times:\n";
        for(int i=0;i<process_no;i++){
            wait = processes[i]->getWaitingTime();
            out << "P" << i+1 << ": " << wait << " ms\n";
            sum = sum+wait;
        }
        out << "Average Waiting Time: " << sum/(process_no*1.0) << " ms\n";
    }

    ~CPU_Sheduler(){
        int i;
        for(i=0; i<process_no; i++)
            delete processes[i];
        delete[] processes;
    }
};

#endif