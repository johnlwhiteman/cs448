#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

    int isAuthenticatedFlag = 0;
    char buffer[5];

    if (argc < 2) {
        printf("Please enter some text\n");
        return 1;
    }

    strcpy(buffer, argv[1]);

    printf("isAuthenticatedFlag: %d\n", isAuthenticatedFlag);
    return 0;
}
