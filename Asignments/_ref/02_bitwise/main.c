#include <stdlib.h>
#include<stdio.h>
int main()
{
	int a, b, c, d, e, f, g, h;

	printf("a) Want admission in next grade? : "); 
	scanf("%d", &a);
	printf("b) You passed in math? : ");
	scanf("%d", &b);
	printf("c) You passed in Pysics? : ");
	scanf("%d", &c);
	printf("d) You passed in Chemistry? : ");
	scanf("%d", &d);
	printf("e) You passed in Biology? : ");
	scanf("%d", &e);
	printf("f) You passed in English? : ");
	scanf("%d", &f);
	printf("g) You passed in History? : ");
	scanf("%d", &g);
	printf("h) You passed in Arts? : ");
	scanf("%d", &h);

	printf("Your answers are:\n");
	printf("Ans (a) = %d\n", a);
	printf("Ans (b) = %d\n", b);
	printf("Ans (c) = %d\n", c);
	printf("Ans (d) = %d\n", d);
	printf("Ans (e) = %d\n", e);
	printf("Ans (f) = %d\n", f);
	printf("Ans (g) = %d\n", g);
	
	if( a & b & c & d & e & f & g & h)
	{
		printf("You got the admission!\n");
	}
	else
	{
		printf("You haven't got the admission...\n");
	}


	return EXIT_SUCCESS;
}
