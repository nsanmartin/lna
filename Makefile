OBJECTS = digit/add.o digit/decr.o digit/incr.o \
	digit/mem.o digit/mul.o digit/pow.o digit/print.o \
	digit/div.o digit/string.o digit/cmp-funs.o  


CFLAGS = -O3 -Wall -g -lgmp -lm -I. -Iinclude -Itests


add : $(OBJECTS)
	gcc arit/$@.c $(OBJECTS) -o build/$@ $(CFLAGS)

mul : $(OBJECTS)
	gcc arit/$@.c $(OBJECTS) -o build/$@ $(CFLAGS)

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