OBJECTS = ../digit/add.o ../digit/decr.o ../digit/incr.o \
	../digit/mem.o ../digit/mul.o ../digit/pow.o ../digit/print.o \
	../digit/string.o

CFLAGS = -g -lgmp -lm -I../include

add : $(OBJECTS)
	gcc  $(OBJECTS) -I. -I../include add-dd.c aux-tests.c -o add \
	-lgmp -lm


addset : $(OBJECTS)
	gcc  $(OBJECTS) -I. -I../include add-setdd.c aux-tests.c -o addset \
	-lgmp -lm

addTT-cmp : $(OBJECTS) 
	gcc  $(OBJECTS) -I. -I../include add-TT-cmp.c aux-tests.c \
	-o add-cmp -lgmp -lm

multiplicador : $(OBJECTS)
	gcc $(OBJECTS) $(CFLAGS) multiplicador.c -o multiplicador \
	-lgmp -lm

muldui : $(OBJECTS)
	gcc $(OBJECTS) -I. -I../include aux-tests.c mul-dui.c -o muldui \
	-lgmp -lm


mul : $(OBJECTS)
	gcc -g $(OBJECTS) -I. -I../include aux-tests.c mul-dd.c -o mul \
	-lgmp -lm

copy : $(OBJECTS)
	gcc $(OBJECTS) -I. -I../include aux-tests.c copy.c -o copy \
	-lgmp -lm

clean :
	rm $(OBJECTS)
