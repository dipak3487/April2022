/*
RAJESH
SHAREEF SHAIK
JIDNYESH PATIL
ASHUTOSH UPADHYAY
PAPAIAH
*/

#include <stdio.h>

int main(){

	int a,b,c,d,e,f,g,h;
	
	printf("want admission in next grade\n");

	scanf("%d", &a);

	printf("you passed in math\n");
	scanf("%d", &b);

	printf("you passed in physics?:\n");
	scanf("%d", &c);

	printf("you passed in chemistry?:\n");
	scanf("%d", &d);

	printf("you passed in biology?:\n");
	scanf("%d", &e);

	printf("you passed in english?:\n");
	scanf("%d", &f);

	printf("you passed in history?:\n");
	scanf("%d", &g);

	printf("you passed in arts?:\n");
	scanf("%d", &h);

	printf("Your amswers are:\n");
	printf("Ans (a) = %d\n", a);
	printf("Ans (a) = %d\n", b);
	printf("Ans (a) = %d\n", c);
	printf("Ans (a) = %d\n", d);
	printf("Ans (a) = %d\n", e);
	printf("Ans (a) = %d\n", f);
	printf("Ans (a) = %d\n", g);
	printf("Ans (a) = %d\n", h);


	if ((a==1)&&(b==1)&&(c==1)&&(d==1)&&(e==1)&&(f==1)&&(g==1)&&(h==1))

	{

		printf("you got the admission\n");

	}
	else
	{
		printf("you did not got the admission\n");
	}

	if (a==0)
	{
		printf("want admission for next grade enter 1\n ");
	}
	/*if
	
	((a==1) && (b+c+d+e+f+g+h)>=6);
	{
		printf("you got the admission\n");

	}
	else
	{
		printf("you did not get the admission\n");
	}*/	

	return 0;
}

