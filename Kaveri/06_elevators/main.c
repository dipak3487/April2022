#include<stdio.h>
#include<stdlib.h>
typedef enum State { Idle=0, UP, DOWN} State;
typedef struct Command {
	int data;
	struct Command *next;
} Command;

int currentFloor;
int totalFloors;
State currentState;

int takeFloors()
{
	//take number of floors available (1..99) in totalFloors
	//print message
	//take input
	//validate the input (1..99)
	//retake input if required.
	return 0;
}


int printDetails()
{
	//print current floor number, current state, list of (current and pending) commands.
	//e.g.
	//Floor: 0, State: UP, Commands: 203, 105, 7, 100

	return 0;
}

int takeCommands()
{
	Command *head = NULL;
    Command *p = NULL;
    Command *newNode = NULL;
    int N = 0, total=0;

    printf("How many commands  you want: "); scanf("%d", &N);
    total = N;

    head = malloc(sizeof(Command) );
    head->next = NULL;
    scanf("%d",&(p->data)); // takeData(head);
    p = head;

    while(N > 1)
    {

        p->next = malloc(sizeof(Command) );
        p = p->next;
        p->next = NULL;
		scanf("%d",&(p->data));
        // takeData(p);
        N--;
    }
	
//    p = head;
//	head = head->next;
//	p->next = NULL;
//	free(p);
    
    //print how many commands you want to provide
	//OR
	//4 203 105 7 100 => first number will tell how many commands we should read. 

	//take all inputs in the list. 
	//Hint: Link list initial filling logic
	return 0;
}

int processCommand()
{
	//take the first node (take value of head, change head)
	//command = head->data

	//targetFloor = (take target floor from command)

	//if current floor != target floor
		// change floor by one. 
		//change state respectively
	//else
		//change state to idle
		//remove current command. It is done. //head = head ->next, but make sure you free up memory. 

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
			takeCommands();
		//else do nothing here. 

		//process the current command
		processCommand();
	}

	return 0;
}
