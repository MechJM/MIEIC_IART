CC=g++
CFLAGS= -Wall -Wextra -Werror -pedantic -rdynamic
BUCKET_OBJS=main.o State.o Node.o Tree.o

default: bucket lesser_clean

bucket: $(BUCKET_OBJS)
	$(CC) $(CFLAGS) $(BUCKET_OBJS) -o bucket 

Tree.o: Tree.cpp Tree.h Node.h
	$(CC) $(CFLAGS) -c Tree.cpp

Node.o: Node.cpp Node.h State.h
	$(CC) $(CFLAGS) -c Node.cpp

State.o: State.cpp State.h
	$(CC) $(CFLAGS) -c State.cpp

main.o: main.cpp Tree.h
	$(CC) $(CFLAGS) -c main.cpp

lesser_clean:
	rm -rf *.o

clean:
	rm -rf *.o bucket