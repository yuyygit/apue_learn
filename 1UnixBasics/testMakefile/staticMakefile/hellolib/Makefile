#objects := $(wildcard *.o)
src := $(wildcard *.c)
objects : $(src)
	$(CC) -c $(CFLAGS) $< 
.PHONY : clean
clean:
	rm *.o
