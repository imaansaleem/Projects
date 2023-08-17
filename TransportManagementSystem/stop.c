#ifndef STOP
#define STOP

struct stop{
    char name[50];
    float location;
    float latitude;
    float longitude;
    float cost;
    float duration;
    int number_of_careers;
    struct stop* next;
};


#endif