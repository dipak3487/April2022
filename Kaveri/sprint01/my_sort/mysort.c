#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000

unsigned long int lineCountFile(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    unsigned long int linecount = 0;
    int c;
    if(fp == NULL){
        fclose(fp);
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
    int i, j;
    char t[MAX_LINE];

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
    char *in = argv[1]; 

    FILE *fileIN; 

    fileIN = fopen(in, "r");
    if(!fileIN)
    {
		printf("sort: cannot read: %s: No such file or directory\n",argv[1]);
        exit(0);
    }

    unsigned long int linecount = lineCountFile(in);
    

    char **array = (char**)malloc(linecount * sizeof(char*));
    char singleline[MAX_LINE];

    int i = 0;
    while(fgets(singleline, MAX_LINE, fileIN) != NULL)
    {
        array[i] = (char*) malloc (MAX_LINE * sizeof(char));
        singleline[MAX_LINE] = '\0';
        strcpy(array[i], singleline);
        i++;
    }

    sortfile(array, linecount);

    for(i=0; i<linecount; i++)
    {
        printf("%s\n", array[i]);
    }


    fclose(fileIN);
 

    for(i=0; i<linecount; i++)
    {
        free(array[i]);
    }
    free(array);

    return 0;
}
