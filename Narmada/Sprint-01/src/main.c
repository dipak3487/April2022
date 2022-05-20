/* FILENAME : main.c
 *
 * DESCRIPTION   :  This is a menudriven project in which user selects
 * 		    their choice to perform the operations which is present in the menu
 * 		    place a call/check balance, current plan
 * 		    , expiry date of their plan.
 *
 *
 * Revision history :
 *
 * DATE			NAME			REASON
 * 25 Apr 2022		Narmada Team		Required Changes are done
 * 5 May 2022		Narmada Team		Updated the case 2
 *
 *
 */




#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>


//Creatin Array of structures to read different entity into different variables

typedef struct Data{
	long long mobile;
	int rate;
	char exp_date[15];
	int balance;
}dict;


int main()
{

	printf("\n\n\t\tTelecom OCS(Online Charging System)-- Team Narmada\n\n\n");
	int choice=0,dial_time=0,ring_time=0,connect_time=0;
	int index_a, index_b;
	char str[1024];
	FILE *fp = fopen("../data/sample.csv", "r");
	if(fp == NULL){
		printf("\nError in opening the sample.csv file\n");
		return 0;
	}
	int row_count = 0;
	int field_count = 0;
	dict values[29];
	//int totalRecords = 0;
	//int total;
	int iteration = 0;
	
	 /*FUNCTION NAME  :    fgets()
	 *
	 * DESCRIPTION   :    The C library function char *fgets(char *str, int n, FILE *stream)
	 * 		      reads a line from the specified stream and stores it into the string 
	 * 		      pointed to by str. It stops when either (n-1) characters are read, the 
	 * 		      newline character is read, or the end-of-file is reached, whichever comes
	 * 		       first.
	 *
	 *
	 * RETURNS	:    On success, the function returns the same str parameter. If the End-of-File 
	 * 		     is encountered and no characters have been read, the contents of str remain 
	 * 		     unchanged and a null pointer is returned.
	 * 		     If an error occurs, a null pointer is returned.
	 *
	 *
	 */


	while(fgets(str,1024,fp)){
		field_count = 0;
		row_count++;
		if(row_count ==1)
			continue;
		
		/* FUNCTION NAME    :   strtrok()
		 *
		 * Description      :   The C library function char *strtok(char *str, const char *delim)
		 * 		        breaks string str into a series of tokens using the delimiter delim.
		 *
		 *
		 * RETURNS	    :   This function returns a pointer to the first token found in the string.
		 * 		        A null pointer is returned if there are no tokens left to retrieve.
		 *
		 *
		 */

		char *field = strtok(str,",");
		while(field){
			if(field_count == 0)

				/*FUNCTION NAME  :    atol()
				 *
				 *
				 * DESCRIPTION   :    The C library function long int atol(const char *str)
				 * 		      converts the string argument str to a long integer (type long int).
				 *
				 *
				 * RETURNS       :    This function returns the converted integral number as a long int.
				 * 		      If no valid conversion could be performed, it returns zero.
				 *
				 *
				 */

				values[iteration].mobile = atol(field);

			if(field_count == 1)
				values[iteration].rate = atol(field);

			if(field_count == 2)
				strcpy(values[iteration].exp_date, field);

			if(field_count == 3)
				values[iteration].balance = atol(field);


			field = strtok(NULL, ",");
			field_count++;
		}
		iteration++;
	}
	//totalRecords = i+1;

	//for(i = 0; i<20; i++){
	//printf("Mobile -> %lld\t Current Plan-> %d\t Exp_date-> %s\t Avl_Balance -> %d\n", values[i].mobile, values[i].rate, values[i].exp_date,values[i].balance);
	//}


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
				for(iteration = 0; iteration < 20; iteration++){
					printf("%2d -> %lld\n", iteration, values[iteration].mobile);
				}

				index_a = -1;
				while(index_a < 0 || index_a > 19)
				{
					printf("\n\nChoose the index of your number: [0 to 20] :  ");
					scanf("%d", &index_a);
				}
				printf("\n Your number is: %lld, Index: %d\n", values[index_a].mobile, index_a);
				break;
			case 2:
				for(iteration = 0; iteration < 20; iteration++){
					printf("%2d -> %lld\n", iteration, values[iteration].mobile);
				}

				index_b = -1;

				while(index_b < 0 || index_b > 19)
				{
					printf("\n\nChoose the index of B_PARTY number: [0 to 20] :  ");
					scanf("%d", &index_b);
				}


				if(values[index_a].balance < 0)
				{
					printf("You don't have enough balance! Please do recharge your number.\n");
					continue;
				}
				//take current date of system to check with plan expiry date
				/* DATATYPE         :  time_t()
				 *
				 * DESCRIPTION      :  The time_t datatype is a data type in the ISO C library defined
				 * 		       for storing system time values. Such values are returned from the
				 * 		       standard time() library function.
				 *
				 */

				char todayDateStr[100];
				time_t rawtime;
				struct tm *timeinfo;
		                time ( &rawtime );
				timeinfo = localtime ( &rawtime );

				/*   FUNCTION NAME   :   strftime()
				 *
				 *
				 *   DESCRIPTION     :   strftime() is a function in C which is used to format date and
				 *   			 time. It comes under the header file time.h, which also contains
				 *   			 a structure named struct tm which is used to hold the time and date.
				 *
				 *
				 *   RETURNS         :   If the resulting C string fits in less than size characters (which
				 *   			 includes the terminating null-character), the total number of characters 
				 *   			 copied to str (not including the terminating null-character) is returned
				 *   			  otherwise, it returns zero.
				 *
				 */

			        strftime(todayDateStr, strlen("DD-MMM-YYYY ")+1,"%d-%m-%Y ",timeinfo);
				//printf("%s\n", todayDateStr );
				//printf("%s\n",values[index_a].exp_date);
				
				/* FUNCTION NAME    :   strcmp()
				 *
				 * DESCRIPTION      :   The strcmp() compares two strings character by character.
				 * 			If the strings are equal, the function returns 0.
				 *
				 */

				int result = strcmp(values[index_a].exp_date, todayDateStr); //comparing today date and the plan
			       								     //expiry date
				if(result>0)
				{
					/* FUNCTION NAME    :   srand() and rand()
					 *
					 *
					 * DESCRIPTION      :   The function rand() is used to generate the pseudo random
					 * 			number. It returns an integer value and its range is from
					 * 			0 to rand_max i.e 32767.
					 *
					 * 			The function srand() is used to initialize the generated
					 * 			pseudo random number by rand() function. It does not return
					 * 			anything.
					 *
					 */

					srand(time(NULL));
					dial_time = rand() % 10;
					printf("\n[%d][%lld] is DIALING... %lld\n\n", index_a, values[index_a].mobile, values[index_b].mobile);
					/*  FUNCTION NAME   :  sleep()
					 *
					 *
					 *  DESCRIPTION     :   The sleep() method in the C programming language allows
					 *  			you to wait for just a current thread for a set amount of time.
					 *
					 */

					sleep(dial_time);
					srand(time(NULL));
					ring_time = rand() % 10;
					printf("RINGING...\n\n");
					sleep(ring_time);
					if(ring_time>50){
						printf("Ring No Answer\n\n\n");
					}
					else{
						time_t start_t, end_t;
						int diff_t;
						srand(time(NULL));
						connect_time = rand() % 40;
						printf("CONNECTED...\n\n");
						start_t = time(NULL);
						sleep(connect_time);
						end_t = time(NULL);
						diff_t = (int) end_t - start_t;
						printf("Your Call Duration is: %d second\n\n", diff_t);
						values[index_a].balance = values[index_a].balance - (diff_t * values[index_a].rate);
						//TODO: convert it into integer: values[index_a].rate);
						printf("Your call cost is: %d paisa\n", (diff_t * values[index_a].rate));
						printf("Your remaining balance is: %d paisa\n\n", values[index_a].balance);
				        	FILE *fp = fopen("../data/sample.csv", "w");
						fprintf(fp, "Mobile No.,Curr_plan,Exp_Date,Avl_Balance\n");
						for(iteration = 0; iteration < 20; iteration++)
						{
							if(values[index_a].mobile)
							{
								fprintf(fp, "%lld,%d,%s,%d\n", values[iteration].mobile, values[iteration].rate, values[iteration].exp_date, values[iteration].balance);
						
							}
						}
						fclose(fp);	
					}
				}
				else {
					printf("Sorry! Your plan is expired! Please recharge your number to make a call.\n\n");
				}

				break;

			case 3:
				printf("Your current rate is [%d] and expiry date for your plan is[%s]\n\n", values[index_a].rate, values[index_a].exp_date);
				break;

			case 4:
				printf("Your Available Balance is [%d]\n\n", values[index_a].balance);
				fclose(fp);
				break;

			case 5:
				exit(0);
		}
	}


	return 0;
}
