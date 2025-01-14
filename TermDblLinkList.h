/************************************************************/
/* Author: Elliot Swan  */
/* Creation Date: 10/12/2022 */
/* Due Date: 10/25/2022 */
/* Course: CSC237 */
/* Professor Name: Dr. Spiegel */
/* Assignment: #2 */
/* Filename: TermDblLinkList.h */
/* Purpose: This file contains class definitions
   for the TermDblLinkList class */
/*  */
/*  */
/************************************************************/

#ifndef TermDblLinkList_H
#define TermDblLinkList_H

#include "TermList.h"
#include "DbblLink.h"
#include "Term.h"
#include <iostream>
#include <fstream>

using namespace std;

class TermDblLinkList : public TermList{
 public:
  //constructor
  TermDblLinkList();

  void readIntoList(string filename);

  void printIteratively();

  virtual double operator()(double x) const;

  void combineDupes();

  void Process();
private:
  DblLink<Term> theList;




};

#endif
