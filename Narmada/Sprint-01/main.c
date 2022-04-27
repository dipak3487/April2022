#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
	
    printf("\n\n\t\tTelecom OCS(Online Charging System)-- Team Narmada\n\n\n");
    char num[14], num1[14];
    int choice;
    char str[1024];
	

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
		case 1:;
			/*Option 1: Read number list from Numbers.list 
			1.a. Number1
			1.b. Number2
			.
			.
			1.z. Back
			On selection of (a..y), select the number and show the main menu. 
			On selection of z, keep the current number and show the main menu.*/

			FILE *fp = fopen("sample.txt", "r");
			if(fp == NULL)
			{
				printf("Error: could not open file\n");
				return(1);
			}

			while (fgets(str,1024, fp) != NULL) {
				for(int cols = 0; cols<8; cols++){
					//char s[1024];
					fscanf(fp, "%s", &str);
					if(cols == 0){
						printf("%s\n", str);
					}
				}
				//printf("%s", str);
			
    			}
			printf("\n\nChoose your number: ");
			scanf("%s", &num);
		
			fseek(fp, 0, SEEK_SET);
			bool x = false;
			while (fgets(str,1024, fp) != NULL) {
                      
              
                      		if((strstr(str, num))){
					//printf("\t\nNumber found in the list\n\n\n");
					x = true;
					break;
				}
				else{
					//printf("Invalid number\n");
					x = false;
			
				}
			}
			if(x == true){
				printf("Number found in the list\n\n");
				//printf("Choose second number:");
				//scanf("%s", &num1);
			}
			else{
				printf("Invalid Number\n\n");
			}
			fclose(fp);
			break;


		case 2:;

      			/*option 2: Read number list from Numbers.list
			2.a. Number1
			2.b. Number2
			.
			.
			2.z. Back
			On selection of (a..y), print: DIALING.. (sleep for 0-3 seconds), RINGING (0-5 seconds), CONNECTED (for 1-			  60 seconds or till balance is available). HANGUP on any key press and back to the main menu. Try to fit RN			    A (Ring No Answer) if RINGING for > 4 seconds (i.e. for 5 seconds), then go RNA, return.
			printf("4. \n");*/
			fopen("sample.txt", "r");
			
			printf("You selected %s as your number:\n", num);

			/*while (fgets(str,1024, fp) != NULL) {
                                for(int cols = 0; cols<4; cols++){
                                        //char s[1024];
                                        fscanf(fp, "%s", &str);
                                        if(cols == 0){
                                                printf("%s\n", str);
                                        }
                                }
                                //printf("%s", str);

                        }*/

			printf("Choose another number from the list to dial:");
			scanf("%s", &num1);
			//printf(num1);

			fseek(fp, 0, SEEK_SET);
			bool y = false;
                        while (fgets(str,1024, fp) != NULL) {


                                if((strstr(str, num1))){
                                       //printf("\t\nNumber found in the list\n\n\n");
                                        y = true;
                                        break;
                                }
                                else{
                                        //printf("Invalid number\n");
                                        y = false;

                                }
                        }
                        if(y == true){
                                printf("Number found in the list\n\n");
                                //printf("Choose second number:");
                                //scanf("%s", &num1);
                        }
                        else{
                                printf("Invalid Number\n\n");
                        }
			fclose(fp);
			break;


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
