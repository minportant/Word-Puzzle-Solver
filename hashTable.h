// Min Woo Kim

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include <vector>
#include <string>

using namespace std;

class hashTable {
 private:
  int table_size;
  //vector< string > table;
  vector< list<string> > table;
 public:
  hashTable(int size);
  unsigned int hashFunction(const string& word);
  void insertItem(const string& key);
  bool contains(const string& word);
};

#endif
