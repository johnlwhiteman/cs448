#include <stdlib.h>
#include <stdio.h>

/*
    # Quick demonstration of ASLR

    # Compile
    $ gcc -fPIE -fno-stack-protector -z execstack -g -o adx adx.c
    # Disable ASLR
    $ sudo echo 0 >/proc/sys/kernel/randomize_va_space
    $ ./aslr
    $ ./aslr
    # Observe that the address remains the same
    # Enable ASLR
    sudo echo 2 >/proc/sys/kernel/randomize_va_space
    ./aslr
    ./aslr
    # Observe that the address changes
    # Note: You can also use ldd ./adx or ldd /bin/bash
    # Thanks Urban Penguin
*/

int main(int argc, char **argv) {
    printf("Address: %p\n", __builtin_return_address(0)-0x5);
    return 0;
}
