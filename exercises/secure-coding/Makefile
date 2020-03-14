.PHONY: all clean

all: heartbleed memleak printf printfX

heartbleed: heartbleed.c
	gcc -g $< -o $@

badmem: memleak.c
	gcc -g $< -o $@

printf: printf.c
	gcc -g $< -o $@

printfX: printf.c
	gcc -Wno-format-extra-args -Wformat-security -g $< -o $@

clean:
	rm -f heartbleed memleak printf printfX
