hashtable: main.cpp hTable.o
	g++ -o hashtable main.cpp hTable.o
hTable.o: hTable.h hTable.cpp
	g++ -c hTable.cpp


run:
	./hashtable

clean:
	rm hashtable *.o
