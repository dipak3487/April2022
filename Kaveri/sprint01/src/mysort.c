/*

	Filename: mysort.c

	created on: 25th Apr 2022

	Description: prints the sorted file the user gave as input 


*/

/*
	function name: linecountfile(const char *filename)

	created on: 25th Apr 2022

	Description: counts the number of lines in a file

*/
/*
	function name: sortfile(char **array, int linecount)

	created on: 25th Apr 2022

	Description: sorts the lines in an array

	

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 4096

unsigned long int lineCountFile(const char *filename)
{
    FILE *fp=NULL;
	fp= fopen(filename, "r");
    unsigned long int linecount = 0;
    int c=0;
    if(fp == NULL){
        return 0;
    }
    while((c=fgetc(fp)) != EOF )
    {
        if(c == '\n')
            linecount++;
    }
    fclose(fp);
    return linecount;
}

void sortfile(char **array, int linecount)
{
    int i=0, j=0;
    char t[MAX_LINE]="";

    for(i=1;i<linecount;i++)
    {
        for(j=1;j<linecount;j++)
        {
            if(strcmp(array[j-1], array[j]) > 0)
            {
                strcpy(t, array[j-1]);
                strcpy(array[j-1], array[j]);
                strcpy(array[j], t);
            }
        }
    }
}


int main(int argc, char **argv)
{
    FILE *fileIN=NULL; 
	char *in=NULL;
	if(strcmp(argv[1],"-o") == 0 || strcmp(argv[1],"-r") == 0)
	{ 
		fileIN = fopen(argv[2], "r");
		in =argv[2];
	}
	else if(strcmp(argv[1],"-help") == 0)
	{
		printf("usage: mysort [OPTION]... [FILE]... \n Write sorted concatenation of all FILE(s) to standard output. \n With no FILE, or when FILE is -, read standard input. \n -o, --output=FILE \n write result to FILE instead of standard output \n -r -reverse reverse the result of comparisons \n --help display this help and exit \n --version output version information and exit \n ");
		exit(0);
	}
	else if(strcmp(argv[1],"-version") == 0)
	{
		printf("mysort version2 by team kaveri \n");
		exit(0);
	}
	else
	{		
		fileIN = fopen(argv[1], "r");
		in = argv[1];
	}
	FILE *fp=NULL;
    if(!fileIN)
    {
		printf("mysort cannont read %s: no such file or directory",argv[1]);
        exit(0);
    }

    unsigned long int linecount = lineCountFile(in);
    

    char **array = (char**)malloc(linecount * sizeof(char*));
    char singleline[MAX_LINE]="";

    int i = 0;
    while(fgets(singleline, MAX_LINE, fileIN) != NULL)
    {
        array[i] = (char*) malloc (MAX_LINE * sizeof(char));
        singleline[MAX_LINE] = '\0';
        strcpy(array[i], singleline);
        i++;
    }

    sortfile(array, linecount);
	if(strcmp(argv[1],"-o") == 0)
	{
		fp =fopen(argv[3],"w+");
		if(fp == NULL)
		{
			printf("written file must be entered");
			exit(0);
		}
	}
    for(i=0; i<linecount; i++)
    {
		if(strcmp(argv[1],"-o") == 0)
		{
			fputs(array[i],fp);
		}
		else if(strcmp(argv[1],"-r") == 0)
		{
			printf("%s ",array[(linecount-1)-i]);
		}
		else
		{
			printf("%s ", array[i]);
		}
    }
    fclose(fileIN);
	if(strcmp(argv[1],"-o") == 0)
		fclose(fp);


    for(i=0; i<linecount; i++)
    {
        free(array[i]);
    }
    free(array);

    return 0;
}
