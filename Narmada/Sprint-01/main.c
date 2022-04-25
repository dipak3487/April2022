#include <stdio.h>
#include <stdlib.h>

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

switch(choice)                                                                                                                                  // Call Inside main
{
     case 1:
     {
                 printf("Enter your Number Here");                                                                              //Take Number Here or not;

                //Read number list from Numbers.list                                                                    // global variables to be used, Being called in another switch case as well.
                    //1.a. Number1
                        //1.b. Number2
                                                                                                                                                               // Call Take number()
                //1.z. Back                                                                                                                             // Call Menu Again
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
        printf("Dialing....\n");
                sleep(3);
        printf("Ringing....\n");
                                                                                                // wait for 5 sec
        printf("Connected.\n");
                                                                                                // how to put any key press command to exit and show main menu

                break;
      }

      case 3:
      {
                        //should display current rate plan, expiry date for <CurrentChoice> mobile number.
        break;
      }

      case 4:
      {
                  // Lil Complicated
                //should display available balance for <CurrentChoice> Mobile number.
        break;
      }
          case 5:
          {
                  exit(0); //Exit from program
          }


      default:
      {
                  printf("Wrong Choice. Try Again\n");
      }
        return 0;

}

int main()
{
        int ch;

        while(1)                                                                                        //Menu Bar
        {

        printf("Online ChargingSystem menu \n");
        printf("Choose Your Option \n");
        printf("1. Choose Your Number");
        printf("2. Dial A Number");
        printf("3. See Rating, Expiry Date, Last Recharge Date");       //create another switch case for this menu like subfolders
        printf("4. Check Available Balance");
        printf("5. Exit");

        takeNumber();
        simRateExp();
        numBal();
        }

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
