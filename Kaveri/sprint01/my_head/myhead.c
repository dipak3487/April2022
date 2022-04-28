#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])  //The parameters to main represent the command line parameters
{
    FILE *myfile; //pointing to txt file
    char content[200];
    int max = 0 ;
    int N;

    // Open file
    myfile = fopen(argv[1], "r");

    if (myfile == NULL)      // check content of the file is null or not
    {
        printf("head: cannot open %s for reading: No such file or directory \n", argv[1]);
        exit(0);
    }
    //Read the first 10 lines from file
    fgets(content, 200, myfile); //library function fgets(); reads a line from the specified stream and stores it into the string pointed to.

    if(argv[2] == NULL) // check the second argument is avilable or not
    {
        N = 10;
    }

    else if(strcmp(argv[2],"-n")==0) // check whether "-n" is valibale at second orgument or not
    {

        N = atoi(argv[3]); // pass the value of third argument to the integer N
    }

    else // direct value given in second argument 
    {

        N = atoi(argv[2]); // pass the value of second argument to the integer N
    }while (*content != EOF) // run while loop until EOF appear
    {
        max++;
        if (max > N)  // check required lines are reached or not. if reached then break the loop.
            break;
        printf("%s", content);
        fgets(content, 200, myfile);//library function fgets(); reads a line from the specified stream and stores it into the string pointed to.
    }
    fclose(myfile); //close the file
    return 0;
}
