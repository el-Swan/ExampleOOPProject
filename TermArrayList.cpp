// Author: Dr. Spiegel
//alterations made by Elliot Swan
//due 20/25/2022
// File: TermArrayList.cpp
// Container of Term objects 
// Implementations of member functions including inherited pure virtual fns.

#include <fstream>
#include <iostream>
#include <iomanip>
#include "TermArrayList.h"
#include <algorithm>

using namespace std;

/*************************************************************************/
/* */
/* Function name: TermArrayList constructor  */
/* Description:  constructs an empty TermArrayList*/
/* Member Type: constructor */
/* Parameters:  none*/
/* Return Value:  none*/
/* */
/*************************************************************************/
  TermArrayList::TermArrayList()
  { numTerms=0; }

/*************************************************************************/
/* */
/* Function name: readIntoList  */
/* Description: fills the respective data structure */
/* Member Type: mutator */
/* Parameters: string filename - import - the filename  */
/* Return Value:  void - none*/
/* */
/*************************************************************************/

  void TermArrayList::readIntoList(string filename)
  {
    ifstream source(filename.c_str());
    double coeff;
    int expn;
    fillList(source);
    Process(source);

    source.seekg(source.beg);
    source.close();
    source.clear();
  }

/*************************************************************************/
/* */
/* Function name: printIteratively */
/* Description:  prints the data structure using an iterative form*/
/* Member Type:  mutator*/
/* Parameters:  none*/
/* Return Value:  none - void*/
/* */
/*************************************************************************/
  // Print the data iteratively
  void TermArrayList::printIteratively()
//  void printObjectArrayIterator(TermArray ThePoly[], int numTerms)
  { cout<<"---------------------------------"<<endl;
    cout<<"|Object  Array  Iterative       |"<<endl;
    cout<<"---------------------------------"<<endl;
    for(int i=0; i<numTerms; i++) {
//      cout<<" "<<ThePoly[i]<< "    " << ThePoly[i].getArea() << 
//	    		"    " << ThePoly[i].getPerimeter() << endl;
      cout <<  ThePoly[i] << (i < numTerms-1?" + ":"");
    }
    cout << endl << endl;
}


/*************************************************************************/
/* */
/* Function name: printPtr */
/* Description:  outputs the data structure using the array pointer method*/
/* Member Type:  mutator*/
/* Parameters: none */
/* Return Value:  void - none*/
/* */
/*************************************************************************/
  // Print the data with a pointer
  void TermArrayList::printPtr()
  //void printObjectArrayPointerRecursive(TermArray* ThePoly, int numTerms)
  { cout<<"---------------------------------"<<endl;
    cout<<"|Object  Array  Pointer         |"<<endl;
    cout<<"---------------------------------"<<endl;
    Term *now=ThePoly;
    for(int i=0; i<numTerms; i++)
      cout << " " << *(now++)  << (i < numTerms-1?" +":"");
    cout << endl << endl;
  }

/*************************************************************************/
/* */
/* Function name: operator()  */
/* Description: evaluates the data structure for the given value x */
/* Member Type:  facilitator*/
/* Parameters:  double x - the value passed in to be evaluated - import*/
/* Return Value:  double - the evaluated polynomial*/
/* */
/*************************************************************************/

  // Evaluate the Polynomial
  double TermArrayList::operator()(double x) const
  { double result=0.0;
    for (int idx=0;idx<numTerms;idx++)
      result+=ThePoly[idx](x);
    return(result);
  }

/*************************************************************************/
/* */
/* Function name: fillList  */
/* Description:  fills the list and deals with duplicates*/
/* Member Type: mutator */
/* Parameters: ifstream& source - import export -the file stream */
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void TermArrayList::fillList(ifstream& source)
{
  double coeff = 0.0;
  int expn = 0;
  while (numTerms < MAXTERMS && source >> coeff >> expn)
    {
      Term dummy(coeff,expn);
      ThePoly[numTerms] = dummy;
      numTerms++;
      
      if (numTerms == MAXTERMS)
      {
	sort(ThePoly, ThePoly + numTerms);
	for(int index = 0; index < numTerms-1; index++)
	{
	  if (ThePoly[index] == ThePoly[index+1])
	  {
	    double toAdd = ThePoly[index].getCoefficient()
	      + ThePoly[index+1].getCoefficient();
            Term placeholder(toAdd, ThePoly[index].getExponent());
	    ThePoly[index] = placeholder;
	    
	    for (int idx = (index+1); idx < (numTerms-(index)); idx++)
	    {
	      ThePoly[idx] = ThePoly[idx+1];
	    }
	    numTerms--;
	    index--;
	  }	  
	}
      }
    }
}

/*************************************************************************/
/* */
/* Function name: Proccess  */
/* Description: continues to deal with duplicates after filling the array
                reverses it */
/* Member Type:  mutator*/
/* Parameters:  ifstream& source - the file stream - import export*/
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void TermArrayList::Process(ifstream& source)
{
  double coeff = 0.0;
  int expn = 0;
  while (source >> coeff >> expn)
    {
    if(numTerms == MAXTERMS)
      {
	sort(ThePoly, ThePoly + numTerms);
	Term placeholder(coeff, expn);
        for (int index = 0; index < numTerms; index++)
	{
	  if (ThePoly[index] == placeholder)
	  {
	    double toAdd = ThePoly[index].getCoefficient()
	      + placeholder.getCoefficient();
            Term placeholder2(toAdd, ThePoly[index].getExponent());
            ThePoly[index] = placeholder2;
	  }
	}
      }
    }    
      sort(ThePoly, ThePoly + numTerms);
      for(int index = 0; index < numTerms-1; index++)
	{
	  if (ThePoly[index] == ThePoly[index+1])
	  {
	    double toAdd = ThePoly[index].getCoefficient()
	      + ThePoly[index+1].getCoefficient();
            Term placeholder(toAdd, ThePoly[index].getExponent());
            ThePoly[index] = placeholder;
 
	    for (int idx = index+1; idx < (numTerms-index+1); idx++)
	    {
	      ThePoly[idx] = ThePoly[idx+1];
	    }
	    numTerms--;
	    index--;
	  }
	}
      reverse(ThePoly, ThePoly+numTerms);
}
