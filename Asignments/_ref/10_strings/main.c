#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include<ctype.h>

int main(int argc, char *argv[])
{
	char str1[100] = "";
	char str2[20] = "";
	int iarr[10];
	int iarr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int len = 0;
	int result = 0;
	char *p = NULL;

	printf("argv[1]=[%s]\n", argv[1]);
	printf("str1[%s], str2[%s]\n", str1, str2);


	//copy argv[1] into str1.
	strncpy(str1, argv[1], sizeof(str1)-1);
	str1[100] = '\0';
	

	strncpy(str2, str1, sizeof(str2)-1);
	str2[20] = '\0';

	printf("str1[%s]\n", str1);
	printf("str2[%s]\n", str2);

	len = strlen(str2);
	for(int i=0; i<strlen(str2)/2; i++)
	{
		//e.g. ABCDEF	len=6.
		//swap(str2[i], str2[len-i-1] );
		str2[i] = str2[i] ^ str2[len - i - 1];
		str2[len - i - 1] = str2[i] ^ str2[len - i - 1];
		str2[i] = str2[i] ^ str2[len - i - 1];
		
	}

	printf("Reverse of str2[%s]\n", str2);

	p = strstr(str2, "ABC");
	if(NULL == p)
	{
		printf("The string does not contain ABC.\n");
	}
	else
	{
		printf("The string contains ABC. Suppressed!\n");
		strncpy(p, "***", 3);
	}
	printf("Now str2 is = [%s]\n", str2);
	

	result = strcmp(str2, "pqr");
	if( 0 == result)
	{
		printf("The string is exactly pqr\n");
	}
	else
	{
		printf("The string is not pqr\n");
		if(result > 0)
		{
			printf("The string[%s] is larger than pqr\n", str2);
		}else
		{
			printf("The string[%s] is less than pqr\n", str2);
		}
	}

	exit(EXIT_SUCCESS);
}
