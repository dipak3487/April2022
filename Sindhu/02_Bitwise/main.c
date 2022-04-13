


#include<stdio.h>
#include<stdlib.h>

int main()

{
        int n,a,b,c,d,e,f,g;

        printf("Want admission in the next grade? :");
        scanf("%d",&n);

	if(n==1)
        {
                printf("passed in maths?");
                scanf("%d",&a);

                 printf("passed in Physics?");
                scanf("%d",&b);

                 printf("passed in Chemistry?");
                scanf("%d",&c);

                 printf("passed in Biology?");
                scanf("%d",&d);

                 printf("passed in English?");
                scanf("%d",&e);

                printf("passed in History?");
                scanf("%d",&f);

                printf("passed in Arts?");
                scanf("%d",&g);


        printf("Your answers are:\n");
        printf("%d\n",a);
        printf("%d\n",b);
        printf("%d\n",c);
        printf("%d\n",d);
        printf("%d\n",e);
        printf("%d\n",f);
        printf("%d\n",g);


        if(a&&b&&c&&d&&e&&f&&g==1)
{
         printf("You got the admission, Congratulations");
}
        else
{
        printf("You could not get the admission, Sorry");
}


}
else{printf("Ok bye\n");}


}








































