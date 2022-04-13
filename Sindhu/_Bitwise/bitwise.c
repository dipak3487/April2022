#include<stdio.h>

int main()
{
 	int a,b,c,d,e,f,g,h;
        printf("Please Enter your response as  Yes => 1 and No=> 0\n");
     
	printf("\nWant admission in Next Grade?");
        scanf("%d",&a);
       
        if(a == 0){
	printf("You opted not to take admission..\n");
	}	
        else if(a==1){
	printf("\nAre you passes in Maths?");
        scanf("%d",&b);
        printf("Are you passed in Physics?");
        scanf("%d",&c);
        printf("Are you passed in Chemistry?");
        scanf("%d",&d);
        printf("Are you passed in Biology?");
        scanf("%d",&e);
        printf("Are you passed in English?");
        scanf("%d",&f);
        printf("Are you passed in Histroy?");
        scanf("%d",&g);
        printf("Are you passed in Arts?");
        scanf("%d",&h);

        if(a & b & c & d & e & f & g & h){
        printf("\nCongratulation!!! You got the Admission...\n");
        }
        else{
                printf("\nSorry...You could not get admission.\n");
        }
	}
	else{
		printf("Invalid Input\n");
	}
        
}
