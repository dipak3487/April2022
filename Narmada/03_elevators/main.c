#include<stdio.h>
#include <stdlib.h>

typedef enum State { Idle=0, UP, DOWN} State;
char strState [3][5] = { "Idle", "UP", "DOWN" };

typedef struct Command {
	int data;
	struct Command *next;
} Command;

int currentFloor;
int totalFloors;
State currentState;
Command *head;

int takeFloors()
{
	totalFloors = 0;
	while(totalFloors < 1 || totalFloors > 99)
	{
		printf("How tall is your building (1-99): "); 
		scanf("%d", &totalFloors);
	}
	return 0;
}


int printDetails()
{
	Command *p;
	//print current floor number, current state, list of (current and pending) commands.
	//e.g.
	//Floor: 0, State: UP, Commands: 203, 105, 7, 100
	//currentFloor, currentState, head
	printf("\t[%d]-[%s]:\t[ ", currentFloor, strState[currentState]);

	p = head;
	while(p != NULL)
	{
		printf("%03d ",  p->data);
		p = p->next;
	}
	printf("]\n");

	return 0;
}

int takeCommand()
{
	int c = -1;

	while(c < 0 || c/100 > 2 || c%100 > totalFloors)
	{
		if( -1 != c) printf("Valid range: [0-%d, 100-%d, 200-%d]. \n", totalFloors, 100+totalFloors, 200+totalFloors);
		scanf("%d", &c);
	}
	return c;
}

int takeCommands()
{
	int N = 0;
	Command *p;

	//print how many commands you want to provide
	//OR
	//4 203 105 7 100 => first number will tell how many commands we should read. 
	printf("Commands for elevator (-1 to exit) : ");
	scanf("%d", &N);

	if(N<1) exit(EXIT_SUCCESS);

	head = malloc(sizeof(Command) );
	head->next = NULL;
	//scanf("%d", &(head->data));	//TODO: Validation 
	head->data = takeCommand();
	p = head;

	while(N > 1)
	{

		p->next = malloc(sizeof(Command) );
		p = p->next;
		p->next = NULL;
		//scanf("%d", &(p->data));
		p->data = takeCommand();
		N--;
	}

	return 0;
}

int processCommand()
{
	int command = 0;
	int targetFloor = 0;
	Command *p = NULL;


	//take the first node (take value of head, change head)
	//command = head->data
	command = head->data;

	//targetFloor = (take target floor from command)
	targetFloor = command%100;

	//if current floor != target floor
		// change floor by one. 
		//change state respectively
	//else
		//change state to idle
		//remove current command. It is done. //head = head ->next, but make sure you free up memory. 

	if(currentFloor < targetFloor)
	{
		//elevator should go UP.
		currentFloor++;
		currentState = UP;
	}
	else if(currentFloor > targetFloor)
	{
		currentFloor--;
		currentState = DOWN;
	}
	else
	{
		currentState = Idle;
		
		p = head;
		head = head->next;
		p->next = NULL;
		free(p);
		p = NULL;

	}

	//we know:
	//		- the current floor
	//		- the direction of the elevator
	//		- pending commands
	//We can decide the state. depending on the current direction and pending commands.

	//if state == UP && pending commands contain 100+currentFloor, 
        //      Change the state to idle
        //      remove the [100+currentFloor] node
        //      sleep(1)
        //      printDetails();
        //      Change the state back to UP
	//if state == DOWN && pending commands contain 200+currentFloor, do the same thing. 
	//if pending commands contain currentfloor   ==> someone from elevator want to go out on the current floor.
	//idle. let the person from the elevator go out. 
	// continue in same direction.  
	//searchNode(int data)	// 0 or N, if found N times, return N, if not found, return 0
	//deleteNode(int N)	//delete all nodes which contains data == N
	//
	printDetails();

	//print the current state. by calling printDetails()
	return 0;
}


int main()
{
	takeFloors();	//take number of floors available (0..99) in totalFloors

	printDetails();

	while(1)
	{
		//if no pending commands, ask for it
		if(NULL == head)
		{
			takeCommands();
		}
		else
		{
			//else do nothing here. 
		}

		//process the current command
		processCommand();
		sleep(1);
	}

	return 0;
}

