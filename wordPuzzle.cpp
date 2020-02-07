// Min Woo Kim

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "hashTable.h"
#include "timer.h"
#include <queue>
#include <sstream>

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500

char grid[MAXROWS][MAXCOLS];

bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

bool readInGrid (string filename, int &rows, int &cols) {
    string line;
    ifstream file(filename.c_str());
    if ( !file.is_open() )
        return false;
    file >> rows;
    getline (file,line); 
    file >> cols;
    getline (file,line); 
    getline (file,line);
    file.close();
    int pos = 0; 
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
        }
    }
    return true;
}

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    static char output[256];
    if ( len >= 255 )
        len = 255;
    int pos = 0, r = startRow, c = startCol;
    for ( int i = 0; i < len; i++ ) {
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        output[pos++] = grid[r][c];
        switch (dir) { 
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    output[pos] = 0;
    return output;
}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

int main(int argc, char* argv[]){
  timer tick;
  int rows, cols;
  string word;
  int count = 0;
  int numWords = 0;
  queue<string> wordQueue;
  string line;
  
  ifstream file(argv[1]);
  while(getline(file,word)){
    numWords++;
  }
  file.close();
  
  int prime = getNextPrime(numWords);
  hashTable tbl(prime);
  
  ifstream file2(argv[1]);
  while(getline(file2,word)){
    tbl.insertItem(word);
  }
  file2.close();
  
  bool result = readInGrid(argv[2], rows, cols);
  if(!result){
    exit(1);
  }
  tick.start();
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      for(int k = 0; k < 8; k++){
	for(int l = 3; l < 23; l++){
	  if(tbl.contains(getWordInGrid(i,j,k,l,rows,cols)) && strlen(getWordInGrid(i,j,k,l,rows,cols)) == l){
	    if(k==0){
	      stringstream ss;
	      stringstream ss2;
	      ss << i;
	      ss2 << j;
	      line = "N (" + ss.str() + ", " + ss2.str() + "):\t" + getWordInGrid(i,j,k,l,rows,cols);
	      wordQueue.push(line);
	    }else
	    if(k==1){
	      stringstream ss;
	      stringstream ss2;
	      ss << i;
	      ss2 << j;
	      line = "NE(" + ss.str() + ", " + ss2.str() + "):\t" + getWordInGrid(i,j,k,l,rows,cols);
	      wordQueue.push(line);
	      //cout<<"NE("<< i <<", "<< j<<"):\t" << getWordInGrid(i,j,k,l,rows,cols) << endl;
	    }else
	    if(k==2){
	      stringstream ss;
	      stringstream ss2;
	      ss << i;
	      ss2 << j;
	      line = "E (" + ss.str() + ", " + ss2.str() + "):\t" + getWordInGrid(i,j,k,l,rows,cols);
	      wordQueue.push(line);
	    }else
	    if(k==3){
	      stringstream ss;
	      stringstream ss2;
	      ss << i;
	      ss2 << j;
	      line = "SE(" + ss.str() + ", " + ss2.str() + "):\t" + getWordInGrid(i,j,k,l,rows,cols);
	      wordQueue.push(line);
	    }else
	    if(k==4){
	      stringstream ss;
	      stringstream ss2;
	      ss << i;
	      ss2 << j;
	      line = "S (" + ss.str() + ", " + ss2.str() + "):\t" + getWordInGrid(i,j,k,l,rows,cols);
	      wordQueue.push(line);
	    }else
	    if(k==5){
	      stringstream ss;
	      stringstream ss2;
	      ss << i;
	      ss2 << j;
	      line = "SW(" + ss.str() + ", " + ss2.str() + "):\t" + getWordInGrid(i,j,k,l,rows,cols);
	      wordQueue.push(line);
	    }else
	    if(k==6){
	      stringstream ss;
	      stringstream ss2;
	      ss << i;
	      ss2 << j;
	      line = "W (" + ss.str() + ", " + ss2.str()+ "):\t" + getWordInGrid(i,j,k,l,rows,cols);
	      wordQueue.push(line);
	    }else
	    if(k==7){
	      stringstream ss;
	      stringstream ss2;
	      ss << i;
	      ss2 << j;
	      line = "NW(" + ss.str() + ", " + ss2.str() + "):\t" + getWordInGrid(i,j,k,l,rows,cols);
	      wordQueue.push(line);
	    }
	    count++;
	  }
	}
      }
    }
  }
  tick.stop();
  while(!wordQueue.empty()){
    cout<<wordQueue.front()<<endl;
    wordQueue.pop();
  }
  cout<<count<<" words found"<<endl;
  cout<<"Found all words in " << tick.getTime()<<" seconds" <<endl;
  int x = tick.getTime() * 1000;
  cout<<x;
  return 0;
}
