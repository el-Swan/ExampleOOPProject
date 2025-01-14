/************************************************************/
/* Author: Elliot Swan */
/* Creation Date: 10/12/2022 */
/* Due Date: 10/25/2022 */
/* Course: csc237 */
/* Professor Name: Dr. Spiegel */
/* Assignment: #2 */
/* Filename: TermSTLObjList.cpp */
/* Purpose: Function definitions for the TermSTLObjList class */
/*  */
/*  */
/************************************************************/


#include <fstream>
#include <iostream>
#include "TermList.h"
#include "TermSTLObjList.h"
#include <algorithm>
#include <vector>
using namespace std;

/*************************************************************************/
/* */
/* Function name: TermSTLObjList constructor  */
/* Description: constructs a TermSTLObjList that is empty */
/* Member Type:  constructor*/
/* Parameters:  none*/
/* Return Value:  none - void*/
/* */
/*************************************************************************/

TermSTLObjList::TermSTLObjList()
{}

/*************************************************************************/
/* */
/* Function name: readIntoList  */
/* Description: reads and processes into the data structure.
   combines duplicates and sorts. Reverses the order so they store correctly */
/* Member Type: mutator */
/* Parameters: string filename - the filename that will be use */
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void TermSTLObjList::readIntoList(string filename)
{
  ifstream file(filename.c_str());
  double coeff;
  int expn;
  while (file >> coeff >> expn)
  {
    Term placeholder(coeff, expn);
    theTerms.push_back(placeholder);    
  }
  Process();
  
  file.close();
  file.clear();
  file.seekg(0, file.beg);
}

/*************************************************************************/
/* */
/* Function name: printIteratively  */
/* Description: outputs the data structure using an iterator  */
/* Member Type:  mutator*/
/* Parameters:  none*/
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void TermSTLObjList::printIteratively()
{
  cout << "----------------------" << endl;
  cout << "STL Print Iterative" << endl;
  cout << "----------------------" << endl;
  vector<Term>::iterator it = theTerms.begin();
  for(; it != theTerms.end(); it++)
  {
    if(it != theTerms.begin())
    cout << " + ";  
    cout << *it;
  }
  cout << endl;
  
}

/*************************************************************************/
/* */
/* Function name: Process */
/* Description: Processes data in an STL container.
                Removes dupes and sorts */
/* Member Type: mutator */
/* Parameters: none */
/* Return Value: void - none */
/* */
/*************************************************************************/
void TermSTLObjList::Process()
{
  std::sort(theTerms.begin(), theTerms.end());
  int index = 0;
  int size = theTerms.size()-1;
  for(; index < size; index++)
  {    
    if (theTerms[index] == theTerms[index+1])
    {
      double toAdd =theTerms[index].getCoefficient() + theTerms[index+1].getCoefficient();
      Term placeholder(toAdd, theTerms[index].getExponent());
      theTerms[index] = placeholder;
      theTerms.erase((theTerms.begin()+index+1));
      theTerms.shrink_to_fit();
      index = index -1;
      size = size -1;
    }
  }
  std::sort(theTerms.begin(), theTerms.end());;
  reverse(theTerms.begin(), theTerms.end());

}
/*************************************************************************/
/*************************************************************************/
/* */
/* Function name:operator()  */
/* Description: evaluates the data structure given a double x */
/* Member Type: facilitator */
/* Parameters:  double x - import*/
/* Return Value:  result- the value of the polynomial*/
/* */

double TermSTLObjList::operator()(double x) const
{
  double result = 0.0;
  for (int idx = 0; idx < theTerms.size(); idx++)
    result += theTerms[idx](x);
  return (result);

}
