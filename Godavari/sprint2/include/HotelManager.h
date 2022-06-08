#ifndef HotelManager_H_INCLUDED
#define HotelManager_H_INCLUDED


#include "Room.h"

using namespace std;

class HotelManager: protected Room{
    public:
    bool CheckIn();
    bool CheckOut(int);
    bool GetAvailableRooms();
    bool SearchCustomer();
    bool MainMenu();
    bool ManageRooms();
};

#endif // HotelManager_H_INCLUDED

