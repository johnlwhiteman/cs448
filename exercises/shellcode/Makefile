.PHONY: all clean
 
all: demo victim 

demo: demo.c
	gcc -O0 -fPIE -fno-stack-protector -z execstack -g $< -o $@

victim: victim.c
	gcc -O0 -fno-stack-protector -z execstack $< -o $@

clean:
	rm -f demo victim 
