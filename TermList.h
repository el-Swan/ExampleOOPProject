/************************************************************/
/* Author: Elliot Swan */
/* Creation Date: 10/20/2022 */
/* Due Date: 10/25/2022 */
/* Course: CSC237 */
/* Professor Name: Dr. Spiegel */
/* Assignment: #2 */
/* Filename: TermList.h */
/* Purpose: This file declares a parent class TermList */
/* sets up polymorphic functions */
/*  */
/************************************************************/


// File: TermList.h
// Abstract base class for containers of Terms
// Known subclasses:
//      TermArray
// Coming soon: ParallelArrayTermList, TermVectorList, ...

#ifndef TERMLIST_H
#define TERMLIST_H

#include <fstream>
#include <string>

using namespace std;

class TermList {
public:

  /*************************************************************************/
/* */
/* Function name: readIntoList */
/* Description: Processes a list in all child classes*/
/* Member Type: mutator*/
/* Parameters:  string filename - the file name- import*/
/* Return Value: void - none */
/* */
/*************************************************************************/
  // Place the line of text into the data structure
  virtual void readIntoList(string filename)=0;

  /*************************************************************************/
/* */
/* Function name: void printIteratively*/
/* Description: prints a TermList child class iteratively*/
/* Member Type: mutator- outputs file stream */
/* Parameters:  none */
/* Return Value: void - none*/
/* */
/*************************************************************************/
  //
  // Print the data iteratively
  virtual void printIteratively()=0;
  /*************************************************************************/
/* */
/* Function name: void printPtr() */
/* Description: prints a TermList array using pointer math*/
/* Member Type: mutator- outputs to the file stream */
/* Parameters:  none*/
/* Return Value: void - none*/
/* */
/*************************************************************************/

  // Print the data Iteratively with a pointer
  virtual void printPtr() {}   // not pure virtual; why?

    /*************************************************************************/
/* */
/* Function name: double operator()() */
/* Description: evaluates a child class's polynomial value*/
/* Member Type: facilitator */
/* Parameters:  double x - input*/
/* Return Value: double - the value of the evaluated polynomial*/
/* */
/*************************************************************************/

  // Evaluate the Polynomial
  virtual double operator()(double x) const=0;
    
};
  
#endif
