#FROM ubuntu:18.04
FROM i386/ubuntu:14.04
WORKDIR /home
RUN apt-get update
RUN mkdir /home/shellcode
RUN cd ./shellcode
COPY Makefile ./
COPY demo.c ./
COPY victim.c ./
COPY disableASLR ./
COPY enableASLR ./
COPY exploit ./
RUN make all
