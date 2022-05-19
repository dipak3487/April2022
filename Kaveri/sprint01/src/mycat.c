#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<getopt.h>

int main(int argc,char *argv[])
{
int opt=0;
int o = 0;
int k=1;
static struct option long_options[] = {
        {"version", no_argument,       0,  'a' },
        {"help", no_argument,       0,  'h' },
        { NULL, 0,     NULL, 0 },
    };
while((opt = getopt_long(argc, argv, "ah:",long_options,NULL)) != -1)
{
    switch (opt) {
                		
				case 'a':
                    			printf("mycat  (Team Kaveri) version 2 \n written by Team Kaveri\n");
                    			exit(0);
				break;
				case 'h':
					printf(" mycat - concatenate files and print on the standard output \n usage: mycat [OPTION]... [FILE].. \n Concatenate FILE(s) to standard output.\n With no FILE, or when FILE is -, read standard input.\n --h display this help and exit \n -a  output version information and exit \n");
					exit(0);
				break;
				default:
					printf("Try './mycat --h' for more information.");
				}
	}
	o=strlen(argv[1]);
   if(o > 1)
   {
	while(k < argc)
	{
	int fdold=0;
	int count=0;
	char buffer[2048]="";
	fdold = open(argv[k], O_RDONLY);
	if(fdold==-1)
	{
		printf("mycat: %s. No such file or directory\n",argv[k]);
	}
	while((count = read(fdold,buffer,sizeof(buffer)))>0)
	{
		printf("%s",buffer);
		memset(buffer,0,sizeof(buffer));
	}
	close(fdold);
	k++;	
	}
  }
}
