#include <stdio.h>
#include <string.h>

void func(char *str) {
    char buf[100];
    strcpy(buf, str);
    printf("%s\n", buf);
}

int main(int argc, char *argv[]) {
    func(argv[1]);
    return 0;
}
