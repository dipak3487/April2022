#include <stdlib.h>
#include<stdio.h>



add(int n1, int n2)
{
	return(n1+n2);
}

subtract(int n1, int n2)
{
	return(n1-n2);
}


multiply(int n1, int n2)
{
	return(n1*n2);
}

divide(int n1, int n2)
{
	return(n1/n2);
}


int main()
{
    printf("\n\n\t\tSindhu - Menu driven program 01\n\n\n");
    int choice, n1,n2, i;
    printf("For addition print 1\n");
        printf("For subtraction print 2\n");
        printf("For muliplication print 3\n");
        printf("For division print 4\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
   

    while(1)
    {

        
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
                printf("Enter the  numbers for subtraction:\n");
                scanf("%d %d", &n1,&n2);
             	printf("\n The result is %d",subtract(n1,n2));
        
            case 3:
                printf("Enter number:\n");
                scanf("%d", &num);
        
                if(num%2 == 0) // 0 is considered to be an even number
                    printf("\n\n%d is an Even number\n\n",num);
                else
                    printf("\n\n%d is an Odd number\n\n",num);
                break;

            case 4:
                printf("Enter numbers to divide:\n");
                scanf("%d %d", &n1,&n2);
                printf("\n The result is %d\n",divide(n1,n2));
                break;

            case 5:
                exit(0);    // terminates the complete program execution
        }
    }
   
}
