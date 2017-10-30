CC=gcc
IDIR = qsolve/
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib


LIBS=-lm

_DEPS = *.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))



$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)



qsolver: $(OBJ)
	gcc main.c qsolve/*.c IO/Input.c Log/CloseLog.c Log/OpenLog.c -o $@ $^ $(CFLAGS) -IIO/ -ILog/ -I/lib/include -lcunit -L/lib/CUnit/lib $(LIBS)

#qsolver:  
#	gcc main.c qsolve/*.c -o qsolver -Iqsolve/ -IIO/ -ILog/ -I/lib/include -lcunit -L/lib/CUnit/lib -lm


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
