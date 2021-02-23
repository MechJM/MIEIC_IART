CC=g++
CFLAGS= -Wall -Wextra -Werror -pedantic -rdynamic
LFLAGS= -lfmt
BUCKET_OBJS=main.o State.o Node.o

default: bucket lesser_clean

bucket: $(BUCKET_OBJS)
	$(CC) $(CFLAGS) $(BUCKET_OBJS) $(LFLAGS) -o bucket 

State.o:

lesser_clean:
	rm -rf *.o

clean:
	rm -rf *.o bucket