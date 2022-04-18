
#include<stdlib.h>
#include<stdio.h>

typedef enum State { Idle=0, UP, DOWN} State;
typedef struct Command {
	int currentFloor;
	State currentState;
	int data;
	struct Command *next;
} Command;




int takeFloors()
{
	Command *p;
	int totalFloors;
	//take number of floors available (1..99) in totalFloors
	printf("Enter the floor number from 1 to 99\n");	//print message
	scanf("%d", &totalFloors);//take input
	if(totalFloors >= 0 && totalFloors <= 99){
		printf("Enter Current Floor number\n"); scanf("%d", &(p->currentFloor));
        printf("Enter CurrentState\n"); scanf("%s", &(p->currentState));
        printf("Enter Commands\n"); scanf("%d", &(p->data));
		
	}
	else{
		printf("Floor Number doesn't exist\n");
		exit(0);

	}                          //validate the input (1..99)
	//retake input if required.
	return 0;
}


int printDetails()
{
	//print current floor number, current state, list of (current and pending) commands.
	
	Command *p;
	Command *head;
	p = head;
	while(p != NULL)
	{
		printf("Floor: %d,  State:%s,  Commands:%d\n", p->currentFloor, p->currentState, p->data);
		p = p->next;
	}
	//e.g.
	//floor: 0, state: up, commands: 203, 105, 7, 100

	return 0;
}

int takecommands()
{
	//print how many commands you want to provide

	Command *head = NULL;
	Command *p = NULL;
	int n = 0, total =0;

	printf("how many commands you want: "); scanf("%d", &n);
	total = n;

	//or
	//4 203 105 7 100 => first number will tell how many commands we should read. 

	//take all inputs in the list. 
	//hint: link list initial filling logic
	return 0;
}

int processcommand()
{
	//take the first node (take value of head, change head)
	//command = head->data

	//targetfloor = (take target floor from command)

	//if current floor != target floor
		// change floor by one. 
		//change state respectively
	//else
		//change state to idle
		//remove current command. it is done. //head = head ->next, but make sure you free up memory. 

	//print the current state. by calling printdetails()
	return 0;
}


int main()
{
	takefloors();	//take number of floors available (0..99) in totalfloors

	printdetails();

	while(1)
	{
		//if no pending commands, ask for it
			takecommands();
		//else do nothing here. 

		//process the current command
		processcommand();
	}

	return 0;
}
