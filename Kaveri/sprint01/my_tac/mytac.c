#include <stdio.h> 
#include <stdlib.h> 
#include <sys/stat.h> 
#include <string.h>

int main(int argc, char **argv) 
{
 if(strcmp(argv[1],"-help") == 0)
 {
	 printf("tac - concatenate and print files in reverse \n tac [OPTION]... [FILE].. \n Write each FILE to standard output, last line first \n With no FILE, or when FILE is -, read standard input. \n --help display this help and exit \n --version  output version information and exit ");
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
	 exit(1);
 }  
 if(fstat(fileno(fh), &st))
 {
	 perror(argv[1]);
	 exit(1);
 } 
 p = malloc(st.st_size);    
 fread(p, sizeof(char), st.st_size, fh);  
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
}
 return 0;    
}
