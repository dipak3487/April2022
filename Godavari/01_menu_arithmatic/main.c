#include<stdio.h>
#include<stdlib.h>

int main()
{
<<<<<<< HEAD
    printf("\n\n\t\tGanga - Menu driven program 01\n\n\n");
    int choice, num, i;
    unsigned long int fact;

    while(1)
    {
        printf("1. Factorial \n");
        printf("2. Prime\n");
        printf("3. Odd\\Even\n");
        printf("4. Exit\n\n\n");
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
                printf("\n\n\t\t\tCoding is Fun !\n\n\n");
                exit(0);    // terminates the complete program execution
        }
    }
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}

=======
   int i,a,b,ch;
 while(1)
 {
   printf("HELLO AND WELCOME\n");
   printf("\t1:ADD\n\t2:Subtract\n\t3:Multiply\n\t4:Divide\n\t5:Exit\n");
   printf("Enter the  choice \n");
   scanf("%d",&ch);

   switch(ch)
     {
          case 1:printf("enter the two nos a \n");
                 scanf("%d\n%d",&a,&b);
                    i=a+b;
                printf(" Addition is %d ",i);
         break;

         case 2:printf("enter the two nos a\n");
                scanf("%d\n%d",&a,&b);
                 i=a-b;
               printf(" Subtraction  is %d ",i);
         break;
         case 3:printf("enter the two nos\n");
                scanf("%d\n%d",&a,&b);
                 i=a *b;
               printf(" Multiply  is %d ",i);
        break;
         case 4:printf("enter the two nos\n");
                scanf("%d\n%d",&a,&b);
                 i=a/b;
               printf(" Divide is %d ",i);
        break;


         case 5 :
                 printf("END of project\n");
                    exit(0);
         break;

     }
  }
   return 0;
 }
>>>>>>> 9a8cb8725b93158e20418d8a1f4f56908d3aee08
