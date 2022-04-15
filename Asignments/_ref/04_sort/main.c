#include<stdio.h>

int printArray(unsigned *p)
{
	printf("\nYour input is : \n");
	for(int i=0; i<10; i++)
	{
		printf("%d, ", *p);
		p++;
	}
	printf("\n");

	return 0;
}

int main()
{
	unsigned arr[10];
	int n;

	printf("Enter 10 integers: ");
	for(int i=0; i<10; i++)
	{
		scanf("%d", &arr[i]);
	}


	printArray(arr);

	for(int j= 0; j < 9; j++)
	{
		//sort
		for(int i=0; i< 9; i++)
		{
			if(arr[i] > arr[i+1])
			{
				//swap
				/*
				unsigned temp;
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				*/
				arr[i] = arr[i] ^ arr[i+1];
				arr[i+1] = arr[i] ^ arr[i+1];
				arr[i] = arr[i] ^ arr[i+1];
			}
		}
		
		printArray(arr);
	}


	return 0;
}
