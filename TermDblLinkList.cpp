/************************************************************/
/* Author: Elliot Swan */
/* Creation Date: 10/12/2022 */
/* Due Date: 10/25/2022 */
/* Course: CSC237 */
/* Professor Name: Dr. Spiegel*/
/* Assignment: #2 */
/* Filename: TermDblLinkList.cpp */
/* Purpose: This file contains class definitions for the 
   TermDblLinkList class */
/* */
/* */
/************************************************************/


#include "TermDblLinkList.h"
#include <fstream>

using namespace std;

/*************************************************************************/
/* */
/* Function name: TermDblLinkList  */
/* Description:  constructs an empty data structure*/
/* Member Type:  constructor*/
/* Parameters:  none*/
/* Return Value:  none*/
/* */
/*************************************************************************/

TermDblLinkList::TermDblLinkList()
{}

/*************************************************************************/
/* */
/* Function name: readIntoList  */
/* Description: given a filename, reads into a linked list inserting in order
   removes duplicates */
/* Member Type: mutator */
/* Parameters:  string filename - the file to be opened - import*/
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void TermDblLinkList::readIntoList(string filename)
{
  ifstream theFile(filename.c_str());
  double coeff;
  int expn;
  while (theFile >> coeff >> expn)
    {
      Term placeholder(coeff, expn);
      theList.orderedInsert(placeholder);
    }
  Process();
  
}

/*************************************************************************/
/* */
/* Function name: printIteratively  */
/* Description:  prints the data structure iteraively using an iterator*/
/* Member Type:  mutator*/
/* Parameters:  none*/
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void TermDblLinkList::printIteratively()
{
  cout << "----------------------------" << endl;
  cout << "Double Linked List Iterative" << endl;
  cout << "----------------------------" << endl;
  DblLinkItr<Term> itr(theList);
  if(itr.isEmpty())
    {
      cout << "The List is empty" << endl;
      return;
    }
  for (itr.start(); !itr.isLastNode(); itr++);
  for(; !itr.isFirstNode(); itr--)
    {
      cout << *itr << " + ";
    }
  cout << *itr << " ";
  cout << endl;
}

/*************************************************************************/
/* */
/* Function name: operator() */
/* Description:  evaluates a polynomial given the double x*/
/* Member Type:  facilitator*/
/* Parameters:  double x - the value to be evaluated*/
/* Return Value: double result - the evaluated polynomial  */
/* */
/*************************************************************************/

double TermDblLinkList::operator()(double x) const
{
  double result = 0.0;
  DblLinkItr<Term> itr(theList);
  for (itr.start(); itr.more(); itr++)
    {
      result += (*itr)(x);
    }
  return (result);  
}

/*************************************************************************/
/* */
/* Function name: Process */
/* Description: sorts and removes dupes from a linked list */
/* Member Type: mutator */
/* Parameters: none */
/* Return Value: none - void */
/* */
/*************************************************************************/
void TermDblLinkList::Process()
{
DblLinkItr<Term> itr(theList);
  DblLinkItr<Term> secondItr(theList);
  secondItr.start();
  for (itr.start(); itr.more(); itr++)
    {
      if(itr.isLastNode())
	{
	  return;
	}
      
      if (!itr.isFirstNode())
	{
	  secondItr = itr;
	  secondItr--;
	  if (*itr == *secondItr)
	    {
	      Term Dummy = *itr;
	      Term Dummy2 = *secondItr;
	      double coeff = Dummy.getCoefficient() + Dummy2.getCoefficient();
	      Term placeholder(coeff, Dummy.getExponent());
	      theList.remove(Dummy2);
	      theList.remove(Dummy);
	      theList.orderedInsert(placeholder);
	      itr.start();
	    }
	}
      secondItr = itr;
      secondItr++;
      if((*itr) == (*secondItr))
	{
	  Term Dummy = *itr;
	  Term Dummy2 = *secondItr;
	  double coeff = Dummy.getCoefficient() + Dummy2.getCoefficient();
	  Term placeholder(coeff, Dummy.getExponent());
	  theList.remove(Dummy);
	  theList.remove(Dummy2);
	  theList.orderedInsert(placeholder);
	  itr.start();
	}
    }
}
