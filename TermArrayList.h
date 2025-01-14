// Author: Dr. Spiegel alterations by Elliot Swan
// created 10/12/22
// due 10/25/2022
// File: TermArrayList.h
// Container of TermArray objects. 

#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <fstream>
#include <string>
#include "TermList.h"
#include "Term.h"

using namespace std;

const int MAXTERMS=10;

class TermArrayList : public TermList {
public:

  TermArrayList();

  // Put a string of strings into the list object
  //void readIntoList(ifstream &source);
  void readIntoList(string filename);

  // Print the data iteratively
  void printIteratively();
  
  // Print the data with a pointer
  void printPtr();

  // Evaluate the Polynomial
  virtual double operator()(double x) const;

  void fillList(ifstream&);
  void Process(ifstream&);
private:
  Term ThePoly[10];
  int numTerms;
  
  
};
  
#endif
