#include <stdio.h>
#include <string.h>
#define MAX 7

int main(int argc, char **argv) {

    /* String Literal ... Crash, not OW */
    char *password = "secret";
    char attempt[MAX];

    if (argc < 2) return 1;

    /* Use a SAFE function ... only MAX bytes */
    strncpy(attempt, argv[1], sizeof(attempt));

    printf("Password: [%s]\n", password);

    /* Compare the whoe string */
    if (0 == strcmp(attempt, password))
        printf("Login Successful\n");
    else
        printf("Bad Human!\n");

    return 0;
}
