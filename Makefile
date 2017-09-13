
lib:
	gcc -c heap.c
	ar rcs libheap.a *.o
clean:
	rm -f *.o

