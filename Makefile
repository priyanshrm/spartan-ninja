CC = clang
CFLAGS = -g
OBJFILES = test.o
TARGET = test

$(TARGET): $(OBJFILES)
	$(CC) $(OBJFILES) -o $(TARGET) $(CFLAGS)

main.o: main.c
	$(CC) -c $^ -o $@ $(CFLAGS)

queue.o: ./source_files/Queue.c
	$(CC) -c $^ -o $@ $(CFLAGS)

dll.o: ./source_files/DoublyLinkedList.c
	$(CC) -c $^ -o $@ $(CFLAGS)

stack.o: ./source_files/Stack.c
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	rm -f *.o $(TARGET)
