#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "../include/Customer.h"
#include "../include/Room.h"
#include "../include/HotelManager.h"
#include "../include/Sql.h"

using namespace std;

int main()
{
	sql sql;
	if(sql.conn) 
	{
		HotelManager hm;
		hm.MainMenu();
	}
	else cout << "Not Connected";
	return 0;
}
