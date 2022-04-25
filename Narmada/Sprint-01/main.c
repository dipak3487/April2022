#include<stdio.h>
#include <stdlib.h>
int main()
{
    printf("\n\n\t\tTelecom OCS(Online Charging System)-- Team Narmada\n\n\n");
    int choice, num, i;
    unsigned long int fact;

    while(1)
    {
        printf("1. Choose your number \n");
        printf("2. Dial a number\n");
        printf("3. See rating, Expiry\n");
	printf("4. See Available Balance\n");
	printf("5. Exit\n\n\n");
        printf("Enter your option here: ");
        scanf("%d",&choice);
        
        switch(choice)
	{
		case 1:
			/*Option 1: Read number list from Numbers.list
			1.a. Number1
			1.b. Number2
			.
			.
			1.z. Back
			On selection of (a..y), select the number and show the main menu. 
			On selection of z, keep the current number and show the main menu.*/



		case 2:

      			/*option 2: Read number list from Numbers.list
			2.a. Number1
			2.b. Number2
			.
			.
			2.z. Back
			On selection of (a..y), print: DIALING.. (sleep for 0-3 seconds), RINGING (0-5 seconds), CONNECTED (for 1-			  60 seconds or till balance is available). HANGUP on any key press and back to the main menu. Try to fit RN			    A (Ring No Answer) if RINGING for > 4 seconds (i.e. for 5 seconds), then go RNA, return.
			printf("4. \n");*/


		case 3:
			/*Option 3: should display current rate plan, expiry date for <CurrentChoice> mobile number. */


		case 4:

			//Option 4: should display available balance for <CurrentChoice> Mobile number.
   

		case 5:
			exit(0);
	}


    }
    return 0;
}
