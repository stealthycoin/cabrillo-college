Main: main.o dictionary.o cinco.o
	g++ -o Cinco main.o dictionary.o cinco.o
dictionary.o: Dictionary.h Dictionary.cpp
	g++ -c Dictionary.cpp
cinco.o: Dictionary.o Cinco.h Cinco.cpp
	g++ -c Cinco.cpp
main.o: main.cpp
	g++ -c main.cpp

clean:
	rm Cinco *.o
run:
	./Cinco