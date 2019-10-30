.PHONY: all clean


all: s1 s2


s1: stack.c
	gcc $< -o $@

s2: stack.c
	gcc -O0 -fno-stack-protector -z execstack $< -o $@

clean:
	rm -f s1 s2
