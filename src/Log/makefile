Log: clean
	gcc -Wall CloseLog.c -c
	gcc -Wall OpenLog.c -c
	gcc -Wall WriteLog.c -c

Driver: clean
	gcc -Wall CloseLog.c -c
	gcc -Wall OpenLog.c -c
	gcc -Wall WriteLog.c -c
	gcc Driver.c OpenLog.c WriteLog.c CloseLog.c -o Driver -Wall -lcunit

.PHONY: clean

clean: 
	rm -rf *.o *~ core Driver
