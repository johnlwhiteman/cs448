# Dependencies
* $ sudo apt-get install gnuplot -y

# Environment Setup
* $ sudo sh -c 'echo core >/proc/sys/kernel/core_pattern'   # Support core dumps 
* $ ulimit -c unlimited # Core dumpls unlimited size

# Build AFL
* $ git clone https://github.com/mirrorer/afl.git
* $ cd ./afl
* $ make
* $ sudo make install
* $ cd ../

# Build Fuzz Goat
* $ git clone https://github.com/fuzzstati0n/fuzzgoat.git
* $ cd ./fuzzgoat
* $ make
* $ objdump ./fuzzgoat # See instrumentation

# Execution
* $ afl-fuzz -i in -o out ./fuzzgoat @@ 
* # OR $ make afl
* # Wait forever or hit ctrl-c

# Graph results
* $ afl-plot ./out ./charts
* $ cd ./charts
* $ firefox index &

# Reproduction
* ./fuzzgoat <input json path>   # Just replace path with one under ./out/crashes

# References
* [AFL Home Page](https://lcamtuf.coredump.cx/afl/)
* [AFL Stats](https://github.com/google/AFL/blob/master/docs/status_screen.txt)
