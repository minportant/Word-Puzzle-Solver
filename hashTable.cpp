// Min Woo Kim

#include "hashTable.h"
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

hashTable::hashTable(int size){
  table_size = size;
  table.resize(table_size);
  /*for(int i = 0; i < table_size; i++){
    table[i] = "";
  }
  */
}

void hashTable::insertItem(const string& key){
  unsigned int index = hashFunction(key);
  table[index].push_back(key);
  /*while(table[index] != ""){
    index++;
  }
  table[index] = key;
  */
}

bool hashTable::contains(const string& word){
  const list<string> & theBucket = table[hashFunction(word)];
  return find(theBucket.begin(), theBucket.end(), word) != theBucket.end();
  /*unsigned int hash = hashFunction(word);
  if(table[hash] == ""){
    return false;
  }
  if(table[hash] == word){
    return true;
  }
  while(table[hash] != word){
    hash++;
    if(hash == (table_size - 1)){
      hash = 0;
    }
    if(table[hash] == word){
      return true;
    }
    if(table[hash] == ""){
      return false;
    }
  }
  
  return false;
  */
}
			   
unsigned int hashTable::hashFunction(const string& word){
  unsigned int result = 1;
  for(int i = 0; i < word.length(); i++){
    result += result*37 * word[i];
  }
 
  return result % table_size;
}
