#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
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
////////////////////////////////////////////////////
	FILE *myfile2;
    char content2[200]="";
    int max2 = 0 ;
    int N2=0;
    int i = 0, j=0;
    char d='\0';
 //////////////////////////////////////////////////
	FILE *fptr;
	//FILE *fn;
    char filename[200], c;
    int max3=0;
	int temp=0;
	//char file2name[200],k;
	FILE *fp;
	//char file3name[200],m;
//////////////////////////////////////////////////////
    FILE *fptrr;
	//FILE *fn1;
    char filename4[200], r;
    int max4=0;

    int opt;
    //char version,help;
   
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
        printf("head: cannot open %s for reading: No such file or directory \n", argv[i]);
        exit(0);
    }

//    while (c != EOF)
  while (NULL != fgets(filename4, 200, fptrr))
    {
      if (max4 > 9)  // check required lines are reached or not. if reached then break the loop.
            break;
        max4++;
	 //   fgets(filename4, 200, fptrr);
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
    // Open file
    myfile = fopen(argv[3], "r");// passing one argument. file in read only mode.

    if (myfile == NULL)      // check content of the file is null or not
    {
        printf("head: cannot open %s for reading: No such file or directory \n", argv[3]);
        exit(0);
    }
    //Read the first 10 lines from file
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
    // Loop to read required byte
    // of file
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

    // Print the bytes as string
    printf("%s", content2);
    fclose(myfile2);
    return 0;
}
# ifndef S_SPLINT_S
if(NH ==1)
{
    //print("qqqqqqqqqqq");
 for(int i=2;i<argc;i++)
    {
     fptr = fopen(argv[i], "r");// passing one argument. file in read only mode.
      //  printf("==> %s <==\n",argv[1]);
    
    if (fptr == NULL)
    {
        printf("head: cannot open '%s' for reading: No such file or directory \n", argv[i]);
        exit(0);
    }

    while (NULL != fgets(filename, 200, fptr))
    {
      if (max > 9)  // check required lines are reached or not. if reached then break the loop.
            break;
        max++;
        printf("%s", filename);	
//	    fgets(filename, 100, fptr);
		
	}
	max=0;
	memset(filename,0,sizeof(filename));
	fclose(fptr);
  }
}

	/*fn = fopen(argv[3], "r");// passing one argument. file in read only mode.
       // printf("==> %s <==\n",argv[2]);
    
    if (fn == NULL)
    {
    //    printf("Cannot open file \n");
        exit(0);
    }

    while (NULL != fgets(file2name,200, fn))
    {
      if (temp > 9)  // check required lines are reached or not. if reached then break the loop.
            break;
        temp++;
		
        printf("%s", file2name);	
//	    fgets(file2name, 100, fn);
		
	}
	fclose(fn);

	temp = 0;
	fp = fopen(argv[4], "r");// passing one argument. file in read only mode.
        //  printf("==> %s <==\n",argv[1]);
      
      if (fp == NULL)
      {   
         // printf("Cannot open file \n");
          exit(0);
      }
      
      while (NULL != fgets(file3name, 200, fp))
      {
		  
        if (temp > 9)  // check required lines are reached or not. if reached then break the loop.
              break;
          temp++;
          printf("%s", file3name);
      }
     fclose(fp);
*/


//printf("%d %d %d",Line,Byte,argc);
if(NH != 1 && H !=1 && Line !=1 && Byte != 1)
{
	int z=argc;
    for(int i=1;i<z;i++)
    {
    // Open file
    myfile = fopen(argv[i], "r");// passing one argument. file in read only mode.

    if (myfile == NULL)      // check content of the file is null or not
    {
        printf("head: cannot open %s for reading: No such file or directory \n", argv[i]);
        exit(0);
    }
    //Read the first 10 lines from file
//30.04.22    fgets(content, 200, myfile); //library function fgets(); reads a line from the specified stream and stores it into the string pointed to.

    N = 9;
//    while (*content != EOF) // run while loop until EOF appear
	while (NULL != fgets(content, 200, myfile))
	
    {
       // max++;
 if (max > N)  // check required lines are reached or not. if reached then break the loop.
            break;
		//	max++;
        printf("%s", content);
		max++;
       // fgets(content, 200, myfile);//library function fgets(); reads a line from the specified stream and stores it into the string pointed to.
    }
    max=0;
   memset(content,0,sizeof(content));
    fclose(myfile); //close the file
//	printf("shubham");
 }
}
# endif
   return 0;	
}
