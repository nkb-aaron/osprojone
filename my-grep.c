#include <stdio.h>
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
   /* for loop execution */
   for( a = 2; a < argc - 1; a = a + 1 ){
      printf("Matching Text in File: %d\n", a - 1);
   
    FILE *fp;
    char str[MAXCHAR];
    char* filename = argv[a];
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        printf("\n");
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL){
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
	}
        
    printf("\n");
    fclose(fp);
}
    return 0;
}
