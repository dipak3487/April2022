#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *myfile;
    char content[200];
    int max = 0 ;
	int N;

    // Open file
    myfile = fopen(argv[1], "r");
    if (myfile == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    // Read the first 10 lines from file
    fgets(content, 200, myfile);
    
	if(argv[2] == NULL)
	{
		N = 10;
	}
	else
	{

		N = atoi(argv[2]);
	}


	while (content != EOF)
    {
        max++;
        if (max > N)
            break;
        printf("%s", content);
        fgets(content, 200, myfile);
    }
	fclose(myfile);
    return 0;
}
       
