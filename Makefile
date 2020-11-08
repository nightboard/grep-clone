.DEFAULT_GOAL := grep

grep: grep.o args.o
	g++ grep.o args.o -o grep

grep.o: grep.cpp
	g++ -c grep.cpp

args.o: src/args.cpp src/args.h
	g++ -c src/args.cpp

clean:
	rm -f *.o grep
