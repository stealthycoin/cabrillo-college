DigitAnalyzer: linknode.h digitanalyzer.o main.o
	g++ -o p5 linknode.h digitanalyzer.o main.o
digitanalyzer.o: DigitAnalyzer.h DigitAnalyzer.cpp
	g++ -c DigitAnalyzer.cpp
main.o: main.cpp
	g++ -c main.cpp

clean:
	rm p5 *.o

run:
	./p5