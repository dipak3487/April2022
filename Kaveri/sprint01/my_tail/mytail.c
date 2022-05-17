#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<getopt.h>

int main(int argc, char *argv[])
{
    FILE *fp, *fptr;
    int fd,read_byte;
    int count = 0;
    int opt;
	int linecount;
	//char version,help;
    FILE *in;
    long int pos;
    char s[200];
    int N;
	int Line = 0,Byte=0;
    //char ch;
    char l[21];
    //int cnt = 0, O=0;
	int H = 0;
	int NH = 0;
    static struct option long_options[] = {
        {"lines", required_argument,       0,  'n' },
        {"bytes", required_argument,       0,  'c' },
        {"version", no_argument,       0,  'a' },
        {"help", no_argument,       0,  'h' },
		{"verbose", no_argument,       0,  'v' },
		{"silent", no_argument,		0,'q'},
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
					printf("Mytail  (Team Kaveri) version 2 \n written by Team Kaveri\n");
					exit(0);
				break;
				case 'q':
					NH =1;
				break;
				case 'v':
					H=1;
				break;
				case 'h':
					printf("Usage: mytail [OPTION]... [FILE]... \n Print the last 10 lines of each FILE to standard output.\t With more than one FILE, precede each with a header giving the file name \n Mandatory arguments to long options are mandatory for short options too. \n c, --bytes=[+]NUM       output the last NUM bytes;\n-n, --lines=[+]NUM       output the last NUM lines, instead of the last 10 lines \n -q, --quiet, --silent    never output headers giving file name \n  -v, --verbose            always output headers giving file names.\n -h  display this help and exit \n -a   output version information and exit.\n ");
					exit(0);
				break;				
				default:
					printf("Try 'mytail -h' for more information.");
			}
}
# ifndef S_SPLINT_S
if(H == 1)
{
   linecount=0;
   int c;
  N =10;
  int k = argc;
  for(int i=2;i<k;i++)
		{
			printf("==> %s <==\n",argv[i]);
			fptr = fopen(argv[i], "r");
			
			
				if (fptr == NULL)
				{
					printf("Cannot open file \n");
					exit(0);
				}
			while((c=fgetc(fptr)) != EOF )
				{
					if(c == '\n')
					{
						linecount++;
					}
				}
			fseek(fptr, 0, SEEK_END);
			pos = ftell(fptr);
			while (pos) {
			fseek(fptr, --pos, SEEK_SET);
			if(linecount >N)
			{if (fgetc(fptr) == '\n') {
				if (count++ == N) break;
				}
			}
			}
		   while (fgets(s, sizeof(s), fptr) != NULL) {
			 printf("%s", s);
			   } 
			   linecount =0;
			   count = 0;
			    memset(s,0,sizeof(s)); 
				fclose(fptr);
		  }      
}
# endif
if (Line == 1)
{
   linecount=0;
   int c;
   fp =fopen(argv[3],"r");
   if (fp == NULL) {
        printf("tail: cannot open '%s' for reading: No such file or directory", argv[3]);
        exit(EXIT_FAILURE);
    }
    while((c=fgetc(fp)) != EOF )
				{
					if(c == '\n')
					{
						linecount++;
					}
				}
   N = atoi(argv[2]);
   fseek(fp, 0, SEEK_END);
   pos = ftell(fp);
   while (pos) {
        fseek(fp, --pos, SEEK_SET);
        if(linecount >N)
			{if (fgetc(fp) == '\n') {
           if (count++ == N) break;
           }
        }
        }
   while (fgets(s, sizeof(s), fp) != NULL) {
         printf("%s", s);
   }
   linecount =0;
   count =0;
  fclose(fp);          
}
if(Byte ==1)
{
	 fd = open(argv[3], O_RDONLY);
               if (fd == -1)
               {
                printf("tail: cannot open '%s' for reading: No such file or directory", argv[3]);
                exit(EXIT_FAILURE);
               }
               N = atoi(argv[2]);
               lseek(fd, -N, SEEK_END);
               read_byte = read(fd, l, N); // Read 20 bytes
               l[read_byte] = '\0';
               printf("%s\n", l);
               close(fd);

}
# ifndef S_SPLINT_S
if(NH == 1)
{
 	N= 10;
 	linecount = 0;
	int c;
	{
		for(int i=2;i<argc;i++)
		{
			fptr = fopen(argv[i], "r");
			
				if (fptr == NULL)
				{
					printf("Cannot open file \n");
					exit(0);
				}
			
			while((c=fgetc(fptr)) != EOF )
				{
					if(c == '\n')
					{
						linecount++;
					}
				}
			fseek(fptr, 0, SEEK_END);
			pos = ftell(fptr);
			while (pos) {
			fseek(fptr, --pos, SEEK_SET);
			if(linecount >N)
			{if (fgetc(fptr) == '\n') {
				if (count++ == N) break;
				}
			}
			}
		   while (fgets(s, sizeof(s), fptr) != NULL) {
			 printf("%s", s);
			   }
			   count = 0;
			   linecount=0;
			    memset(s,0,sizeof(s)); 
				fclose(fptr);
		  }
		       
	}
}
# endif
//printf("%d %d %d",Line,Byte,argc);
# ifndef S_SPLINT_S
if(NH != 1 && H !=1 && Line !=1 && Byte != 1)
{
	N =10;
	linecount = 0;
	int c;
	for(int i=1;i<argc;i++)
	{
	in =fopen(argv[i],"r");
	if (in == NULL) {
        printf("mytail: cannot open '%s' for reading: No such file or directory", argv[i]);
        exit(EXIT_FAILURE);
    		}
    	while((c=fgetc(in)) != EOF )
				{
					if(c == '\n')
					{
						linecount++;
					}
				}
		fseek(in, 0, SEEK_END);
		pos = ftell(in);
        while (pos) {
        fseek(in, --pos, SEEK_SET);
        if(linecount >N)
			{if (fgetc(in) == '\n') {
            if (count++ == N) break;
        }
        }
    }
    count =0;
    linecount =0;
    while (fgets(s, sizeof(s), in) != NULL) {
        printf("%s", s);
    }
    memset(s,0,sizeof(s));
	fclose(in);
   }
}
# endif
return 0;
}
