OBJS=SimmulatedAnnealing.o Point.o
CFLAGS=-g -I./include
LIBS=
EXE=simanneal-hill
EXEOUTPUT=..
OUTPUT=./obj
VPATH=src:include:obj
CC=g++

$(shell `mkdir ./bin ./obj`)

default: $(EXE)

$(EXE): $(OBJS) main.cpp
	$(CC) -o $(EXEOUTPUT)/$(EXE) main.cpp $(OUTPUT)/*.o $(CFLAGS) $(LIBS)

Point.o: Point.cpp Point.h
	$(CC) -c -o $(OUTPUT)/$@ $< $(CFLAGS) $(LIBS)

SimmulatedAnnealing.o: SimmulatedAnnealing.cpp SimmulatedAnnealing.h Point.h Iterator.h LinkedList.h
	$(CC) -c -o $(OUTPUT)/$@ $< $(CFLAGS) $(LIBS)

clean:
	rm -rf $(OUTPUT)/*.o $(EXEOUTPUT)/$(EXE) ./bin ./obj


