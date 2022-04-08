#include<stdio.h>
#include<stdlib.h>

int main()
{
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
