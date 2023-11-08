IDIR = include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR= src

LIBS=-lm -lssl -lcrypto

_DEPS = breaking_into.h input.h output.h free.h encrypt.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o breaking_into.o input.o output.o free.o encrypt.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
