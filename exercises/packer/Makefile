.PHONY: clean

packme:  packme.c
	gcc -static -o packme packme.c

pack: packme 
	rm -f packed && upx -o packed packme 

clean:
	rm -f packme packed
