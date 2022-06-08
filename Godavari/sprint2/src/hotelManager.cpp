#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<mysql/mysql.h>

#include "Customer.h"
#include "Room.h"
#include "HotelManager.h"
#include "Sql.h"




using namespace std;

//This function manageroom details like add rooms in the system,modify their details.we can add RoomType,Comfort,Capacity,Status,Rent_Per_Day in the room table

bool HotelManager::ManageRooms(){
    Room room;
    int Menu, RoomNumber;
    HotelManager hm;
    sql sql;

        cout << "\n***********";
        cout<<"\n### Manage Rooms ###";
        cout<<"\n1.Add Room\n2.Modify Room\n3.Back to main Menu: ";
        cout << "\n***********";
        cout << "\n\nEnter Option: ";
        cin >> Menu;
        if(Menu == 1){
            cout << "\nEnter Room Number:";
            cin >> RoomNumber;

            stringstream s1;                                                            //to store the query
            s1 << "SELECT * FROM rooms WHERE RoomNumber = '"<< RoomNumber <<"'";
            bool qstate = sql.query_check(s1, sql);                                   //cheack query and execute query
            if(qstate) {
                sql.res= mysql_store_result(sql.conn);                                 // store result set
                sql.row = mysql_fetch_row(sql.res);                                  // fetch result one by one
                if(sql.row) cout << "\nRoom Already Present!";
                else room.AddRoom(RoomNumber);
            }
            else cout << "\nQuery Execution Failed!";
        }
        else if(Menu==2){
            cout << "\nEnter Room Number:";
            cin >> RoomNumber;
            room. SearchRoom(RoomNumber);
        }
        else if(Menu==3){
            hm.MainMenu();
        }
        else {
            cout << "*********";
            cout << "\nInvalid input!";
            cout << "*********";
        }
        cout << "\nPress any key to continue:";
        cin.ignore();
        cin.get();
        hm.ManageRooms();
        return true;
}

//This function add check-in details in the system.

bool HotelManager::CheckIn(){
    sql sql;
    int RoomNumber, Again;
    
    cout << "Enter Room Number: ";
    cin >> RoomNumber;
    stringstream s1, s2, s3;
    s1 << "SELECT Status FROM rooms WHERE RoomNumber = '"<< RoomNumber <<"'";
    bool qstate = sql.query_check(s1, sql);
    if(qstate) {
        sql.res= mysql_store_result(sql.conn);
        sql.row = mysql_fetch_row(sql.res);
        if(sql.row) {
            int Status = atoi(sql.row[0]);
            if(Status != 0) {
                cout << "\nRoom is already booked.";
                cout << "\nPress any key to continue:";
                cin.ignore();
                cin.get();
                cout << "\nPress 1 to go back to main Menu\nPress 2 to enter another room no.";
                cin >> Again;
                if(Again==1)MainMenu();
                if(Again==2)CheckIn();
                else cout << "\nInvalid input!";
            }
            else {
                cout<<"\nEnter Customer Name (First Name): ";
                cin>>cust.FirstName;
                cout<<"\nEnter Customer Name (Last Name): ";
                cin>>cust.LastName;
                cout<<"\nEnter Address (only city): ";
                cin>>cust.Address;
                cout<<"\nEnter Phone Number(10 digits): ";
                cin >> cust.Phone;
                cout<<"\nEnter Number of Days: ";
                cin >> cust.Num_of_Days;

                s2 << "INSERT INTO guests(RoomNumber, FirstName, LastName, Address, PhoneNumber,NumOfDays) VALUES('"<< RoomNumber <<"','"<< cust.FirstName <<"','"<< cust.LastName <<"','"<< cust.Address <<"','"<< cust.Phone <<"','"<< cust.Num_of_Days <<"')";
                bool q2state = sql.query_check(s2, sql);
                if(q2state) {
                    Status = 1;
                    s3 << "UPDATE rooms SET Status = '"<< Status <<"' WHERE RoomNumber = '"<< RoomNumber <<"'";
                    bool q3state = sql.query_check(s3, sql);
                    if(q3state) {
                            cout << "\nCustomer CheckedIn Successfully!";
                    }
                    else cout << "\nRoomStatus not modified!";
                }
                else cout << "\nCheckIn UnSuccessful!";
            }
        }
        else cout << "\nRoom Not Found\n";
    }
    else {
        cout << "Query Execution Failed\n";
    }
    cout << "\nPress any key to continue:";
    cin.ignore();
    cin.get();
    MainMenu();
    return true;
}

