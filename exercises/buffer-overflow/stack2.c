#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

    int  isAuthenticatedFlag = 0;
    char buffer[5];

    if (argc < 2) return 1;

    strcpy(buffer, argv[1]);

    printf("Input [%d]: %d\n", strlen(argv[1]),
                               isAuthenticatedFlag);

    return 0;
}
