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
Command *head = NULL;

int takeFloors()
{
	int F;
	printf("enter the no.of floors ");
	scanf("%d",&F);
	if(F<0 ||F>99)
	{
		takeFloors();
	}
	else{
		printf("the no.of.floors are%d",F);
	}
//	return F;
	//take number of floors available (1..99) in totalFloors
	//print message
	//take input
	//validate the input (1..99)
	//retake input if required.
	return 0;
}


int printDetails()
{

        printf("\n The current floor number is: %d \t current state is %d \n", currentFloor,currentState);
	Command *p = NULL;
    p = head;
    while(p != NULL)
    {


		printf("\n The list of (current and pending) commands is: %d", p->data);
		p = p->next;

    }


	//print current floor number, current state, list of (current and pending) commands.
	//e.g.
	//Floor: 0, State: UP, Commands: 203, 105, 7, 100

	return 0;
}

int takeCommands()
{
    Command *p = NULL;
    Command *newNode = NULL;
    int N = 0, total=0;

    printf("How many commands  you want: "); scanf("%d", &N);
    total = N;
	if(head ==NULL)
	{
		head = malloc(sizeof(Command) );
		head->next = NULL;
		scanf("%d",&(head->data)); // takeData(head);
	}
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
	p = head;
	while(p != NULL)
    {
        printf("[%d]->",  p->data);
        p = p->next;
    }
    printf("NULL\n");

    return 0;

	
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

	Command *l;
	int p = head->data;
	int TargetFloor;
	TargetFloor = p%100;
	while(TargetFloor != currentFloor)
	{
	 if(currentFloor !=TargetFloor)
	 {
		if(currentFloor < TargetFloor)
		{
			currentFloor=+1;
			currentState = UP;
		}
		else
		{
			currentFloor= currentFloor-1;
			currentState = DOWN;
		}
	 }
	}
	if(currentFloor == TargetFloor)
	{
		currentState=0;
		l= head;
		head=head->next;
		l->next =NULL;
		free(l);
		l=NULL;
	}
	printDetails();
	


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
