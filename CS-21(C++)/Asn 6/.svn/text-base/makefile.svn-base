MazeGen: main.cpp Maze.o DisjointSet.o
	g++ -o MazeGen main.cpp Maze.o DisjointSet.o
Maze.o: DisjointSet.o Maze.h Maze.cpp
	g++ -c Maze.cpp
DisjointSet.o: DisjointSet.h DisjointSet.cpp
	g++ -c DisjointSet.cpp
run:
	./MazeGen
clean:
	rm *~ *.o
