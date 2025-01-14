/************************************************************/
/* Author: Elliot Swan */
/* Creation Date: 10/12/2022 */
/* Due Date: 10/25/2022 */
/* Course: CSC237 */
/* Professor Name: Dr. Spiegel */
/* Assignment: #2 */
/* Filename: TermSTLObjList.h */
/* Purpose: This file contains class definitions for the
   TermSTLObjList class */
/*  */
/*  */
/************************************************************/


#ifndef TERMSTLLIST_H
#define TERMSTLLIST_H

#include "TermList.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Term.h"
using namespace std;

class TermSTLObjList : public TermList{
public:
  //constructor
  TermSTLObjList();

  void readIntoList(string filename);

  void printIteratively();

  void Process();
  virtual double operator()(double x) const;

  private:
  vector<Term> theTerms;



};

#endif
