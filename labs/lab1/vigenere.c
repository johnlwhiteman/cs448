#include <stdio.h>

void showUsage(void);

int main(int argc, char **argv) {

    /* Your code goes here */

    /* comment out */
    showUsage();

    return 0;
}

void showUsage() {

    printf("\nVigenère is a simple substitution cipher program\n");

    printf("\nUse Case: Argument-Based\
          \n\nE(k,p): vigenere -e -k 'k' -i 'p'\
          \nD(k,c): vigenere -d -k 'k' -i 'p'\n\n");

    printf("Use Case: File-Based\
          \n\nE(k,p): vigenere -E -k 'kpath' -i 'ppath' -o 'cpath'\
          \nD(k,c): vigenere -D -k 'kpath' -i 'cpath' -o 'ppath'\n\n");

    printf("k: key\
        \np: plaintext\
        \nc: ciphertext\
        \nE(k,p): Encrypt\
        \nD(k,c): Decrypt\
        \ni: input or path to input file\
        \no: path to output file\n\n");
}
