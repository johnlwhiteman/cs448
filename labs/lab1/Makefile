.PHONY: clean

all: vigenere

vigenere: vigenere.c
	gcc -Wall -o $@ $<

sign: signCode
	./signCode

verify: verifySign 
	./verifySign
 
clean:
	rm -f vigenere sign.* *.pem *.pub *.bin *.sig *.256
