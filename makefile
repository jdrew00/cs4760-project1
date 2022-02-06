CC=gcc
CFLAGS=-I.
OBJ = chain.o 

chain: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	-rm *.o $(objects) chain