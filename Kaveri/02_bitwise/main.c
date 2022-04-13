/*
Team kaveri

chaitanya
Kodari Suresh
Madduri Raghuram
Piyush
Renu Shantaram Wagh
*/




#include<stdio.h>

int main()
{
        int a,b,c,d,e,f,g,h;
        printf("want admission in next grade\n");
        scanf("%d",&a);
        printf("r u passed in math?:\n");
        scanf("%d",&b);
        printf("r u passed in physics?:\n");
        scanf("%d",&c);
        printf("r u passed in chemistry?:\n");
        scanf("%d",&d);
        printf("r u passed in biology?:\n");
        scanf("%d",&e);
        printf("r u passed in english?:\n");
        scanf("%d",&f);
        printf("r u passed in history?:\n");
        scanf("%d",&g);
        printf("r u passed in arts?:\n");
        scanf("%d",&h);

        if((a==1)&&(b==1)&&(c==1)&&(d==1)&&(e==1)&&(f==1)&&(g==1)&&(h==1))
        {
                printf("you got admission\n");
        }
        else
        {
                printf("you did not got admission\n");
        }
        if(a==0)
        {
                printf("want admission in next grade enter 1\n");
        }

        return 0;

}

 


