
#include<stdlib.h>
#include<stdio.h>

typedef enum State { Idle=0, UP, DOWN} State;
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
	//take number of floors available (1..99) in totalFloors
	printf("Enter the floor number from 1 to 99\n");	//print message
	scanf("%d", &totalFloors);//take input
	if(totalFloors >= 0 && totalFloors <= 99){
		printf("This is the right Floor!!!\n");		
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
	
	printf("Floor: %d,  State:%s\n", currentFloor, currentState);
	
	Command *p;
	p = head;
	while(p != NULL)
	{
		//printf("Enter Current Floor number\n"); scanf("%d", &(p->currentFloor));
                //printf("Enter CurrentState\n"); scanf("%s", &(p->currentState));
                //printf("Enter Commands\n"); scanf("%d", &(p->data));
//		printf("The list of (current and pending) commands:%d");
		p = p->next;
	}
	//e.g.
	//floor: 0, state: up, commands: 203, 105, 7, 100

	return 0;
}

int takecommands()
{
	//print how many commands you want to provide

	Command *p = NULL;
	Command *newNode = NULL;
	int N = 0, total=0;

	printf("How many commands you want: "); scanf("%d", &N);
	total = N;
	
	head = malloc(sizeof(Command) );
	head->next = NULL;
	scanf("%d", &(head->data));
	p = head;

	while(N > 1)
	{

		p->next = malloc(sizeof(Command) );
		p = p->next;
		p->next = NULL;
		scanf("%d", &(p->data));
		N--;
	}

	p = head;
	while(p != NULL)
	{
        	printf("[%d]->",  p->data);
        	p = p->next;
	}

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
	Command *p;
	p = head->data;
	int targetFloor;
	targetFloor = currentFloor%100;
	//targetfloor = (take target floor from command)

	//if current floor != target floor
		// change floor by one. 
		//change state respectively
	while(targetFloor != currentFloor)
	{
		if(targetFloor > currentFloor)
		{
			currentFloor += 1;
			currentState = UP;
		}
		else if(targetFloor < currentFloor)
		{
			currentFloor -= 1;
			currentState = DOWN;
		}
		else{
			currentState = Idle;
		}
	} 
	//else
		//change state to idle
	if(targetFloor == currentFloor)
	{
		currentState = Idle;
		p = head;
		head = head->next;
		p->next = NULL;
		free(p);
		p = NULL;	//remove current command. it is done. //head = head ->next, but make sure you free up memory. 
	}
	printDetails();	//print the current state. by calling printdetails()
	return 0;
}


int main()
{
	takeFloors();	//take number of floors available (0..99) in totalfloors

	printDetails();

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
