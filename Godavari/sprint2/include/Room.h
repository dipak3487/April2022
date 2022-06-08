#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

//#include <windows.h>
#include "Customer.h"

using namespace std;

class Room
{
    private:
    string RoomType;
    string Comfort;
    string Capacity;
    int Status;
    int RentPerDay;
    
    public:
    Room() {};
    Room(string rt,string c,string ct,int s,int rent);
    ~Room() {};
    Customer cust;
    bool AddRoom(int);
    bool SearchRoom(int);
    bool ModifyRoom(int);
    bool DisplayRoom(int);
    string getType();
    string getComfort();
    string getCapacity();
    int getStatus();
    int getRent();
    int getAvailableRoomsCount();

};

#endif // ROOM_H_INCLUDED




