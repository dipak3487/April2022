#include<stdio.h>
#include<stdlib.h>

typedef struct command
{
     int data;
     struct command *next;
}command;

int takeNumber()
{
     //take the number of your choice
     //dial that number
}

int simRateExp()
{
     //print the rating of a particular number(sim)
     //print the expiry date 
}

int numBal()
{
     //display the available balance of a number
}

switch(choice)
{
     case 1:
     {
	//Read number list from Numbers.list
        //1.a. Number1
        //1.b. Number2
 
        //1.z. Back
        //On selection of (a..y), select the number and show main menu. 
        //On selection of z, keep current number and show main menu.
     	break;
      }

      case 2:
      {
	//Read number list from Numbers.list
        //2.a. Number1
        //2.b. Number2
 
        //2.z. Back
	//On selection of (a..y), print: DIALING.. (sleep for 0-3 seconds), RINGING (0-5 seconds), CONNECTED (for 1-60 seconds or till balance is available). HANGUP on any key press and back to main menu. Try to fit RNA (Ring No Answer) if RINGING for > 4 seconds (i.e. for 5 seconds), then go RNA, return.
      	break;
      }

      case 3:
      {
	//should display current rate plan, expiry date for <CurrentChoice> mobile number.
     	break;
      }

      case 4:
      {
	//should display available balance for <CurrentChoice> Mobile number. 
      	break;
      }
   
      default:
      {
	printf("wrong choice\n");
      }
	return 0;
}

int main()
{
	takeNumber();
	simRateExp();
	numBal();

	return 0;
}

/*Menu:
1. Choose your number (<CurrentChoice>)
2. Dial a number
3. See rating, expiry 
4. See available balance
5. Exit

Option 1: Read number list from Numbers.list
1.a. Number1
1.b. Number2
.
.
.
1.z. Back
On selection of (a..y), select the number and show main menu. 
On selection of z, keep current number and show main menu.


Option 2: Read number list from Numbers.list
2.a. Number1
2.b. Number2
.
.
2.z. Back

On selection of (a..y), print: DIALING.. (sleep for 0-3 seconds), RINGING (0-5 seconds), CONNECTED (for 1-60 seconds or till balance is available). HANGUP on any key press and back to main menu. Try to fit RNA (Ring No Answer) if RINGING for > 4 seconds (i.e. for 5 seconds), then go RNA, return.

Option 3: should display current rate plan, expiry date for <CurrentChoice> mobile number. 

Option 4: should display available balance for <CurrentChoice> Mobile number. */



