CC=gcc
CFLAGS=-I.
DEPS = skip_list.h
OBJ = main.o skip_list.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run.exe: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean:
	$(RM) count *.o *~
