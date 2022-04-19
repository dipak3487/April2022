#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
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

//int takeFloors();
int takeFloors()
{
	totalFloors = 0;
	while(totalFloors < 1 || totalFloors > 99)
	{
		printf("How tall is your building (1-99): "); 
		scanf("%d", &totalFloors);
	}
	return 0;

/*	if(totalFloors<0 ||totalFloors>99)
	{
		takeFloors();
	}
	else{
		printf("the no.of.floors are%d",&totalFloors);
	}*/
	//take number of floors available (1..99) in totalFloors
	//print message
	//take input
	//validate the input (1..99)
	//retake input if required.
	
}


int printDetails()
{

	Command *p;
     //   printf("\n The current floor number is: %d \t current state is %d \n", currentFloor,currentState);
	printf("\t[%d]-[%s]:\t[ ", currentFloor, strState[currentState]);
    p = head;
    while(p != NULL)
    {
		printf(" %03d", p->data);
		p = p->next;

    }
	printf("]\n");

	//print current floor number, current state, list of (current and pending) commands.
	//e.g.
	//Floor: 0, State: UP, Commands: 203, 105, 7, 100

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
    Command *p = NULL;
    int N = 0;

    printf("How many commands  you want:(-1 to exit): ");
	scanf("%d", &N);

    if(N<1) exit(EXIT_SUCCESS);

	if(head ==NULL)
	{
		head = malloc(sizeof(Command) );
		head->next = NULL;
		head->data =takeCommand();
	}
    p = head;

    while(N > 1)
    {

        p->next = malloc(sizeof(Command) );
        p = p->next;
        p->next = NULL;
		p->data = takeCommand();
		//scanf("%d",&(p->data));
        // takeData(p);
        N--;
    }
/*	p = head;
	while(p != NULL)
    {
        printf("[%d]->",  p->data);
        p = p->next;
    }
    printf("NULL\n");
*/
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
}

int processCommand()
{

	int command = 0;
	int TargetFloor=0;
	Command *p=NULL;
	
	command = head->data;
	
	TargetFloor = command%100;
	if(currentFloor < TargetFloor)
		{
			currentState = UP;
			currentFloor++;
		}
		else if(currentFloor >TargetFloor)
		{
			currentState = DOWN;
			currentFloor--;
		}
	if(currentFloor == TargetFloor)
	{
		currentState=0;
		p= head;
		head=head->next;
		p->next =NULL;
		free(p);
		p=NULL;
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
		if (NULL == head)
		{

		//if no pending commands, ask for it
			takeCommands();
		}
		else{
		}
		//else do nothing here. 
//			printDetails();
		//process the current command
		processCommand();
		sleep(1);
	}

	return 0;
}
