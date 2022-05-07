#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<getopt.h>

int main(int argc,char *argv[])
{
 int opt;
  
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
					printf("help");
					exit(0);
				break;
				default:
					printf("Try './mycat -h' for more information.");
				}
	}
	
	int o = strlen(argv[1]);
  if (o > 1)
   {
	int k=1;
	//printf("%d",argc);
	while(k < argc)
	{
	int fdold,count;
	char buffer[2048];
	fdold = open(argv[k], O_RDONLY);
	if(fdold==-1)
	{
		printf("cat: %s. No such file or directory\n",argv[k]);
		//exit(1);
		}
	while((count = read(fdold,buffer,sizeof(buffer)))>0)
	{
		printf("%s",buffer);
		//printf("$");
		memset(buffer,0,sizeof(buffer));
	}
	close(fdold);
	k++;	
	}
  }
	exit(0);
}

