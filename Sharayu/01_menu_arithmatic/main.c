#include <stdlib.h>
#include<stdio.h>

int sum,sub,mul,dvid;

int add(int n1, int n2)
{
	sum=n1+n2;
	printf("addition of the numbers:%d\n",sum);
}

int subtract(int n1, int n2)
{
	sub=n1-n2;
	printf("subtraction of the numbers:%d\n",sub);
}
 
int multiply(int n1, int n2)
{
	mul=n1*n2;
	printf("multiplication of the numbers:%d\n",mul);
}

int divide(int n1, int n2)
{
	dvid=n1/n2;
	printf("division of the numbers:%d\n",dvid);
}


void printMenu()
{
	//printf
	//printf
	//printf
}

int main()
{
    printf("\n\n\t\tSharayu - Menu driven program 01\n\n\n");
    int choice, num, i,n1,n2;
    unsigned long int fact;

    while(1)
    {
        printf("1. Factorial \n");
        printf("2. Prime\n");
        printf("3. Odd\\Even\n");
	printf("4. Addition\n");
	printf("5. subtraction\n");
	printf("6. multiplication\n");
	printf("7. division\n");
        printf("8. Exit\n\n\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter number:\n");
                scanf("%d", &num);
                fact = 1;
                for(i = 1; i <= num; i++)
                {
                    fact = fact*i;
                }
                printf("\n\nFactorial value of %d is = %lu\n\n\n",num,fact);
                break;
        
            case 2:
                printf("Enter number:\n");
                scanf("%d", &num);
                if(num == 1)
                printf("\n1 is neither prime nor composite\n\n");
                for(i = 2; i < num; i++)
                {
                    if(num%i == 0)
                    {
                        printf("\n%d is not a prime number\n\n", num);
                        break;
                    }
                
                }
                /*
                    Not divisible by any number other 
                    than 1 and itself
                */
                if(i == num) 
                {
                    printf("\n\n%d is a Prime number\n\n", num);
                    break;
                }
        
            case 3:
                printf("Enter number:\n");
                scanf("%d", &num);
        
                if(num%2 == 0) // 0 is considered to be an even number
                    printf("\n\n%d is an Even number\n\n",num);
                else
                    printf("\n\n%d is an Odd number\n\n",num);
                break;
	case 4:
		printf("enter the First number:\n");
		scanf("%d", &n1);
		printf("enter the second number:\n");
                scanf("%d", &n2);
		add(n1,n2);
		
		break;
	case 5:
		printf("enter the First number:\n");
                scanf("%d", &n1);
                printf("enter the second number:\n");
                scanf("%d", &n2);
                subtract(n1,n2);
		break;
	case 6:
		printf("enter the First number:\n");
                scanf("%d", &n1);
                printf("enter the second number:\n");
                scanf("%d", &n2);
                multiply(n1,n2);
		break;
	case 7:
		printf("enter the First number:\n");
                scanf("%d", &n1);
                printf("enter the second number:\n");
                scanf("%d", &n2);
                divide(n1,n2);
		break;
	case 8:
                printf("\n\n\t\t\tCoding is Fun !\n\n\n");
                exit(0);    // terminates the complete program execution
                break;


        }
    }
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}
