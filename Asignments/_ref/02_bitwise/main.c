#include <stdlib.h>
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
	//int a, b, c, d, e, f, g, h;
	unsigned char ans = 0;
	unsigned char mask = 1;
	unsigned char passCount = 0;

	ans = takeUserInput("a) Want admission in next grade? : "); 

	ans <<=1;
	ans |= takeUserInput("b) You passed in math? : ");
	
	ans <<=1;
	ans |= takeUserInput("c) You passed in Pysics? : ");

	ans <<=1;
	ans |= takeUserInput("d) You passed in Chemistry? : ");

	ans <<=1;
	ans |= takeUserInput("e) You passed in Biology? : ");

	ans <<=1;
	ans |= takeUserInput("f) You passed in English? : ");

	ans <<=1;
	ans |= takeUserInput("g) You passed in History? : ");

	ans <<=1;
	ans |= takeUserInput("h) You passed in Arts? : ");


	printf("Your answers are: %x \n", ans);
	
	//allow if all passed.
	//if(0xff == ans)

	//student should be intrested and should pass maths and physics
	// xxxx xxxx
	// 111x xxxx <= give admission
	// 1110 0000 
	// e0

	//if( (ans & 0xe0) == 0xe0 )	// maths and pysics must pass.

					  // a==1 && (b+c+d+e+f+g+h) >= 6)
	
	//mask = 1;
	// xxxx xxxx
	// 0000 0001
	// 0000 0010

	for(int i=0; i<7; i++)
	{
		if(ans & mask) passCount++;
		mask <<= 1;
	}
	printf("passCount=%d\n",passCount);

	if(0xff == ans || ((0x80&ans) && (6 >= passCount) ))
	{
        printf("You got the admission!\n");
    }
    else
    {
        printf("You haven't got the admission...\n");
    }


	return EXIT_SUCCESS;
}
