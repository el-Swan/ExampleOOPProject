/************************************************************/
/* Author: Elliot Swan */
/* Creation Date: 10/16/2022 */
/* Due Date: 10/25/2022 */
/* Course: CSC237 */
/* Professor Name: Dr. Spiegel */
/* Assignment: #2 */
/* Filename: testLL.cpp */
/* Purpose: This program is a test driver for the 
   doubly linked list class. Can be run using a script
   or by user input 
/*  
/* 
/************************************************************/


#include "DbblLink.h"
#include <iostream>

using namespace std;
void printMenu();
int getInput();
int menu(DblLink<int>&);
void printBack(DblLink<int>);
void print(DblLink<int> toPrint);
void remove(DblLink<int>& theList);

int main(){
  DblLink<int> list1;
  int input = 0;
  
  while (input != 5)
  {
    printMenu();
    input = menu(list1);
    if (input == 5)
      break;
  }
  return 0;
}

/*************************************************************************/
/* */
/* Function name: void printMenu */
/* Description: outputs text to the screen to describe a menu */
/* Member Type: mutator */
/* Parameters: none */
/* Return Value: void - none*/
/* */
/*************************************************************************/
void printMenu()
{
  cout << "1: Insert" << endl;
  cout << "2: Remove" << endl;
  cout << "3: Print Forward" << endl;
  cout << "4: Print Backward" << endl;
  cout << "5: Exit" << endl;
}

/*************************************************************************/
/* */
/* Function name: int menu() */
/* Description: takes a user input and controls the program  */
/* Member Type: facilitator */
/* Parameters: DblLink<int>& theList - import export */
/* Return Value: int - the choice to decide to close the program */
/* */
/*************************************************************************/
int menu(DblLink<int>& theList)
{
  int input = getInput();
  switch(input){
  case 1:
    theList.orderedInsert(getInput());
    break;
  case 2:
    remove(theList);
    break;
  case 3:
    print(theList);
    break;
  case 4:
    printBack(theList);
  case 5:
    break;
  }
  return input;
}

/*************************************************************************/
/* */
/* Function name: remove */
/* Description: removes an element from the list */
/* Member Type: mutator */
/* Parameters: DblLink<int>& theList- import export */
/* Return Value: void - none */
/* */
/*************************************************************************/
void remove(DblLink<int>& theList)
{
  if (theList.empty())
	  {cout <<"The list is empty" << endl;
	    return;
	  }	
        int found = getInput();
        if(theList.find(found))   
        theList.remove(found);
    else
      cout << "Error not found" << endl;
}

/*************************************************************************/
/* */
/* Function name: int getInput */
/* Description: gets user input for various purposes */
/* Member Type:  facilitator*/
/* Parameters:  none*/
/* Return Value: int - the user choice*/
/* */
/*************************************************************************/
int getInput()
{
  cout << ">";
  int input = 0;
  
  cin >> input;
  cout << endl;
  return input;

}

/*************************************************************************/
/* */
/* Function name: void print() */
/* Description: outputs the list. Outputs an error if the list is empty */
/* Member Type: facilitator */
/* Parameters:  DblLink<int> toPrint -import - the list to be output*/
/* Return Value: none - void*/
/* */
/*************************************************************************/
void print(DblLink<int> toPrint)
{
  DblLinkItr<int> itr(toPrint);
  if (itr.isEmpty())
    {
      cout << "The List is empty" << endl;
      return;
    }
  else
    cout << toPrint << endl;
}

/*************************************************************************/
/* */
/* Function name: void printBack */
/* Description:  outputs the list backwards using an iterator*/
/* Member Type:  mutator*/
/* Parameters:  DblLink<int> toPrint - import - the list to print*/
/* Return Value: none - void*/
/* */
/*************************************************************************/

void printBack(DblLink<int> toPrint)
{
  
  DblLinkItr<int> itr(toPrint);
  if (itr.isEmpty())
  {
    cout << "The List is empty" << endl;
    return;
  }
  for (itr.start(); !itr.isLastNode(); itr++);
  for (;!itr.isFirstNode(); itr--)
    cout << *itr << " ";
  cout << *itr << endl;
}

