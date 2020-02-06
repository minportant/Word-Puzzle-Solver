# Min Woo Kim

CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -O2
DEBUG=-Wall
OFILES=hashTable.o wordPuzzle.o timer.o
.SUFFIXES: .o .cpp

BinarySearchTree: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
	@echo "WORD PUZZLE IS READY TO GO!"
	
clean:
	-rm -f *.o *~ a.out
	
hashTable.o: hashTable.cpp hashTable.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
timer.o: timer.cpp timer.h
