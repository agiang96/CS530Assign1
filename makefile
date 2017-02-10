#Members: Alexander Giang, Shawn Chua
#Class Users: cssc0885, cssc0894
#Class Information: CS530, Spring 2017
#Assignment #1, HexDump
#Filename: makefile

CC=g++

all: xsd 

xsd: xsd.o
	g++ bin.o hex.o xsd.o -o xsd

xsd.o: xsd.cpp
	$(CC) -c xsd.cpp

bin.o: bin.cpp
	$(CC) -c bin.cpp

hex.o: hex.cpp
	$(CC) -c hex.cpp

clean:
	rm -rf *.o core xsd
