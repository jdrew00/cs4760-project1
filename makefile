CC=gcc
CFLAGS=-I.
#DEPS = hellomake.h
OBJ = chain.o 

#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

chain: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~