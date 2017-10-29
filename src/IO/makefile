IO: clean
	gcc -Wall Input.c -c
	gcc -Wall Output.c -c

Driver: clean
	gcc -Wall Input.c -c
	gcc -Wall Output.c -c
	gcc Driver.c Input.c -o Driver -Wall -lcunit

.PHONY: clean

clean: 
	rm -rf *.o *~ core Driver
