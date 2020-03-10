#include <stdio.h>
#include <string.h>
#define MAX 7

int main(int argc, char **argv) {

    char password[MAX];
    char attempt[MAX];

    if (argc < 2) return 1;

    strcpy(password, "secret");
    strcpy(attempt, argv[1]);

    printf("Password: [%s]\n", password);

    if (0 == strncmp(attempt, password, MAX))
        printf("Login Successful\n");
    else
        printf("Bad Human!\n");

    return 0;
}
