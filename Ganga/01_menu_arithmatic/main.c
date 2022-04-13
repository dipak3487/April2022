#include<stdio.h>
#include<stdlib.h>
int main()
{
    printf("\n\n\t\tGANGA  TEAM MEMBER\n\n\n");
    int choice, num, i,n1,n2,add,sub,mul,divide;
    unsigned long int fact;

    while(1)
    {
        printf("1. Factorial \n");
        printf("2. Prime\n");
        printf("3. Odd\\Even\n");
        printf("4. ADDITION\n");
        printf("5. SUBTRACTION\n");
        printf("6. MULTIPLE\n");
        printf("7. DIVISION\n");
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
  if(i == num)
                {
                    printf("\n\n%d is a Prime number\n\n", num);
                    break;
                }

            case 3:
                printf("Enter number:\n");
                scanf("%d",&num);

                if(num%2 == 0) // 0 is considered to be an even number
                    printf("\n\n%d is an Even number\n\n",num);
                else
                    printf("\n\n%d is an Odd number\n\n",num);
                break;

            case 4:
                printf("Enter the two Number:\n");
                scanf("%d %d",&n1,&n2);
                add = n1 + n2;
                printf("ADDITION :%d\n",add);
                break;
           case 5:
                printf("Enter the two Number:\n");
                scanf("%d %d",&n1,&n2);
                 sub = n1 - n2;
                printf("SUBSTRACTION :%d\n",sub);
                 break;

           case 6:
                 printf("Enter the two Number:\n");
                 scanf("%d %d",&n1,&n2);
                 mul = n1 * n2;
                 printf("MUL :%d\n",mul);
                 break;

           case 7:
                printf("Enter the two  Number:\n");
                scanf("%d %d",&n1,&n2);
                 divide = n1 / n2;
                 printf("DIV :%d\n",divide);
                 break;


            case 8:
                printf("\n\n\t\t\tCoding is Fun !\n\n\n");
                exit(0);    // terminates the complete program execution
 }
    }
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;

}