//This function used for CheckOut of the Customer
bool HotelManager::CheckOut(int RoomNumber){
    sql sql;
    int Bill;
    int Num_of_Days;
    stringstream s1, s2, s3, s4;
    s1 << "SELECT Status, Rent_Per_Day FROM rooms WHERE RoomNumber = '"<< RoomNumber <<"'";
    bool qstate = sql.query_check(s1, sql);
    if(qstate){
        sql.res= mysql_store_result(sql.conn);
        sql.row = mysql_fetch_row(sql.res);
        if(sql.row) {
            int Status = atoi(sql.row[0]);
            int rent = atoi(sql.row[1]);
            if(Status == 0) {
                cout << "\nRoom is empty.";
            }
            else {
                cout<<"\nEnter Room Number was booked for: ";
                cin>>Num_of_Days;
                Bill = Num_of_Days*rent;
               
                
                  
                    
                        Status = 0;
                        s4 << "UPDATE rooms SET Status = '"<< Status <<"' WHERE RoomNumber = '"<< RoomNumber <<"'";
                        bool q4state = sql.query_check(s4, sql);
                        if(q4state) {
                            cout << "\nCheckOut Successful!";
                            cout << "\n Bill := "<<Bill;
                            }
                        else{
                             cout << "\nRoom Status Not Modified!";
                        }
                    
                
            }
        }
        else cout << "\nRoom not found";
    }
    else cout << "\nQuery Execution Failed";

    cout << "\nPress any key to continue:";
    cin.ignore();
    cin.get();
    MainMenu();
    return true;
}

//This function check whether room available or not for allocating to the Customer
bool HotelManager::GetAvailableRooms(){
    sql sql;
    int Status = 0;
    stringstream s1;
    s1 << "SELECT RoomNumber FROM rooms WHERE Status = '"<< Status <<"'";
    bool qstate = sql.query_check(s1, sql);
    if(qstate) {
        sql.res= mysql_store_result(sql.conn);
        sql.row = mysql_fetch_row(sql.res);
        if(sql.row) {
            cout << "Room numbers of available rooms are: ";
            cout << sql.row[0] << ", ";

            while ((sql.row = mysql_fetch_row(sql.res)))
            cout << sql.row[0] << ", ";
        }
        else cout << "\nALL rooms are reserved.";
    }
    else cout << "\nQuery Not Executed";
    cout << "\nPress any key to continue:";
    cin.ignore();
    cin.get();
    //CheckIn();
   MainMenu();
   return true;
}

//This function search the Customer detail with their allocated room number
bool HotelManager::SearchCustomer(){

    sql sql;
    string FName;
    string LName;
    cout << "\nEnter first name of the Customer:";
    cin >> FName;
    cout << "\nEnter last name of the Customer:";
    cin >> LName;

    stringstream ss;
    ss << "SELECT * FROM guests WHERE FirstName = '"<< FName << "' and LastName like '"<< LName << "'";
    bool qstate = sql.query_check(ss, sql);
    if(qstate) {
        sql.res= mysql_store_result(sql.conn);
        int flag = 0;
        cout << "\nCurrent Guest list:-\n";
        cout << "-----------------------\n";
        while ((sql.row = mysql_fetch_row(sql.res))) {
            cout << "Room Number: " << sql.row[0] << endl;
            cout << "FirstName: " << sql.row[1] << endl;
            cout << "LastName: " << sql.row[2] << endl;
            cout << "Address: " << sql.row[3] << endl;
            cout << "Phone Number: " << sql.row[4] << endl;
            cout << "Number of days of stay: " << sql.row[5] << endl;
            cout << "-----------------------\n";
            flag = 1;
        }
        if(flag == 0)
            cout << "No Such Customer" << endl;
        cout << "***********************\n";
    }
    else{
        cout << "Query not executed"<< endl;
    }

    MainMenu();
    return true;
}

