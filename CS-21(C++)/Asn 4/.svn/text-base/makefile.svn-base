program: radixbucketsort.cpp spandexarray.o
	g++ -o p4 radixbucketsort.cpp spandexarray.o
spandexarray.o: SpandexArray.h SpandexArray.cpp
	g++ -c SpandexArray.cpp

run:
	time ./p4 < 1Mrand > output

clean:
	rm p4
