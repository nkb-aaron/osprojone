#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#define MAXCHAR 1000
int main(int argc, char *argv[]) {
	int a;
	char* sub = argv[1];
	
	if(argc == 0 || argv[1] == NULL){
		printf("my-grep: searchterm[file ...]");
		printf("\n");
		return 1;
	}
	
	//check stadard input
	if(argc == 1 || argv[2] == NULL){
		char str2[MAXCHAR];
	    fgets(str2, MAXCHAR, stdin);
	    int i, j=0, k;
		  for(i=0; str2[i]; i++)
		  {
		    if(str2[i] == sub[j])
		    {
		      for(k=i, j=0; str2[k] && sub[j]; j++, k++)
		        if(str2[k]!=sub[j])
		            break;
		       if(!sub[j]){
		        printf("%s", str2);
		        
				}
		    }
		  }
	    //printf("result = %zd, n = %zu, line = \"%s\"\n", result, n, line);
	    //free(line);
		return 0;
	}
	
   /* for loop execution */
   for( a = 2; a < argc - 1; a = a + 1 ){
      //printf("Matching Text in File: %d\n", a - 1);
   
    FILE *fp;
    char str[MAXCHAR];
    char* filename = argv[a];
    
    
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("my-grep: cannot open file");
        printf("\n");
        return 1;
    }
    //fgets(str, MAXCHAR, fp) != NULL
    /*while (getline(fp, str) != NULL){
    	int i, j=0, k;
		  for(i=0; str[i]; i++)
		  {
		    if(str[i] == sub[j])
		    {
		      for(k=i, j=0; str[k] && sub[j]; j++, k++)
		        if(str[k]!=sub[j])
		            break;
		       if(!sub[j]){
		        printf("%s", str);
		        
				}
		    }
		  }
	}*/
	
	size_t buffer_size = 80;
    char *buffer = malloc(buffer_size * sizeof(char));

    // read each line and print it to the screen
    int line_number = 0;
    while(-1 != getline(&buffer, &buffer_size, fp))
    {
        //printf("%d: %s", ++line_number, buffer);
        int i, j=0, k;
		  for(i=0; buffer[i]; i++)
		  {
		    if(buffer[i] == sub[j])
		    {
		      for(k=i, j=0; buffer[k] && sub[j]; j++, k++)
		        if(buffer[k]!=sub[j])
		            break;
		       if(!sub[j]){
		        printf("%s", buffer);
		        
				}
		    }
		  }
    }
        
    printf("\n");
    fclose(fp);
}
    return 0;
}
