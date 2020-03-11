.PHONY: all clean

all: stack1 stack2 stack3 stack4 aslr

stack1: stack1.c
	gcc $< -o $@


stack2: stack2.c
	gcc $< -o $@


stack3: stack3.c
	gcc $< -o $@


stack4: stack4.c
	gcc $< -o $@

aslr:  aslr.c
	gcc -fPIE -fno-stack-protector -z execstack -g -o $@ $< 

stack: stack.c
	gcc -O0 -fno-stack-protector -z execstack $< -o $@

clean:
	rm -f stack1 stack2 stack3 stack4 aslr
