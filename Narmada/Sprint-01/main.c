#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>

typedef struct Data{
	long long mobile;
	int rate;
	char exp_date[15];
	int balance;
}dict;


int main()
{

	printf("\n\n\t\tTelecom OCS(Online Charging System)-- Team Narmada\n\n\n");
	int choice,a,b,c;
	int index_a, index_b;
	char str[1024];
	FILE *fp = fopen("sample.csv", "r");
	if(fp == NULL){
		printf("\nError in opening the file\n");
		return 0;
	}
	int row_count = 0;
	int field_count = 0;
	dict values[29];
	int totalRecords = 0;
	int total;
	int i = 0;
	while(fgets(str,1024,fp)){
		field_count = 0;
		row_count++;
		if(row_count ==1)
			continue;

		char *field = strtok(str,",");
		while(field){
			if(field_count == 0)
				values[i].mobile = atol(field);

			if(field_count == 1)
				values[i].rate = atol(field);

			if(field_count == 2)
				strcpy(values[i].exp_date, field);

			if(field_count == 3)
				values[i].balance = atol(field);


			field = strtok(NULL, ",");
			field_count++;
		}
		i++;
	}
	totalRecords = i+1;

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
				for(i = 0; i < 20; i++){
					printf("%2d -> %lld\n", i, values[i].mobile);
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
				for(i = 0; i < 20; i++){
					printf("%2d -> %lld\n", i, values[i].mobile);
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
				//take randome interval

				srand(time(NULL));
				a = rand() % 10;
				printf("\n[%d][%lld] is DIALING... %lld\n\n", index_a, values[index_a].mobile, values[index_b].mobile);
				sleep(a);
				srand(time(NULL));
				b = rand() % 10;
				printf("RINGING...\n\n");
				sleep(b);
				if(b>50){
					printf("Ring No Answer\n\n\n");
				}
				else{
					time_t start_t, end_t;
					int diff_t;
					srand(time(NULL));
					c = rand() % 40;
					printf("CONNECTED...\n\n");
					start_t = time(NULL);
					sleep(c);
					end_t = time(NULL);
					diff_t = (int) end_t - start_t;
					printf("Your Call Duration is: %d second\n\n", diff_t);
					values[index_a].balance = values[index_a].balance - (diff_t * values[index_a].rate);
					//TODO: convert it into integer: values[index_a].rate);
					printf("Your call cost is: %d paisa\n", (diff_t * values[index_a].rate));
					printf("Your remaining balance is: %d paisa\n\n", values[index_a].balance);
				        FILE *fp = fopen("sample.csv", "w");
					fprintf(fp, "Mobile No.,Curr_plan,Exp_Date,Avl_Balance\n");
					for(i = 0; i < 20; i++)
					{
						if(values[index_a].mobile)
						{
							fprintf(fp, "%lld,%d,%s,%d\n", values[i].mobile, values[i].rate, values[i].exp_date, values[i].balance);
						
						}
					}	
				}
				break;

			case 3:
				printf("Your current rate is [%d] and expiry date for your plan is[%s]\n\n", values[index_a].rate, values[index_a].exp_date);
				break;

			case 4:
				printf("Your Available Balance is [%d]\n\n", values[index_a].balance);
				break;

			case 5:
				exit(0);
		}
	}


	return 0;
}
