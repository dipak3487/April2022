#include <stdio.h>
int main()
{
    int a=4;
    float b;
    double c;
    char d;
    char *pstr[10];
    int *ip;
    int *parr[10];
    float *pf;
    unsigned int u;
    long l;
    unsigned long ul;
    short si; 
    
    
    printf("Size of int %d\n " ,sizeof(a));
    printf("Size of char pointer string %d\n", sizeof(*pstr));
    printf("Size of pointer int %d\n",sizeof(*ip));
    printf("Size of Integer Pointer Array %d\n",sizeof(*parr));   
    printf("Size of integer %d",sizeof(int));
    printf("Size of Float %d \n",sizeof(float));
    printf("Size of double=%d \n",sizeof(double));
    printf("Size of Unsigned Integer %d\n",sizeof(u));
    printf("Size of char=%d \n",sizeof(char));
    printf("Size of long =%d \n",sizeof(long));
    printf("Size of Unsigned long %d\n",sizeof(ul));
    printf("Size of Short is %d \n",sizeof(short));

    return 0;
}
