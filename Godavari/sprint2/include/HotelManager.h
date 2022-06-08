#ifndef HotelManager_H_INCLUDED
#define HotelManager_H_INCLUDED

//#include <windows.h>
#include "Room.h"

using namespace std;

class HotelManager: protected Room{
    public:
    void CheckIn();
    void CheckOut(int);
    void GetAvailableRooms();
    void SearchCustomer();
    void MainMenu();
    void ManageRooms();
};

#endif // HotelManager_H_INCLUDED

