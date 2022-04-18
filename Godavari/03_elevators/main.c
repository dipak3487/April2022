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
        //take number of floors available (1..99) in totalFloors

         //print messag
           //   printf("ENter the number from 1 to 99\n");
           //  scanf("%d\n",&m);
            //take input
            //validate the input (1..99)
            int F;
	printf("enter the no.of floors between 1 to 99\n");
	scanf("%d",&F);
	if(F<0 ||F>99)
	{
		takeFloors();
	}
	else{
		printf("the no.of.floors are %d\n",F);
	}
        //retake input if required.
  return 0;
}


int printDetails()
{
        //print current floor number, current state, list of (current and pending) commands.
      //   printf("The current floor number is:- %d The Current state is:- %d The list of commands %d ",f,s,c);
        //e.g.
        //Floor: 0, State: UP, Commands: 203, 105, 7, 100
    printf("\n The current floor number is: %d \t current state is %d \n", currentFloor,currentState);
 
     Command *p= NULL;
     p = head;
    while(p != NULL)
    {
		printf("\n The list of (current and pending) commands is: %d\n", p->data);
		p = p->next;
    }    


    
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
       head = malloc(sizeof(Command));
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
         N--;
     }
       while(p !=NULL)
       {
            {
        printf("\n The current floor number is: %d \t current state is %d \n", currentFloor,currentState);
                printf("\n The list of (current and pending) commands is: %d\n", p->data);
                p = p->next;
    }






          }



       //print how many commands you want to provide
        //OR
        //4 203 105 7 100 => first number will tell how many commands we should read.

        //take all inputs in the list.
        //Hint: Link list initial filling logic
        return 0;

    
}

int processCommandnt()
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
        takeFloors(7);   //take number of floors available (0..99) in totalFloors

  //      printDetails();

    /*    while(1)
        {
                //if no pending commands, ask for it
                        takeCommands();
                //else do nothing here.

                //process the current command
                processCommand();
        }
*/
        return 0;
}

 
