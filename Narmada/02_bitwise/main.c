/*Praveen
Nishant
Gopal
Vinit
Rohit
Aishwarya
*/


#include<stdio.h>


int takeUserInput(char *message)
{
	int userInput = 0;
	printf("%s", message);
	scanf("%d", &userInput);
	return userInput;
}
int main()
{
	printf("\n\n\n\t\t This program is from team Narmada\n\n\n\n");
	int a,b,c,d,e,f,g,h;
	
	printf("a) Want to take admission in next grade\n\n");
	scanf("%d", &a);
	printf("b) You passed in math?\n\n");
	scanf("%d", &b);
	printf("b) You passed in physics?\n\n");
        scanf("%d", &c);
	printf("b) You passed in chemistry?\n\n");
        scanf("%d", &d);
	printf("b) You passed in biology?\n\n");
        scanf("%d", &e);
	printf("b) You passed in english?\n\n");
        scanf("%d", &f);
	printf("b) You passed in history?\n\n");
        scanf("%d", &g);
	printf("b) You passed in arts?\n\n");
        scanf("%d", &h);


	printf("Your answers are :\n");
	printf("Ans (a) =%d\n ", a);
        printf("Ans (b) =%d\n ", b);
        printf("Ans (c) =%d\n ", c);
        printf("Ans (d) =%d\n ", d);
        printf("Ans (e) =%d\n ", e);
        printf("Ans (f) =%d\n ", f);
	printf("Ans (g) =%d\n ", g);
	printf("Ans (h) =%d\n ", h);

	if(a && b && c && d && e && f && g && h == 1)
	{
		printf("You got the admission\n");
	}
	else
	{
		printf("You did not get the admission\n");
	}

	//allow failure in one subject

/*	if((a==1) && ((b+c+d+e+f+g+h)) >=  6)
	{
		printf("You got the admission\n");
	}

	else
	{
		printf("You did not get the admission\n");
	}*/

	return 0;
}

