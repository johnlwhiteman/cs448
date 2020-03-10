.PHONY: all clean
 
all: demo victim 

demo: demo.c
	gcc -O0 -fno-stack-protector -z execstack $< -o $@

victim: victim.c
	gcc -O0 -fno-stack-protector -z execstack $< -o $@

clean:
	rm -f demo victim 
