OBJECTS = digit/add.o digit/decr.o digit/incr.o \
	digit/mem.o digit/mul.o digit/pow.o digit/print.o \
	digit/div.o digit/string.o digit/cmp-funs.o  


CFLAGS = -O3 -Wall -g -lgmp -lm -I. -Iinclude -Itests


install: add mul
	cp build/add build/mul /usr/local/bin

add : $(OBJECTS)
	gcc -O3 -Wall -g  -lm -I. -Iinclude  arit/$@.c $(OBJECTS) \
	-o build/$@ 

mul : $(OBJECTS)
	gcc -O3 -Wall -g  -lm -I. -Iinclude arit/$@.c $(OBJECTS) \
	-o build/$@

taddrand : $(OBJECTS)
	gcc  tests/$@.c $(OBJECTS)  tests/aux-tests.c \
	-o build/$@  $(CFLAGS)

tmulrand : $(OBJECTS)
	gcc tests/$@.c $(CFLAGS) $(OBJECTS) -I. -Iinclude tests/aux-tests.c \
	-o build/$@ -lgmp -lm

tdiv-dui : $(OBJECTS)
	gcc  tests/$@.c $(OBJECTS)  tests/aux-tests.c  \
	-o build/$@ $(CFLAGS)


clean :
	rm $(OBJECTS)
	rm build/*
