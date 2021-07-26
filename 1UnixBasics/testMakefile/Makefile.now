#VPATH = hellolib
vpath % hellolib
#vpath %.h hellolib
objects = proMain.o hello.o


hello : $(objects)
	gcc -o hello $(objects)

proMain.o : hello.h
hello.o : hello.h
#	gcc -c hellolib/hello.c

.PHONY : clean
clean : cleanobj 
	rm hello
cleanobj:
	rm *.o
