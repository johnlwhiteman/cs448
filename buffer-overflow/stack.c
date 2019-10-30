#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  
    char buffy[3];
 
    if (argc < 2) {
        printf("Please add a string\n");
        return 1;
    } 
    
    strcpy(buffy, argv[1]);
    return 0;
}

