#include<iostream>
#include <vector>

class vehicle
{
	public:
	bool engineState;
	int speed;
	void startEngine() { engineState = true; }
	void stopEngine() { engineState = false; }
	void virtual accelerate() { speed++; }
	void applyBrake() { if(speed > 0) speed--; }
	void virtual display()    
	{ 
		std::cout << "Not implemented" << std::endl;

		if(this->engineState) 
		{
			std::cout << "Engine On, Speed: " << this->speed << std::endl;
		}
		else
		{
			std::cout << "Engine is off." << std::endl;
		}
	}
	vehicle() : engineState(false), speed(0) {}
	~vehicle(){};
};

class Menu
{
	private:
	std::vector<std::string> menuList;
	std::vector<void(*)(vehicle *)> menuOptions;


	int choice;


	public:
	void displayOptions()
	{
		for(int i=0; i<menuList.size(); i++)
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


	void addOption(std::string name, void (*fptr)(vehicle *vp))
	{
		menuList.push_back(name);
		menuOptions.push_back(fptr);
	};

	int getChoice()
	{
		return choice;
	}

	void executeOption(vehicle *vp)
	{
		//call the right function for the choice user made. 
		menuOptions[choice](vp);
	}
};

class Car : public vehicle
{
public:
	void accelerate() {	if(speed < 80) speed++;	}
};

class Bike : public vehicle
{
	public:
	void accelerate() {	if(speed < 60) speed++;	}
};

class HV : public vehicle
{
	public:
	void accelerate() {	if(speed < 40) speed++;	}
};

void createCarObject(vehicle *vp) { vp = new Car; }
void createBikeObject(vehicle *vp) { vp = new Bike; }
void createHVObject(vehicle *vp) { vp = new HV; }

void selectVehicle(vehicle *vp)
{

	if(NULL == vp)
	{
		Menu m1;
		m1.addOption("Car", createCarObject);
		m1.addOption("Bike", createBikeObject);
		m1.addOption("Heavy Vehicle", createHVObject);

		m1.displayOptions();
		m1.selectOption();
		m1.executeOption(vp);
	}
	else
	{
		std::cout << "The object is already created." << std::endl;
	}

}

void startVehicle(vehicle *vp)
{
	std::cout << "startVehicle() NOT IMPLEMENTED!" << std::endl;
}

void stopVehicle(vehicle *vp)
{
	std::cout << "stopVehicle() NOT IMPLEMENTED!" << std::endl;
}

void execAccelerate(vehicle *vp)
{
	vp->accelerate();
	//std::cout << "accelerate() NOT IMPLEMENTED!" << std::endl;
}

void applyBrake(vehicle *vp)
{
	std::cout << "applyBrake() NOT IMPLEMENTED!" << std::endl;
}

void displayInfo(vehicle *vp)
{
	vp->display();
}

void exitProgram(vehicle *vp)
{
	std::cout << "Thats all folks! visit again!" << std::endl;
	exit(0);
}

int main()
{
	Menu m;
	vehicle *pv = NULL;

	m.addOption("SelectVehicle", selectVehicle);
	m.addOption("Start", startVehicle);
	m.addOption("Stop", stopVehicle);
	m.addOption("Accelerate", execAccelerate);
	m.addOption("Apply Brake", applyBrake);
	m.addOption("Display information", displayInfo);
	m.addOption("Exit", exitProgram);

	while(true)
	{
		m.displayOptions();
		m.selectOption();
		m.executeOption(pv);
	}

	return 0;
}

