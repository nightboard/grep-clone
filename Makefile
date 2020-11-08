.DEFAULT_GOAL := grep

grep: grep.o args.o matchAlgo.o
	g++ grep.o args.o matchAlgo.o -o grep

grep.o: grep.cpp
	g++ -c grep.cpp

args.o: src/args.cpp src/args.h
	g++ -c src/args.cpp

matchAlgo.o: src/matchAlgo.cpp src/matchAlgo.h
	g++ -c src/matchAlgo.cpp

clean:
	rm -f *.o grep
