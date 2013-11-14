p5: SchmooList.o Schmoo.o main.cpp
	g++ -o p5 Schmoo.o SchmooList.o main.cpp 
Schmoo.o: Schmoo.h Schmoo.cpp
	g++ -c Schmoo.cpp
SchmooList.o: SchmooList.h SchmooList.cpp Schmoo.o LinkNode.h
	g++ -c SchmooList.cpp

run:
	./p5
clean:
	rm *.o *~
