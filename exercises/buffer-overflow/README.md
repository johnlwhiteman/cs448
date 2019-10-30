## Setup

`$ ../../no-aslr`

`$ make clean`

`$ make all`

## Simple test with OS/Compiler Protections

$ ./s1 aaaaa

$ ./s1 aaaaaa

What do you observe?

## Simple test without OS/Compiler Protections

`$ ./s2 aaaaa`

`$ ./s2 aaaaaa`

What happened? And why is this bad?

How many a's does it take to get a segmentation fault (core dump)?

## Cleanup

`$ ../../yes-aslr`

`$ make clean`

