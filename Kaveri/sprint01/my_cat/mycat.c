#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[])

{
	if(argc!=2){
		printf("\nThe syntax should as be follow");
		printf("\nCommandname filestoread\n");
		exit(1);
	}
	int fdold,count;
	char buffer[2048];
	fdold = open(argv[1], O_RDONLY);
	if(fdold==-1)
	{
		printf("cannot open file");
		exit(1);
	}
	while((count = read(fdold,buffer,sizeof(buffer)))>0)
	{
		printf("%s",buffer);
	}
	exit(0);
}

