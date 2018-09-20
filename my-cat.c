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
	
	if(argc == 0 || argv[1] == NULL){
		return 0;
	}
   /* for loop execution */
   for( a = 1; a < argc; a = a + 1 ){
      //printf("Text in File: %d\n", a);
   
    FILE *fop;
    char str[MAXCHAR];
    char* filename = argv[a];
 
    fop = fopen(filename, "r");
    if (fop == NULL){
        printf("my-cat: cannot open file");
        printf("\n");
        return 1;
    }
    while (fgets(str, MAXCHAR, fop) != NULL)
        printf("%s", str);
    fclose(fop);
}
    return 0;
}
