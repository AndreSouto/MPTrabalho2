IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs
 
ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = catch.hpp romdec.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = romdec.o testes.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testes: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIBS) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
