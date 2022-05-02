#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct key_value
{
	long long num;
	char cupl[50];
	char exdt[50];
	long long bal;

} dict;

void printValues(dict values[]);

int main()
{

	FILE *fp = fopen("sample.csv","r");


	if(!fp)
	{
		printf("trouble reading file !\nprogram terminating....\n");
		return 0;
	}
	char buff[1024];

	int row_count = 0;
	int field_count = 0;
	dict values[29];
	double sum;
	int total;

	int i = 0;
	while (fgets(buff,1024,fp))
	{
		field_count = 0;
		row_count++;
		if (row_count == 1)
			continue;

		char *field = strtok(buff,"," );
		while(field)
		{
			if(field_count ==0)
				values[i].num=atol(field);

			if(field_count ==1)
				strcpy(values[i].cupl,field);

			if(field_count ==2)
				strcpy(values[i].exdt,field);

			if(field_count ==3)
				values[i].bal=atol(field);



			field = strtok(NULL, ",");
			field_count++;
		}
		i++;
	}

	printValues(values);
	return 0;
}

void printValues(dict values[])
{
	for(int i=0; i<20; i++)
	{
		printf("Number-> %lld\t Current Plan-> %s\t Ex_Date-> %s\t Av_Bal-> %lld\n", values[i].num,values[i].cupl,values[i].exdt,values[i].bal);
	}
}
