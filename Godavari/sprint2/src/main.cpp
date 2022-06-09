#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <mysql/mysql.h>
#include "Customer.h"
#include "Room.h"
#include "HotelManager.h"
#include "Sql.h"

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
