



#include <stdlib.h>
#include<stdio.h>



int add(int n1, int n2)
{
  return (n1+n2);
}

int subtract(int n1, int n2)
{
  return (n1 - n2);
}


int multiply(int n1, int n2)
{
  return (n1 * n2);
}

int divide(int n1, int n2)
{
  return (n1 / n2);
}

void printMenu()
{
	//printf
	//printf

	//printf
}

int main()
{
    printf("\n\n\t\tGanga - Menu driven program 01\n\n\n");
    int choice, num, i;
    unsigned long int fact;
    int l,m;
    while(1)
    {
        printf("1. Factorial \n");
        printf("2. Prime\n");
        printf("3. Odd\\Even\n");
        printf("4. add\n\n\n");
	printf("5. subtract\n\n\n");
        printf("6. multiply \n\n\n");
	printf("7. divide \n\n\n");
        printf("0. exit \n\n\n"); 
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
		printf("enter the numbers to add");
		scanf("%d %d",&l,&m);
		printf("\n\n the sum is %d\n\n",add(l,m));
		break;
	    case 5:
		printf("enter the numbers to subtract");
		scanf("%d %d",&l,&m); 
		printf("\n\n subtraction is %d\n\n", subtract(l,m));
                break;

          case 6:
                printf("enter the numbers to multiply");
                scanf("%d %d",&l,&m); 
                printf("\n\n multiply is %d\n\n", multiply(l,m));
                break; 
	  case 7:
		printf("enter the numbers to divide");
                scanf("%d %d",&l,&m);
                printf("\n\n multiply is %d\n\n", divide(l,m));
                break;
          case 0:
                printf("\n\n\t\t\tCoding is Fun !\n\n\n");
                exit(0);    // terminates the complete program execution
        }
    }
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;

}
