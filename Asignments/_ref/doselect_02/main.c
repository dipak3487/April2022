#include<stdio.h>
#include <stdlib.h>
#include<string.h>

char findSmallestLargerThan(char *str, char ch)
{
	char ret = 0;
	int index = -1;
	for(int i = 0; i<strlen(str); i++)
	{
		if(str[i] > ch)
		{
			if(ret == 0 || str[i] < ret)
			{
				ret = str[i];
				index = i;
			}
		}
	}
	//shift rest
	ret = str[index];
	for(int j = index; j<strlen(str); j++)
	{
		str[j] = str[j+1];
	}
	return ret;
}


char findLargestSmallerThan(char *str, char ch)
{
    char ret = 0;
	int index = -1;
    for(int i = 0; i<strlen(str); i++)
    {
        if(str[i] < ch)
        {
            if(ret == 0 || str[i] > ret)
            {
                ret = str[i];
				index = i;
            }
        }
    }
	//shift rest
	ret = str[index];
	for(int j = index; j<strlen(str); j++)
	{
		str[j] = str[j+1];
	}
    return ret;
}



char* sort( char *str)
{
	int len = strlen(str);
	char ch = '\0';
	char *newStr = malloc(len);
	memset(newStr, 0, len);

	int asc = 1;

	for(int i=0; i<len; i++)
	{
		if( asc)
		{
			ch = findSmallestLargerThan(str, ch);
		}
		else
		{
			ch = findLargestSmallerThan(str, ch);
		}

		printf("asc=%d, str[%s], newStr[%s], ch[%c], i[%d]\n",asc, str, newStr, ch, i);

		if(0 == ch)
		{
			asc++;
			asc %= 2;
			ch = newStr[i-1];
			if(asc) ch--;
			else ch++;
			i--;
		}
		else
		{
			newStr[i] = ch;
		}
	}
			 
	return newStr;

}


int main(int argc, char *argv[])
{

	char *newStr = sort(argv[1]);

	printf("New string: %s\n", newStr);
	return 0;

}
