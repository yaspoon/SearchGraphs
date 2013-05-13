OBJS=Edge.o Graph.o Vertex.o GreedySearch.o
CFLAGS=-g -I./include
LIBS=
EXE=greedy-search
EXEOUTPUT=..
OUTPUT=./obj
VPATH=src:include:obj
CC=g++

$(shell `mkdir ./bin ./obj`)

default: $(EXE)

$(EXE): $(OBJS) main.cpp
	$(CC) -o $(EXEOUTPUT)/greedy-search main.cpp $(OUTPUT)/*.o $(CFLAGS) $(LIBS)

Edge.o: Edge.cpp Edge.h Vertex.h
	$(CC) -c -o $(OUTPUT)/$@ $< $(CFLAGS) $(LIBS)

Graph.o: Graph.cpp Graph.h Vertex.h Set.h Edge.h
	$(CC) -c -o $(OUTPUT)/$@ $< $(CFLAGS) $(LIBS) 

Vertex.o: Vertex.cpp Vertex.h 
	$(CC) -c -o $(OUTPUT)/$@ $< $(CFLAGS) $(LIBS)

Set.o: Set.h LinkedList.h Pair.h
	$(CC) -c -o $(OUTPUT)/$@ $< $(CFLAGS) $(LIBS)

Pair.o: Pair.h
	$(CC) -c -o $(OUTPUT)/$@ $< $(CFLAGS) $(LIBS)

Iterator.o: Iterator.h LinkedList.h
	$(CC) -c -o $(OUTPUT)/$@ $< $(CFLAGS) $(LIBS)

LinkedList.o: LinkedList.h Iterator.h LinkedListNode.h
	$(CC) -c -o $(OUTPUT)/$@ $< $(CFLAGS) $(LIBS)

LinkedListNode.o: LinkedListNode.h
	$(CC) -c -o $(OUTPUT)/$@ $< $(CFLAGS) $(LIBS)

GreedySearch.o: GreedySearch.cpp GreedySearch.h Set.h Stack.h Common.h
	$(CC) -c -o $(OUTPUT)/$@ $< $(CFLAGS) $(LIBS)

clean:
	rm -rf $(OUTPUT)/*.o $(EXEOUTPUT)/$(EXE) ./bin ./obj


