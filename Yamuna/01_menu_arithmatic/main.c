#include<stdlib.h>
#include<stdio.h>


int main()
{
    printf("\n\n\t\tYamuna @Omkar - Menu driven program 01\n\n\n");
    int choice, num, i;
    unsigned long int fact;
	int a; 
	int b;
	int res;

    while(1)
    {
        printf("1. Factorial \n");
        printf("2. Prime\n");
        printf("3. Odd\\Even\n");
        printf("4. Add\n");
	printf("5. Subtract\n");
	printf("6. Multiply\n");
	printf("7. Divided\n");
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
		printf("Enter numbers to add:\n");
		scanf("%d %d", &a , &b);
		
		res = a+b;
		printf("addition of two nos is : %d\n", res);
		break;

	    case 5:
                printf("Enter numbers to subtract:\n");
                scanf("%d %d", &a , &b);

                res = a-b;
                printf("subtraction of two nos is : %d \n", res);
		break;

	    case 6:
                printf("Enter numbers to Multiply:\n");
                scanf("%d %d", &a , &b);

                res = a*b;
                printf("Multiplication of two nos is : %d \n", res);
		break;

	    case 7:
                printf("Enter numbers to div:\n");
                scanf("%d %d", &a , &b);

                res = a/b;
                printf("division of two nos is : %d\n", res);

        
            case 8:
                printf("\n\n\t\t\tCoding is Fun !\n\n\n");
                exit(0);    // terminates the complete program execution
        }
    }
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}
