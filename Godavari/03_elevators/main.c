#include<stdio.h>
typedef enum State { Idle=0, UP, DOWN} State;
typedef struct Command {
      int data;
        struct Command *next;
} Command;

int currentFloor;
int totalFloors;
State currentState;

int takeFloors(int m)
{
        //take number of floors available (1..99) in totalFloors
        int totalfloors[10]={1,2,3,4,5,6,7,8,9,10};
          int i;

         //print messag
           //   printf("ENter the number from 1 to 99\n");
           //  scanf("%d\n",&m);
            //take input
            //validate the input (1..99)
           for(int i=1;i<10;i++)
            {
                if(totalfloors[i] == m )
             {
              printf("-----valid input:-\n");
                break;
             }
            }
                   if(i == 10||i>10)
         {
                 printf("------Value is incorrect-----\n");
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
         printf("Enter Current floor number ,current state,list of commands\n");
         scanf("%d %s %d",&currentFloor,&currentState,&Command);
          printf("Floor:- %d,state:-%s,commands:-%d\n",currentFloor,currentState,Command);
        return 0;
}

int takeCommands()
{
   {
        //print how many commands you want to provide
        //OR
        //4 203 105 7 100 => first number will tell how many commands we should read.

        //take all inputs in the list.
        //Hint: Link list initial filling logic
        return 0;

    }
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

 
