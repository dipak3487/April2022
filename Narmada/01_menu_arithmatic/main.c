#include <stdlib.h>
#include<stdio.h>


int add(int n1, int n2)
{
int res1;
res1 = n1+n2;
return res1;
}

int subtract(int n1, int n2)
{
int res2;
res2 = n1-n2;
return res2;
}


int multiply(int n1, int n2)
{
int res3;
res3 = n1*n2;
return res3;
}

int divide(int n1, int n2)
{
int res4;
res4 = n1/n2;
return res4;
}


int main()
{
    printf("\n\n\t\tGanga - Menu driven program 01\n\n\n");
    int choice, num, i;
    int n1, n2, res1,res2,res3,res4,x,y,z;
    unsigned long int fact;
    while(1)
    {
        printf("1. Factorial \n");
        printf("2. Prime\n");
        printf("3. Odd\\Even\n");
	printf("4. Addition\n");
	printf("5. Subtraction\n");
	printf("6. Multiplication\n");
	printf("7. Divide\n");
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
		printf("Enter two number = ");
		scanf("%d %d", &n1, &n2);
		res1 = add(n1,n2);
		printf("\n Sum of %d and %d is:%d\n\n",n1,n2,res1);
		break;
	    case 5:
		printf("Enter two number = ");
                scanf("%d%d", &n1,&n2);
		res2 = subtract(n1,n2);
                printf("\n Subtraction of %d and %d is:%d\n\n",n1,n2,res2);
                break;
	    case 6:
		printf("Enter two number = ");
                scanf("%d%d", &n1,&n2);
		res3 = multiply(n1,n2);
                printf("\n Multiplication of %d and %d is:%d\n\n",n1,n2,res3);
                break;

	    case 7:
		printf("Enter two number = ");
                scanf("%d%d", &n1,&n2);
		res4 = divide(n1,n2);
                printf("\n Divison of %d and %d is:%d\n\n",n1,n2,res4);
                break;



            case 8:
                printf("\n\n\t\t\tCoding is Fun !\n\n\n");
                exit(0);    // terminates the complete program execution
        }
    }
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}
