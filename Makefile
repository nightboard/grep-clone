.DEFAULT_GOAL := grep

grep: grep.cpp
	g++ grep.cpp -o grep
