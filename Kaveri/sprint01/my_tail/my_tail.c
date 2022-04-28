#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	FILE *fp;
    int count = 0;
    long int pos;
    char s[100];
    int N;
	int cnt = 0;
    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("tail: cannot open '%s' for reading: No such file or directory", argv[1]);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);

	if(argv[2]==NULL)
	{
		N = 10;
	}
	else if(strcmp(argv[2],"-n")==0)
	{
		N = atoi(argv[3]);
	}

	else
	{
		N = atoi(argv[2]);
	}
//	if(strcmp(argv[2],"-n")==0)

		pos = ftell(fp);
		while (pos) {
        fseek(fp, --pos, SEEK_SET); 
        if (fgetc(fp) == '\n') {
            if (count++ == N) break;
        }
    }
    
    while (fgets(s, sizeof(s), fp) != NULL) {
	    printf("%s", s);
    }
    fclose(fp);
    return 0;
}
