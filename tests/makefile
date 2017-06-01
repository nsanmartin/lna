OBJECTS = ../digit/add.o ../digit/decr.o ../digit/incr.o \
	../digit/malloc.o ../digit/mul.o ../digit/pow.o ../digit/print.o \
	../digit/string.o

CFLAGS = -lgmp -lm -I../include

add : $(OBJECTS)
	gcc  $(OBJECTS) $(CFLAGS)  add-TT.c -o add

add-cmp : $(OBJECTS) 
	gcc  $(OBJECTS) -I. -I../include add-TT-cmp.c aux-tests.c \
	-o add-cmp -lgmp -lm

multiplicador : $(OBJECTS)
	gcc $(OBJECTS) $(CFLAGS) multiplicador.c -o multiplicador \
	-lgmp -lm
clean :
	rm $(OBJECTS)
