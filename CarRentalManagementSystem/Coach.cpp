#ifndef COACH
#define COACH
#include "Vehicle.cpp"
#include <cstring>
#include <iostream>

using namespace std;

class Coach: public Vehicle{
    static inline int  rate_per_km;
    static inline int count_of_Coaches;
public:
    Coach(string number_plate, string color, string driver_name, string type_of_vehicle, int model_no, int seating_capacity, bool is_Booked, int rate_per_km):Vehicle(number_plate, color, driver_name, type_of_vehicle, model_no, seating_capacity, is_Booked){
        count_of_Coaches++;
        this->rate_per_km=rate_per_km;
    }

    void writeInFile(ostream& out){ // function overriding
        Vehicle::writeInFile(out);
        out << ',' << rate_per_km;
        out << ',' << count_of_Coaches;
        out << ',' << endl;
    }

    static int getRate(){
        return rate_per_km;
    }

    static void Change_Rates(int rate){
        rate_per_km=rate;
    }
};
#endif