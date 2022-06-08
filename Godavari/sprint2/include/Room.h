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
    int Rent_Per_Day;
    
    public:
    Room() {};
    Room(string rt,string c,string ct,int s,int rent);
    ~Room() {};
    Customer cust;
    int TotalRoomCount();
    bool AddRoom(int);
    void SearchRoom(int);
    void  ModifyRoom(int);
    void  DisplayRoom(int);
};

#endif // ROOM_H_INCLUDED




