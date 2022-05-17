#include <stdio.h> 
#include <stdlib.h> 
#include <sys/stat.h> 
#include <string.h>

int main(int argc, char **argv) 
{
 if(strcmp(argv[1],"-help") == 0)
 {
	 printf("mytac - concatenate and print files in reverse \n mytac [OPTION]... [FILE].. \n Write each FILE to standard output, last line first \n With no FILE, or when FILE is -, read standard input. \n -help display this help and exit \n -version  output version information and exit ");
	exit(0);
 }
 if(strcmp(argv[1],"-version") == 0)
 {
	 printf("mytac version2 by Team Kaveri");
	 exit(0);
 }
 struct stat st;       
 char *p, *q;                
 int k=1;
 while(k < argc)
{
	FILE *fh = fopen(argv[k], "r");    
 if(!fh)
 {
	 printf("mytac: failed to open %s for reading: No such file or directory\n",argv[k]);
	 exit(0);
 }  
 if(fstat(fileno(fh), &st))
 {
	 perror(argv[1]);
	 exit(0);
 }
// printf("size of st %ld",st.st_size);
 p = malloc(st.st_size*2);    
 fread(p, sizeof(char), (st.st_size*2), fh);  
 fclose(fh);                     
 q = p + st.st_size;
 *q = '\0'; 
  
 while(--q >= p) {            
    if(*q == '\n')
	{
		*q = '\0';
		puts(1+q);
		
	} 

 }
 k++;
free(p);
}
 return 0;    
}
