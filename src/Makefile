CFLAGS += -std=c99

all: chordgen pictDB_server

cg_utils.o: cg_utils.c
chordgen.o: chordgen.c chordgen.h

chordgen: chordgen.o cg_utils.o

clean:
	rm *.o
