# Word Puzzle Solver

The goal of this puzzle solver is to find words in the puzzle in any of the eight directions. This program will take one grid of letters text file and one dictionary of words. Any of the words in the dictionary that is found on the puzzle is outputted. This program uses hash function to add dictionary words into a hash table. The hash function is used again to find words from the word puzzle.

## Getting Started

To begin, just clone or download my repository. Unzip the file if necessary. Open terminal in the folder. Type 'make' to execute Makefile. When the solver is ready, you will be prompted with the message 'WORD PUZZLE IS READY TO GO!'

## Running the Program

To run this program, you will need to execute the a.out file in this format (./a.out <dictionary_file> <grid_file>) Using the given dictionary and puzzle text files for example,

```
./a.out dictionary.txt WordPuzzle.txt
```

### Example output

```
. 
.
.
E (299, 244):	fan
E (299, 247):	why
E (299, 250):	biz
NW(299, 255):	air
NW(299, 257):	sub
N (299, 259):	cot
E (299, 259):	cup
NW(299, 269):	set
N (299, 271):	rim
W (299, 273):	cork
. 
.
.
```

