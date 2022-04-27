#include <stdio.h> 
#include <stdlib.h> 
#include <sys/stat.h> 
  
 int main(int argc, char *argv[]) 
{ 
 struct stat st;       
 char *p, *q;                
  
 FILE *fh = fopen(argv[1], "r");    
 if(!fh) { perror(argv[1]); exit(1); }  
 if(fstat(fileno(fh), &st)) { perror(argv[1]); exit(1); } 
 p = malloc(st.st_size);    
 fread(p, sizeof(char), st.st_size, fh);  
 fclose(fh);                     
 q = p + st.st_size; *q = '\0'; 
  
 while(--q >= p) {            
    if(*q == '\n') { puts(1+q); *q = '\0'; } 
 }          
 return 0;    
}
