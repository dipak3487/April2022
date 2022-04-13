


#include<stdio.h>
#include<stdlib.h>

int main()

{
        int n,a,b,c,d,e,f,g;

        printf("Hii.!!,Want an admission in the next grade? :\n");
	printf("Please enter, 1 for YES and 0 for NO\n");       
        scanf("%d",&n);

	if(n==1)
        {
                printf("passed in maths?\t");
                scanf("%d",&a);

                 printf("passed in Physics?\t");
                scanf("%d",&b);

                 printf("passed in Chemistry?\t");
                scanf("%d",&c);

                 printf("passed in Biology?\t");
                scanf("%d",&d);

                 printf("passed in English?\t");
                scanf("%d",&e);

                printf("passed in History?\t");
                scanf("%d",&f);

                printf("passed in Arts?\t\t");
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








































