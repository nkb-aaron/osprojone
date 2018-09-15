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
	
   /* for loop execution */
   for( a = 1; a < argc; a = a + 1 ){
      printf("Text in File: %d\n", a);
   
    FILE *fop;
    char str[MAXCHAR];
    char* filename = argv[a];
 
    fop = fopen(filename, "r");
    if (fop == NULL){
        printf("Could not open file %s",filename);
        printf("\n");
        return 1;
    }
    while (fgets(str, MAXCHAR, fop) != NULL)
        printf("%s", str);
    printf("\n");
    fclose(fop);
}
    return 0;
}
