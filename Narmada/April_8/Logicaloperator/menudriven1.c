#include<stdio.h>
#include<stdlib.h>


int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    int choice, num, i,a,b;

    while(1)
    {
        printf("1. Addition \n");
        printf("2. Substraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
	printf("5. Exit\n\n\n");

        printf("Enter your choice :  ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter First Number:\n");
                scanf("%d", &a);
                printf("Enter Second Number:\n");
                scanf("%d", &b);
                num =a+b;
	      	printf("\n\n Addition %d is\n\n\n",num);
                break;
        
            case 2:
                printf("Enter First Number:\n");
                scanf("%d", &a);
                printf("Enter second Number:\n");
                scanf("%d", &b);
                if(a>b)
		{num = a-b;
                printf("\n Substraction %d is\n\n",num);
		break;
		}
		else
                    printf("\n\n Bigger Number Cannot Be Substracted \n\n");
                    break;

        
            case 3:
                printf("Enter First Number:\n");
                scanf("%d", &a);
                printf("Enter Second Number:\n");
                scanf("%d", &b);
                num = a*b;
                printf("\n\n%d Multiplication is %d\n\n",num);
                break;
        
            case 4:
                printf("Enter First Number:\n");
                scanf("%d", &a);
                printf("Enter Second Number:\n");
	        scanf("%d", &b);
                num = a/b ;

                printf("\n\n Division is %d\n\n",num);
		break;
	    
	    case 5:
		exit(0);
        }
    }
   
}
