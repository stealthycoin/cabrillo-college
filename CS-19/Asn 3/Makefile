program: main.o intset.o
	g++ -o IntSet main.o intset.o
main.o: main.cpp
	g++ -c main.cpp
intset.o: IntSet.h IntSet.cpp
	g++ -c IntSet.cpp

clean:
	rm IntSet *.o

run:
	./IntSet