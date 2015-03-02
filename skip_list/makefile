CC=gcc
CFLAGS= -g -Wall -Wextra
DEPS = skip_list.h
OBJ = main.o skip_list.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run.out: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean:
	$(RM) count *.o *~
