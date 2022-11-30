#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <bits/stdc++.h>

#include<stdio.h>
#include<math.h>
#include <iostream>
#include <unordered_map>
#include <map>
#include <sstream>
#include <fstream>
#include <string>

// #ifndef STD_HEADERS
// #include "std_headers.h"
// #endif

using namespace std;

// Can change this value for debugging
#define DICT_SIZE 512

typedef struct{
    int occurence;
    bool dest;
    bool src;
}varmap;

template <typename T> class Entry {
 public:
  string key;
  T value;

  Entry() {key = "";}
  Entry(T initValue) {key = ""; value = initValue;}
  ~Entry() {;}
};
  
template <typename T> class Fetcher {
 private:
  int N; // size of array A
  int numFilled; // number of used array elements
  Entry<T> *A; // Array of dictionary entries

 public:

  // Lookup table to store variable occurence along with instruction number, and its type (Destination | Source)
    //  opcode  var     var
  std::map <string, string, string> lookupU;

  //   opcode        insNo. src     dest
  std::map <string, tuple<int, string, string>> lookupIns;

  //   varName      insNo. dest?  src?
  std::map <string, tuple<int, bool, bool>> lookupVar;

  std::map <int, bool, bool> *ins1;
  
  //read the input code file
  void readFile(char fname[100]);

  // parse instruction
  void parseLine(string line, const char *delimiter);

  // check if operand is a constant
  bool checkIfNumber(string operand);

  // Default constructor
  Fetcher();

  // Default destructor
  ~Fetcher() {;}
  
  // Return the entry corresponding to given key, or NULL if the given key does not exist in the dictionary
  Entry<T> *get(string key);

  // Add the given entry in the appropriate location (using hashing) in the dictionary; return true if success, false if failure (array is full)
  bool put(Entry<T> entry);

  // Remove the given key; return true if success, false if failure (given key not present)
  bool remove(string key);

  string getKeyAtIndex(int index) { return A[index].key; } 
};

#endif