pthread_t pthread1;
int change=0;

void* userPreferenceThread(void *arg) {
    char *input = (char *)arg;
      //  cout<<"Started: %s\n"<< input;

    while(true) {

                //if /tmp/nice file exists
        if (access("/tmp/nice", F_OK) == 0)
        {
                        // HotelManager::SetUserPreference(1); //nice Menu
                   change = 1;
 }
        else
        {
           // HotelManager::SetUserPreference(0); //normal Menu
                        change = 0;
        }

        sleep(1);
    }
    //pthread_exit(arg);
    return arg;
}

void createUserPreferenceThread() {
   const char *thread_input1 = " ";
    pthread_attr_t attr;
    pthread_attr_init(&attr);
     pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    int rc = pthread_create(&pthread1, &attr, userPreferenceThread, (void *)thread_input1);
    //int rc = pthread_create(&pthread1, NULL, userPreferenceThread, (void *)thread_input1);
    if(rc != 0) {
        printf("Error occurred, thread could not be created, errno = %d\n", rc);
        exit(0);
    }
}


bool HotelManager::MainMenu(){
    HotelManager hm;
    createUserPreferenceThread();
   // cout<<"user preference:"<<change;
    if(change==0)
  {
    cout << "\n\t\t Welcome to Hotel Management System\n" << endl;
    int Menu;
    int RoomNumber;
    cout << "**********************************************************";
    cout << "\n\t1.Manage Rooms"<< endl << "\t2.Check-In Room" << endl << "\t3.Check-out Room" << endl << "\t4.Search Customer" << endl << "\t5.Available Rooms" << endl << "\t6.Exit";
    cout << "\n*********************************************************";
    cout << "\nEnter the corresponding no. to go the Menu:";
    cin >> Menu;
    switch(Menu){
        case 1:
           hm.ManageRooms();
           break;
         case 2:
            hm.CheckIn();
            break;
         case 3:
            cout << "\nEnter Room Number:";
            cin >> RoomNumber;
            hm.CheckOut(RoomNumber);
            break;
        case 4:
                hm.SearchCustomer();
            break;
        case 5:
                hm.GetAvailableRooms();
            break;
        case 6:
            cout<<"\nTHANK YOU FOR USING THIS SOFTWARE";
            break;
        default:
            cout << "\nInvalid input.";
            cout << "\nEnter the correct option:";
    }
}

else
{
cout << "\n\t\tWelcome to Hotel Management System\n" << endl;
    int Menu;
    int RoomNumber;
    cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*";
    cout << "\n\t\t1.Manage Rooms"<< endl <<"\t\t2.Check-In Room" << endl << "\t\t3.Check-out Room" << endl << "\t\t4.Search Customer" << endl << "\t\t5.Available Rooms" << endl << "\t\t6.Exit";
    cout << "\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*";
    cout << "\nEnter the corresponding no. to go the Menu:";
    cin >> Menu;
    switch(Menu){
        case 1:
           hm.ManageRooms();
           break;
         case 2:
 hm.CheckIn();
            break;
         case 3:
            cout << "\nEnter Room Number:";
            cin >> RoomNumber;
            hm.CheckOut(RoomNumber);
            break;
        case 4:
                hm.SearchCustomer();
            break;
        case 5:
                hm.GetAvailableRooms();
            break;
        case 6:
            cout<<"\nTHANK YOU FOR USING THIS SOFTWARE";
            break;
        default:
            cout << "\nInvalid input.";
            cout << "\nEnter the correct option:";
    }

}
return true;
}

