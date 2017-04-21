IDIR =../include 
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = romdec.hpp catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testes.o romdec.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testes: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: all testes clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
