OBJECTS = ../digit/add.o ../digit/decr.o ../digit/incr.o \
	../digit/mem.o ../digit/mul.o ../digit/pow.o ../digit/print.o \
	../digit/string.o

CFLAGS = -g -lgmp -lm -I../include

add : $(OBJECTS)
	gcc  $(OBJECTS) -I. -I../include add-dd.c aux-tests.c -o build/add \
	-lgmp -lm

addrand : $(OBJECTS)
	gcc  $(OBJECTS) -I. -I../include addrand.c aux-tests.c \
	-o build/addrand -lgmp -lm


drnd : $(OBJECTS)
	gcc  $(OBJECTS) -I. -I../include drnd.c aux-tests.c \
	-o build/drnd -lgmp -lm

addset : $(OBJECTS)
	gcc  $(OBJECTS) -I. -I../include add-setdd.c aux-tests.c \
	-o build/addset -lgmp -lm

addTT-cmp : $(OBJECTS) 
	gcc  $(OBJECTS) -I. -I../include add-TT-cmp.c aux-tests.c \
	-o build/add-cmp -lgmp -lm

multiplicador : $(OBJECTS)
	gcc $(OBJECTS) $(CFLAGS) multiplicador.c -o build/multiplicador \
	-lgmp -lm

muldui : $(OBJECTS)
	gcc $(OBJECTS) -I. -I../include aux-tests.c mul-dui.c -o build/muldui \
	-lgmp -lm


mul : $(OBJECTS)
	gcc -g $(OBJECTS) -I. -I../include aux-tests.c mul-dd.c -o build/mul \
	-lgmp -lm

copy : $(OBJECTS)
	gcc $(OBJECTS) -I. -I../include aux-tests.c copy.c -o build/copy \
	-lgmp -lm


copyrand : $(OBJECTS)
	gcc $(OBJECTS) -I. -I../include aux-tests.c copyrand.c \
	-o build/copyrand -lgmp -lm

strtodec : $(OBJECTS)
	gcc $(OBJECTS) -I. -I../include aux-tests.c strtodec.c
	\ -o build/strtodec -lgmp -lm

clean :
	rm $(OBJECTS)
