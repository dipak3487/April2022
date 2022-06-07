#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

//#include <windows.h>
#include "Customer.h"

using namespace std;

class Room
{
    private:
    string roomtype;
    string comfort;
    string capacity;
    int status;
    int rent_per_day;
    
    public:
    Room() {};
    Room(string rt,string c,string ct,int s,int rent);
    ~Room() {};
    Customer cust;
    int TotalRoomCount();
    void addRoom(int);
    void searchRoom(int);
    void modifyRoom(int);
    void displayRoom(int);
};

#endif // ROOM_H_INCLUDED

