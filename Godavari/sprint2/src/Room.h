#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED


#include "Customer.h"

using namespace std;

class Room
{
    public:
    string RoomType;
    string Comfort;
    string Capacity;
    int Status;
    int Rent_Per_Day;

    Customer cust;
    void AddRoom(int);
    void  SearchRoom(int);
    void   ModifyRoom(int);
    void   DisplayRoom(int);
};

#endif 

