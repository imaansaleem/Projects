#include <iostream>
#include <fstream>
#include <cstring>
#include "CPUScheduler.cpp"

using namespace std;

int Scheduler_Simulator(int scheduling_method, int mode);
int Scheduler = 0;
int Mode = 0;


int main(int argc, char* args[]) {
    fstream input, output;
    char filename[100];
    int quantum = 2;
    int arrival, burst, priority, count = 0;
    char e;
    bool isPreemptive = Mode == 1;
    CPU_Sheduler *scheduler;


    if(argc != 5) {
        cout << "Invalid Arguments. Terminating Program......" << endl;
        return 0;
    }

    //file opening
    if(!strcmp(args[1], "-f")){
        input.open(args[2], ios::in);
        strcpy(filename, args[2]);
    } else if( !strcmp(args[1], "-o" )){
        output.open(args[2], ios::out);
    } else {
        cout << "Invalid Arguments. Terminating Program......" << endl;
        return 0;
    }

    if(!strcmp(args[3], "-f")){
        input.open(args[4], ios::in);
        strcpy(filename, args[4]);
    } else if( !strcmp(args[3], "-o" )){
        output.open(args[4], ios::out);
    } else {
        cout << "Invalid Arguments. Terminating Program......" << endl;
        return 0;
    }

    if (input.fail()) { //if file does not open for certain reasons
        cout << "File cannot be open. Terminating Program......" << endl;
        return 0;
    }


    while (input >> burst) {
        input >> e;
        input >> arrival;
        input >> e;
        input >> priority;
        count++;
    }

    scheduler = new CPU_Sheduler(count);

    input.close();
    input.open(filename, ios::in);

    while (input >> burst) {
        input >> e;
        input >> arrival;
        input >> e;
        input >> priority;
        scheduler->Add_Process(burst, arrival, priority);
    }

    int option;
    do{
        option = Scheduler_Simulator(Scheduler,Mode);
        if (option == 1) {
            do { //sheduler method displayer
                cout << "\n\t\tScheduling Method\n";
                cout << "1) None\n";
                cout << "2) First Come, First Served Scheduling\n";
                cout << "3) Shortest-Job-First Scheduling\n";
                cout << "4) Priority Scheduling\n";
                cout << "5) Round-Robin Scheduling\n";
                cout << "Option > ";
                cin >> option;
                if (cin.fail() || option < 1 || option > 5) { //fail flag will be set when we give input other than integer.
                    cin.clear(); //clears buffer
                    cin.ignore(); //ignore input
                    cout << "\nInvalid Input:(\n";
                } else
                    break;
            } while (option < 1 || option > 5);
            Scheduler=option;
        }

        else if (option == 2) {
            do{
                cout << "Select a Preemptive Mode\n";
                cout << "0) OFF\n";
                cout << "1) ON\n";
                cout << "Option > ";
                cin >> option;
                if (cin.fail() || option < 0 || option > 1) { //fail flag will be set when we give input other than integer.
                    cin.clear(); //clears buffer
                    cin.ignore(); //ignore input
                    cout << "\nInvalid Input :(\n";
                } else
                    break;
            } while (option < 0 || option > 1);
            Mode=option;
        }
        else if(option == 3){
            if(Scheduler == 1){
                cout << "Select a Scheduling Method first.\n";
            } else if( Scheduler == 2 ){
                scheduler->FCFS(cout);
            } else if( Scheduler == 3 ){
                scheduler->SJF(isPreemptive, cout);
            } else if( Scheduler == 4 ){
                scheduler->PS(isPreemptive, cout);
            }  else if( Scheduler == 5 ) {
                do {
                    cout << "Enter the Time Quantum: ";
                    cin >> quantum;
                    if (cin.fail() || quantum <= 0) {
                        cin.clear();
                        cin.ignore();
                        cout << "\nInvalid Input :(\n";
                    }
                } while (quantum <= 0);
                scheduler->SJF(quantum, cout);
            }
        }
    }while(option!=4);

    scheduler->FCFS(cout);
    scheduler->FCFS(output);

    scheduler->SJF(false, cout);
    scheduler->SJF(false, output);
    scheduler->SJF(true, cout);
    scheduler->SJF(true, output);

    scheduler->PS(true, cout);
    scheduler->PS(true, output);
    scheduler->PS(false, cout);
    scheduler->PS(false, output);

    scheduler->RRS(quantum, cout);
    scheduler->RRS(quantum, output);

    output.close();

    delete scheduler;

    return 0;
}
int Scheduler_Simulator(int scheduling_method, int mode){ //Assigns particular sheduler and shows if mode is on or off
    string Method="None";
    string Mode="Off";
    if(scheduling_method==2)
        Method = "First Come, First Served Scheduling";
    else if(scheduling_method==3)
        Method = "Shortest-Job-First Scheduling";
    else if(scheduling_method == 4)
        Method = "Priority Scheduling";
    else if(scheduling_method == 5)
        Method = "Round-Robin Scheduling";

    if(mode == 1)
        Mode = "ON";
    else
        Mode = "OFF";

    int option;
    do{
        cout << "\n\t\t\tCPU Scheduler Simulator\n";
        cout << "1) Scheduling Method(" << Method << ")\n";
        cout << "2) Preemptive Mode (" << Mode << ")\n";
        cout << "3) Show Result\n";
        cout << "4) End Program\n";
        cout << "Option > ";
        cin >> option;
        if (cin.fail() || option < 1 || option > 4) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\nInvalid Input :(\n";
        }
        else
            break;
    }while(option < 1 || option > 4);
    return option;
}

