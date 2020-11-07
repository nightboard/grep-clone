.DEFAULT_GOAL := grep

grep: grep.cpp
	g++ grep.c -o grep
