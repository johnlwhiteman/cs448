.PHONY: all clean

all: printf printfX

printf: printf.c
	gcc -g $< -o $@

printfX: printf.c
	gcc -Wno-format-extra-args -Wformat-security -g $< -o $@

clean:
	rm -f printf printfX
