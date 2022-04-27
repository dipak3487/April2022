#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    FILE *fp;
    int count = 0;
    long int pos;
    char s[100];
    int N = 10;
    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("the file you requested is not here.");
//		printf("%s",fp);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0, SEEK_END);
//	printf("enter the no.of lines you want to print");
//	scanf("%d",&N);
//	argv[2]=N;
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
