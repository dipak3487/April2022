//c program to print given number of lines from beginning of a file
//file name and number of lines must be supply as command line argument

#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
 
int main(int argc, char * argv[])
{
    FILE    *   fp;             // file pointer
    char    *   line = NULL;
    int         len  = 0;
 
    int cnt = 0;
	char n=0;
	//char check="n";
 
    if( argc < 3)
    {
        printf("Insufficient Arguments!!!\n");
        printf("Please use \"program-name file-name N\" format.\n");
        return -1;
    }
 
    // open file
    fp = fopen(argv[1],"r");
 
    // checking for file is exist or not
    if( fp == NULL )
    {
        printf("\n%s file can not be opened !!!\n",argv[1]);
        return 1;   
    }
 
    // read lines from file one by one
    while (getline(&line, &len, fp) != -1)
    {
		//if(atoi(argv[2])== -n)
		if(strcmp(argv[2],"-n")==0)


{
        cnt++;
        if ( cnt > atoi(argv[3]) )
            break;
        
        printf("%s",line); fflush(stdout);
		}
		else
		{
			printf("error");
}
    }
     
    // close file
    fclose(fp);
 
    return 0;
}

