FROM ubuntu:18.04
WORKDIR /home
RUN apt-get update
RUN mkdir /home/afl
RUN cd ./afl
RUN apt-get install build-essential git gnuplot -y

# Not allowed to do this in Docker
# RUN bash -c 'echo "core" > /proc/sys/kernel/core_pattern'
RUN ulimit -c unlimited
RUN git clone https://github.com/mirrorer/afl.git 


#&& cd afl && make && make install
