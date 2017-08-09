OBJECTS = ../digit/add.o ../digit/decr.o ../digit/incr.o \
	../digit/mem.o ../digit/mul.o ../digit/pow.o ../digit/print.o \
	../digit/div.o ../digit/string.o ../digit/cmp-funs.o  

CFLAGS = -Wall -g -lgmp -lm -I. -I../include 

add : $(OBJECTS)
	gcc  $(OBJECTS)  add-dd.c aux-tests.c \
	-o build/add  $(CFLAGS)

addrand : $(OBJECTS)
	gcc $(OBJECTS)  addrand.c aux-tests.c \
	-o build/addrand $(CFLAGS)


drnd : $(OBJECTS)
	gcc  $(OBJECTS) -I. -I../include drnd.c aux-tests.c \
	-o build/drnd -lgmp -lm

addset : $(OBJECTS)
	gcc  $(OBJECTS) -I. -I../include add-setdd.c aux-tests.c \
	-o build/addset -lgmp -lm

addsetrand : $(OBJECTS)
	gcc  $(OBJECTS) -I. -I../include add-setddrand.c aux-tests.c \
	-o build/addsetrand -lgmp -lm

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
	gcc -g $(OBJECTS) -I. -I../include aux-tests.c mul-dd.c \
	-o build/mul -lgmp -lm


mulfile : $(OBJECTS)
	gcc -g $(OBJECTS) -I. -I../include aux-tests.c mul-file.c \
	-o build/mulfile -lgmp -lm


mulrand : $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -I. -I../include aux-tests.c mulrand.c \
	-o build/mulrand -lgmp -lm

copy : $(OBJECTS)
	gcc $(OBJECTS) -I. -I../include aux-tests.c copy.c \
	-o build/copy -lgmp -lm


copyrand : $(OBJECTS)
	gcc $(OBJECTS) -I. -I../include aux-tests.c copyrand.c \
	-o build/copyrand -lgmp -lm

strtodec : $(OBJECTS)
	gcc $(OBJECTS) -I. -I../include aux-tests.c strtodec.c
	\ -o build/strtodec -lgmp -lm


divdui : $(OBJECTS)
	gcc -g $(OBJECTS) -I. -I../include aux-tests.c div-dui.c  \
	-o build/divdui -lgmp -lm


divduipt : $(OBJECTS)
	gcc -g $(OBJECTS) -I. -I../include aux-tests.c div-dui-input.c  \
	-o build/divduipt -lgmp -lm


divug : $(OBJECTS)
	gcc -g $(OBJECTS) -I. -I../include aux-tests.c div-bug-test.c  \
	-o build/divug -lgmp -lm

clean :
	rm $(OBJECTS)
