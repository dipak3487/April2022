/*
	Filename : myhead.c
	Created On : 25th April 2022
	Description : This file contains the source code to print the first 'n' lines as per the input provided by the user.
*/


#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
int main(int argc, char *argv[])
{
FILE *myfile; //pointing to txt file
    char content[200]; //char array of size 200
    int max = 0 ;
    int N=0;
	FILE *myfile2;
    char content2[200]="";
    int i = 0, j=0;
    char d='\0';
	FILE *fptr;
	char filename[200];
	int temp=0;
	FILE *fp;
    FILE *fptrr;
    char filename4[200];
    int max4=0;
    int opt;
 
   
    int Line = 0,Byte=0;
    int H = 0;
    int NH = 0;
    static struct option long_options[] = {
        {"lines", required_argument,       0,  'n' },
        {"bytes", required_argument,       0,  'c' },
        {"version", no_argument,       0,  'a' },
        {"help", no_argument,       0,  'h' },
        {"verbose", no_argument,       0,  'v' },
        {"silent", no_argument,     0,'q'},
        { NULL, 0,     NULL, 0 },
    };
while((opt = getopt_long(argc, argv, "ncahqv:",long_options,NULL)) != -1)
{
    switch (opt) {
                case 'n':
                    Line = 1;
                break;
                case 'c':
                    Byte = 1;
                break;
                case 'a':
                    printf("myhead  (Team Kaveri) version 2 \n written by Team Kaveri");
                    exit(0);
                break;
                case 'q':
                    NH =1;
                break;
                case 'v':
                    H=1;
                break;
                case 'h':
				printf("Usage: myhead [OPTION]... [FILE]... \n print the first NUM lines of each FILE to standard output. \n Mandatory arguments to long options are mandatory for short options too. \n -c, --bytes=[+]NUM output the first NUM bytes;\n -n, --lines=[+]NUM output the first NUM lines, instead of the first 10 lines \n -q, --quiet, --silent never output headers giving file name \n -v, --verbose always prints headers giving file names.\n -h  display this help and exit \n -a   output version information and exit. \n");
                    exit(0);
                break;
                default:
                printf(" Try 'myhead -h' for more information.\n");
                break;
            }
}
# ifndef S_SPLINT_S
if(H == 1)
{
	int k = argc;
	for(int i=2;i<k;i++)
	{
	fptrr = fopen(argv[i], "r");// passing one argument. file in read only mode.
        printf("==> %s <==\n",argv[i]);

    if (fptrr == NULL)
    {
        printf("myhead: cannot open %s for reading: No such file or directory \n", argv[i]);
        exit(0);
    }

  while (NULL != fgets(filename4, 200, fptrr))
    {
      if (max4 > 9)  // check required lines are reached or not. if reached then break the loop.
            break;
        max4++;
        printf("%s", filename4);
		
	}
	max4=0;
	memset(filename4,0,sizeof(filename4));
fclose(fptrr);
}
}
# endif
if (Line == 1)
{ 
    myfile = fopen(argv[3], "r");// passing one argument. file in read only mode.
    if (myfile == NULL)      // check content of the file is null or not
    {
        printf("myhead: cannot open %s for reading: No such file or directory \n", argv[3]);
        exit(0);
    }
    
    fgets(content, 200, myfile); //library function fgets(); reads a line from the specified stream and stores it into the string pointed to.
	
    N = atoi(argv[2]);
    while (*content != EOF) // run while loop until EOF appear
    {
        max++;
		if (max > N)  // check required lines are reached or not. if reached then break the loop.
         {
			 break;
		 }
        printf("%s", content);
        fgets(content, 200, myfile);//library function fgets(); reads a line from the specified stream and stores it into the string pointed to.
    }
    fclose(myfile); //close the file
    return 0;   
}
if(Byte ==1)
{
	myfile2 = fopen(argv[3], "r");
    if (myfile2 == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
        N = atoi(argv[2]);
    
    for (i = 0, j = 0; i <= N && d != EOF; i++)
	{
       // Skip the bytes not required
           if (i >= 1)
           {
			     content2[j]=d;
				j++;
		   }
        // Get the characters
         d = fgetc(myfile2);
    }
    
    printf("%s", content2);
    fclose(myfile2);
    return 0;
}
# ifndef S_SPLINT_S
if(NH ==1)
{
    
 for(int i=2;i<argc;i++)
    {
     fptr = fopen(argv[i], "r");// passing one argument. file in read only mode.
    
    
    if (fptr == NULL)
    {
        printf("myhead: cannot open '%s' for reading: No such file or directory \n", argv[i]);
        exit(0);
    }
    while (NULL != fgets(filename, 200, fptr))
    {
      if (max > 9)  // check required lines are reached or not. if reached then break the loop.
            break;
        max++;
        printf("%s", filename);	
		
	}
	max=0;
	memset(filename,0,sizeof(filename));
	fclose(fptr);
  }
}

if(NH != 1 && H !=1 && Line !=1 && Byte != 1)
{
	int z=argc;
    for(int i=1;i<z;i++)
    {
    
    myfile = fopen(argv[i], "r");// passing one argument. file in read only mode.
    if (myfile == NULL)      // check content of the file is null or not
    {
        printf("myhead: cannot open %s for reading: No such file or directory \n", argv[i]);
        exit(0);
    }
    
    N = 9;

	while (NULL != fgets(content, 200, myfile))
	
    {
       // max++;
 if (max > N)  // check required lines are reached or not. if reached then break the loop.
            break;
		//	max++;
        printf("%s", content);
		max++;
       
    }
    max=0;
   memset(content,0,sizeof(content));
    fclose(myfile); //close the file
 }
}
# endif
   return 0;	
}
