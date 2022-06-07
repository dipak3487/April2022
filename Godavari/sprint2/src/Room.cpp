#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "../include/HotelManager.h"
#include "../include/Room.h"
#include "../include/Customer.h"
#include "../include/Sql.h"

using namespace std;

Room::Room(string rt,string c,string ct,int s,int rent)
{
 RoomType = rt;
 Comfort = c;
 Capacity = ct;
 Status= s;
 Rent_Per_Day=rent;
}


void Room::AddRoom(int RoomNumber){
    sql sql;
    Room room;
    cout << "\n***********";
    cout << "\n(Deluxe Suite->D)\n(Non-Deluxe Suite->N)\n(Presidential Suite->P)\n";
    cout << "*********";
    cout << "\nEnter the code for room type:";
    cin >> room.RoomType;

    cout << "\n***********";
    cout << "\n(AC->A)\n(Non-AC->N)";
    cout << "\n***********";
    cout << "\nEnter the code for room Comfort:";
    cin >> room.Comfort;

    cout << "\n***********";
    cout << "\n(Single->S)\n(Double->D)";
    cout << "\n***********";
    cout << "\nEnter the code for room Capacity:";
    cin >> room.Capacity;

    cout << "\nEnter the rent per day:";
    cin >> room.Rent_Per_Day;

    cout << "\n***********";
    cout << "\n(Available->0)\n(None-Available->1)";
    cout << "\n***********";
    cout << "\nEnter the Status:";
    cin >> room.Status;

    stringstream ss;
    ss << "INSERT INTO rooms(RoomNumber, Type, Comfort, Capacity, Status, Rent_Per_Day) VALUES('"<< RoomNumber <<"','"<< room.RoomType <<"','"<< room.Comfort <<"','"<< room.Capacity <<"','"<< room.Status <<"','"<< room.Rent_Per_Day <<"')";
    if(sql.query_check(ss, sql)){
        cout << "\nRoom Added Successfully!";
        cout << "\nPress any key to display room:";
        cin.ignore();
        cin.get();
          DisplayRoom(RoomNumber);
    }
    else{
        cout << "\nQuery Execution Failed!";
    }
    cout << "\nPress any key to continue:";
    cin.get();
    HotelManager hm;
    hm.ManageRooms();
}

int Room :: TotalRoomCount()
 {
    sql sql;
     int count=0;
   // Room room ;
        stringstream ss;
        ss << "SELECT COUNT(*) FROM rooms" ;
        bool qstate = sql.query_check(ss, sql);
        if(qstate) {
             sql.res= mysql_store_result(sql.conn);
             count = mysql_num_rows(sql.res);
             // cout<<count;                   
            }
            
        return count;
}

void Room::  DisplayRoom(int RoomNumber){
    sql sql;
    HotelManager hm;
    cout << "\n***********\n";

            stringstream ss;
            ss << "SELECT * FROM rooms WHERE RoomNumber = '"<< RoomNumber <<"'";
            bool qstate = sql.query_check(ss, sql);
            if(qstate) {
                sql.res= mysql_store_result(sql.conn);
                sql.row = mysql_fetch_row(sql.res);
                if(sql.row) {
                    cout << "Details of Roomnumber " << sql.row[0] << " : \n";
                    cout << "Room type: " << sql.row[1] << "\n";
                    cout << "Room Comfort: " << sql.row[2] << "\n";
                    cout << "Room Capacity: " << sql.row[3] << "\n";
                    cout << "Room Status: " << sql.row[4] << "\n";
                    cout << "Rent per day: " << sql.row[5] << "\n";
                    //cout << "Number of Days: " << sql.row[6] << "\n";
                }
                else cout << "\nNo record found!!";
            }
            else{
                cout << "\nQuery Execution Failed";
                cout << "Press any key to go back to manage rooms";
                cin.ignore();
                cin.get();
                hm.ManageRooms();
            }
}


void Room::  ModifyRoom(int RoomNumber){
    int opt, index;
    sql sql;
    HotelManager hm;
    string newc;
    stringstream ss;
        cout << "\n***********";
        cout << "\nWhat would you want to modify?";
        cout << "\nRoom Type - Press 1\nRoom Comfort - Press 2\nRoom Capacity - Press 3\nRent per day - Press 4\nFinish - Press 5\n";
        cout << "*********";
        cin >> opt;

    if (opt == 1){
            index = 1;
            cout << "\n***********";
            cout << "\n(Deluxe Suite->D)\n(Non-Deluxe Suite->N)\n(Presidential Suite->P)\n";
            cout << "*********";
            cout << "\nEnter the code for new room type:";
            cin >> newc;
            ss << "UPDATE rooms SET Type = '"<< newc <<"' WHERE RoomNumber = '"<< RoomNumber <<"'";
    }
        else if (opt == 2){
            index = 2;
            cout << "\n***********";
            cout << "\n(AC->A)\n(Non-AC->N)";
            cout << "*********";
            cout << "\nEnter the code for new room Comfort:";
            cin >> newc;
            ss << "UPDATE rooms SET Comfort = '"<< newc <<"' WHERE RoomNumber = '"<< RoomNumber <<"'";
        }
        else if (opt == 3){
            index = 3;
            cout << "\n***********";
            cout << "\n(Single->S)\n(Double->D)";
            cout << "*********";
            cout << "\nEnter the code for new  room Capacity:";
            cin >> newc;
            ss << "UPDATE rooms SET Capacity = '"<< newc <<"' WHERE RoomNumber = '"<< RoomNumber <<"'";
        }
        else if(opt == 4){
            index = 5;
            cout << "\nEnter new rent per day: ";
            cin >> newc;
            ss << "UPDATE rooms SET Rent_Per_Day = '"<< newc <<"' WHERE RoomNumber = '"<< RoomNumber <<"'";
        }
        else if(opt == 5){
            hm.ManageRooms();
        }
        else{
               cout << "\nInvalid Input";
            cout << "\nPress any key to continue:";
            cin.ignore();
            cin.get();
              ModifyRoom(RoomNumber);
        }

        if(sql.query_check(ss, sql)) {
            cout << "Successfully Modified";
        }
        else{
            cout << "\nFailed to Modify";
            cout << "\nPress any key to continue:";
            cin.ignore();
            cin.get();
            hm.ManageRooms();
        }

    cout << "\nPress any key to continue: ";
    cin.ignore();
    cin.get();
    hm.MainMenu();
}


void Room:: SearchRoom(int RoomNumber){
    sql sql;
    HotelManager hm;

        stringstream ss;
        ss << "SELECT * FROM rooms WHERE RoomNumber = '"<< RoomNumber <<"'";
        bool qstate = sql.query_check(ss, sql);
        if(qstate) {
            sql.res= mysql_store_result(sql.conn);
            sql.row = mysql_fetch_row(sql.res);
            if(sql.row) {
                  DisplayRoom(RoomNumber);
                  ModifyRoom(RoomNumber);
            }
            else cout << "\nNo record found!!";
        }
        else{
            cout << "\nQuery Execution Failed!";
        }
        cout << "\nPress any key to continue:";
        cin.ignore();
        cin.get();
        hm.ManageRooms();
}

