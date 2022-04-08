#include<stdio.h>
#include<stdlib.h>
int main()
{
    printf("\n\n\t\tTeam Narmada\n\n\n");
    int choice, num, i, num1, c;
    unsigned long int fact;

    while(1)
    {
        printf("1. Factorial \n");
        printf("2. Prime\n");
        printf("3. Odd\\Even\n");
	printf("4. Add\n");
	printf("5. Sub\n");
	printf("6. Mul\n");
	printf("7. Div\n");
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
		printf("Enter num:\n");
		scanf("%d",&num);
		printf("Enter num1:\n");
		scanf("%d",&num1);
		c=num+num1;
			printf("\n\n%d is Addition\n\n",c);
		break;
	    case 5:
		printf("Enter num:\n");
                scanf("%d",&num);
                printf("Enter num1:\n");
		scanf("%d",&num1);
                c=num-num1;
                        printf("\n\n%d is Sub\n\n",c);
                break;
	    case 6:
		printf("Enter num:\n");
                scanf("%d",&num);
                printf("Enter num1:\n");
                scanf("%d",&num1);
                c=num*num1;
                        printf("\n\n%d is Mul\n\n",c);
	   case 7:
		printf("Enter num:\n");
                scanf("%d",&num);
                printf("Enter num1:\n");
                scanf("%d",&num1);
                c=num/num1;
                        printf("\n\n%d is Div\n\n",c);		

        
            case 8:
                printf("\n\n\t\t\tCoding is Fun !\n\n\n");
                exit(0);    // terminates the complete program execution
        }
    }
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;

}
