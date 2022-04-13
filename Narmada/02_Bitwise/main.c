#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h;

	printf("a) Want addmission in next Grade..??\n");
	scanf("%d",&a);
	printf("b) You passes in Maths..??\n");
	scanf("%d",&b);
	printf("c) You passes in Physics..??\n");
	scanf("%d",&c);
	printf("d) You passes in Chemistry..??\n");
	scanf("%d",&d);
	printf("e) You passes in Biology..??\n");
	scanf("%d",&e);
	printf("f) You passes in English..??\n");
	scanf("%d",&f);
	printf("g) You passes in History..??\n");
	scanf("%d",&g);
	printf("h) You passes in Arts..??\n");
	scanf("%d",&h);


	
	printf("a) Your answer is %d\t \t\n",a);
	printf("b) You passes in Math   %d\t\t\n",b);
	printf("c) You passes in Physics%d\t\t\n",c);
	printf("d) You passes in Chemistry%d\t\t\n",d);
	printf("e) You passes in Biology%d\t\t\n",e);
	printf("f) You passes in English%d\t\t\n",f);
	printf("g) You passes in History%d\t\t\n",g);
	printf("h) You passes in Arts%d\t\t\n",h);


	if(a && b && c && d && e && f && g && h == 1)
	{
		printf("-----------    You are Allowed to take addmission      ------------\n");
	}
	else
	{
		printf("-----------    You ar not allowed to take addmission    -----------\n");
	}
}
