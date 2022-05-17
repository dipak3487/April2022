#include<iostream>
#include <vector>
#include<string>

class Menu
{
	private:
	std::vector<std::string> menuList;
	std::vector<void(*)()> menuOptions;

	int choice;


	public:
	void displayOptions()
	{
		for(int i=0; i<menuList.size() -1; i++)
		{
			std::cout << i << ". " << menuList[i] << std::endl;
		}
	}
	
	void selectOption()
	{
		choice = -1;
		do
		{
			std::cout << "Enter you choice [0-" << menuList.size() -1 << "]: ";
			std::cin >> choice;
		}while(choice < 0 || choice >= menuList.size());
	}


	void addOption(std::string name, void (*fptr)())
	{
		menuList.push_back(name);
		menuOptions.push_back(fptr);
	};

	int getChoice()
	{
		return choice;
	}

	void executeOption()
	{
		//call the right function for the choice user made. 
		menuOptions[choice]();
	}
};

class Parking
{
	std::vector<std::string> slots;
	int parkedVehicles;
	int totalVehiclesServed;

	public:
	Parking() : parkedVehicles(0), totalVehiclesServed(0) {
		for(int i=0; i<20; i++) slots.push_back("");
		}
	void showAvailability(){
		if(parkedVehicles < slots.size() )
		{
			std::cout << "Available" << std::endl;
		}
		else
		{
			std::cout << "FULL" << std::endl;
		}
	}
	void entryParking() {
		int index = -1;
		for(int i=0 ; i< slots.size(); i++)
        {
            if(slots[i].length() < 1) //vaccant
                std::cout << i << "\t";
            else
                std::cout << "X\t";

            if((i+1)%5 == 0) std::cout << std::endl;
        }

		std::cout << "Which slot you would like to use: ";
		std::cin >> index;
		bookSlot(index);


	}
	void bookSlot(int index)
	{
		slots[index] = "MH12AB223";
		parkedVehicles++;
	}
	void exitParking() {
		int index = -1;
		for(int i=0 ; i< slots.size(); i++)
		{
			if(slots[i].length() > 1) //vehicle present. 
			{
				std::cout << i << ". " << slots[i] << std::endl;
			}
		}

		std::cout << "Where is your vehicle : ";
		std::cin >> index;

		slots[index] = "";
		parkedVehicles--;
		totalVehiclesServed++;
	}
	void showTotalCollection() {
		std::cout << "Total " << totalVehiclesServed *10 << " rupees collected so far." << std::endl;
	}
	void showTotalVehiclesServed() {
		std::cout << "Total " << totalVehiclesServed << " vehicles served so far." << std::endl;
	}
};

Parking p;

void Parking_showAvailability()
{
	p.showAvailability();
}

void Parking_entryParking()
{
	p.entryParking();
}

void Parking_exitParking()
{
	p.exitParking();
}
void Parking_showTotalCollection()
{
	p.showTotalCollection();
}

void Parking_showTotalVehiclesServed()
{
	p.showTotalVehiclesServed();
}

void Parking_exit()
{
	exit(0);
}

int main()
{
	Menu m;
	m.addOption("Show Availability", Parking_showAvailability);
	m.addOption("Entry", Parking_entryParking);
	m.addOption("Exit", Parking_exitParking);
	m.addOption("Total collection", Parking_showTotalCollection);
	m.addOption("Total vehicles served", Parking_showTotalVehiclesServed);
	m.addOption("Exit", Parking_exit);

	while(true)
	{
		m.displayOptions();
		m.selectOption();
		m.executeOption();
	}

	return 0;
}

