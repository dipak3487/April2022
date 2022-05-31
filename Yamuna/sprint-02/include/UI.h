#ifndef __UI_H
#define __UI_H

#include "Bus.h"

typedef enum Menu { ADD_BUS=1, RESERVE_SEAT, SHOW_RESERVATION, SHOW_AVAILABILITY, CANCEL_RESERVATION, EXIT} Menu;

class UI
{
	private:
    static int const MinMenu = 1;
	static int const MaxMenu = 6;

	public:
	static bool DisplayMainMenu();
	static int GetMenuChoice();

	static Bus& add_new_number_of_bus();
	static bool avail();
	
    



};

#endif
