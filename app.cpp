/************************************************************/
/* Author: Elliot Swan */
/* Creation Date: 10/12/22 */
/* Due Date: 10/25/22 */
/* Course: CSC237 */
/* Professor Name: Dr. Spiegel */
/* Assignment: #2 */
/* Filename: app.cpp */
/* Purpose: This program will use polymorphic binding  */
/* to fill a data structure of Terms, evaluate and output */
/* */
/************************************************************/

#include <iostream>
#include "DbblLink.h"
#include "Term.h"
#include "TermDblLinkList.h"
#include "TermList.h"
#include <fstream>
#include "TermArrayList.h"
#include "TermSTLObjList.h"
bool getFile(string& fileName);
void outerMenu();
int getInput();
void menuChoice(int& choice, string fileName);
void errorMessage();
void outerMenu();
void dblLinkMenu();
double getX();
void dblLinkChoice(TermList* theTerms, string filename);
void stlObjChoice(TermList* theTerms, string filename);
void stlObjMenu();
void objArrayChoice(TermList* theTerms, string filename);
void ObjArray();
void batch(string fileName, double x);
void batchArray(TermList* theTerms, string fileName, double x);
void batchSTL(TermList* theTerms, string fileName, double x);
void batchList(TermList* theTerms, string fileName, double x);

int main(int argc, char** argv)
{
  string fileName;
  ifstream file;
  bool fileOpened = false;
  if (argc == 3)
    {     
      fileName = argv[1];
      file.open(fileName.c_str());
      fileOpened = !file.fail();
      if (fileOpened == false)
	{
	  errorMessage();
	  return 1;
	}
      double x = stod(argv[2]);
      batch(fileName, x);
      return 0;
    }
  
  fileOpened = getFile(fileName);
  if (fileOpened == false)
  {
    errorMessage();
    return 1;     
  }  

  int choice = 0; 
  while (choice != 4)
  {
    outerMenu();
    choice = getInput();
    menuChoice(choice, fileName);
  }
  return 0;
  
}

/*************************************************************************/
/* */
/* Function name: errorMessage */
/* Description:  outputs an error message*/
/* Member Type:  mutator*/
/* Parameters:  none*/
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void errorMessage()
{
  cout << "ERROR" << endl;
}

/*************************************************************************/
/* */
/* Function name: menuChoice  */
/* Description: decides what data structure the user wants  */
/* Member Type: facilitator */
/* Parameters:  int& choice - the users choice
                string fileName - the name of the file*/
/* Return Value:  void*/
/* */
/*************************************************************************/

void menuChoice(int& choice, string fileName)
{
    
  TermList* theTerms;
  switch(choice){
  case 1:
    objArrayChoice(theTerms, fileName);
       break;
    case 2:
      stlObjChoice(theTerms, fileName);
      break;
  case 3:
      dblLinkChoice(theTerms, fileName);  
    break;
  case 4:
    break;
      }
}

/*************************************************************************/
/* */
/* Function name: getFile  */
/* Description:  determines if the file name is valid. gets the file name*/
/* Member Type:  facilitator*/
/* Parameters:  string&  fileName - import export - the file name*/
/* Return Value:  bool true if the file was opened false otherwise*/
/* */
/*************************************************************************/

bool getFile(string& fileName)
{
  cout << "Please enter a file name: ";
  cin >> fileName;
  cout << endl;
  ifstream file(fileName.c_str());

  if(file.fail())
    return false;
  return true;

}

/*************************************************************************/
/* */
/* Function name: outerMenu  */
/* Description: outputs an outer menu to decide the data structure */
/* Member Type:  mutator*/
/* Parameters:  none*/
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void outerMenu()
{
  cout << "Select a data structure: " << endl;
  cout << "1. Object Array" << endl;
  cout << "2. STL Object" << endl;
  cout << "3. Doubly Linked List" << endl;
  cout << "4. Exit" << endl;
}

/*************************************************************************/
/* */
/* Function name: getInput */
/* Description:  gets user input*/
/* Member Type:  facilitator*/
/* Parameters:  none*/
/* Return Value:  int choice - the users choice*/
/* */
/*************************************************************************/

int getInput()
{
  int choice = 0;
  cin >> choice;
  return choice;
}

/*************************************************************************/
/* */
/* Function name: stlObjChoice */
/* Description:  outputs the users choice in the STL object*/
/* Member Type:  facilitator*/
/* Parameters:  TermList* theTerms - import export - a pointer that will
                polymorphically run the functions
                string filename - import - the filename*/
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void stlObjChoice(TermList* theTerms, string filename)
{
  theTerms = new TermSTLObjList;
  theTerms -> readIntoList(filename);
  int choice = 0;
  while (choice != 4)
  {
    stlObjMenu();
    choice = getInput();
      switch(choice)
	{
	case 1:
	  theTerms -> printIteratively();
	break;
	case 2:
	break;
	case 3:
	{
	  double x =getX();
	  cout << "Evaluated for X: " << (*theTerms)(x) << endl;
	  break;
	}
	case 4:
	break;
	}
  }
  delete theTerms;
}

/*************************************************************************/
/* */
/* Function name: objArrayChoice */
/* Description:  decides how to interpret user input in object array*/
/* Member Type:  facilitator
/* Parameters:  TermList* theTerms - import export - a pointer that 
                polymorphically calls functions
                string filename - import - the filname*/
/* Return Value: none - void */
/* */
/*************************************************************************/

void objArrayChoice(TermList* theTerms, string filename)
{
  theTerms = new TermArrayList;
  theTerms -> readIntoList(filename);
  int choice = 0;
  while(choice != 4)
  {
    ObjArray();
    cin >> choice;
    switch(choice)
    {
    case 1:
      theTerms -> printIteratively();
      break;
    case 2:
      theTerms -> printPtr();
      break;
    case 3:
      {
	double x = getX();
	cout << "Evaluated for x: " << (*theTerms)(x);
	cout << endl;
      }
      break;
    case 4:
      break;
    }
  }
  delete theTerms;
}

/*************************************************************************/
/* */
/* Function name: dblLinkChoice  */
/* Description: decides what to do in the double link list
                based on user input. fills the linked list */
/* Member Type:  facilitator*/
/* Parameters:  TermList* theTerms - a pointer that will call 
                functions polymorphically - import export
                string filename - the name of the file*/
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void dblLinkChoice(TermList* theTerms, string filename)
{
  
  theTerms = new TermDblLinkList;
  theTerms -> readIntoList(filename);
  
  int choice = 0;
  while (choice != 4)
  {
    dblLinkMenu();
    cin >> choice;
    switch(choice)
      {
      case 1:
	theTerms -> printIteratively();
	break;
      case 2:
	break;
      case 3:
	{
	double x = getX();
	cout << "Evaluated for x: " << (*theTerms)(x);
	cout << endl;
	}
      case 4:
	break;	
      }
  }
  delete theTerms;
}

/*************************************************************************/
/* */
/* Function name: ObjArray */
/* Description:  outputs a menu for the object array*/
/* Member Type:  mutator*/
/* Parameters:  none*/
/* Return Value:  void none*/
/* */
/*************************************************************************/

void ObjArray()
{
  cout << "----------------------------" << endl;
  cout << "Object C++ Array" << endl;
  cout << "----------------------------" << endl;
  cout << "1: Object Array Iterative Print" << endl;
  cout << "2: Object Array Pointer Print" << endl;
  cout << "3: Evaluate the polynomial" << endl;
  cout << "4: Exit" << endl;
}

/*************************************************************************/
/* */
/* Function name: stlObjMenu  */
/* Description: outputs a menu for the STL object */
/* Member Type:  mutator*/
/* Parameters:  none*/
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void stlObjMenu()
{
  cout << "----------------------------" << endl;
  cout << "STL Object" << endl;
  cout << "----------------------------" << endl;
  cout << "1: STL Object Iterative Print" << endl;
  cout << "3: Evaluate the polynomial" << endl;
  cout << "4. Exit " << endl;
}

/*************************************************************************/
/* */
/* Function name: dblLinkMenu */
/* Description: outputs a menu for the linked list choice */
/* Member Type:  mutator*/
/* Parameters:  none*/
/* Return Value:  void - none*/
/* */
/*************************************************************************/

void dblLinkMenu()
{
  cout << "----------------------------" << endl;
  cout << "Doubly Linked List" << endl;
  cout << "----------------------------" << endl;
  cout << "1: Doubly Linked List Iterative Print" << endl;
  cout<< "3: Evaluate polynomial" << endl;
  cout << "4: Exit Doubly Linked List" << endl;
}

/*************************************************************************/
/* */
/* Function name: getX  */
/* Description: gets a value for x */
/* Member Type: facilitator */
/* Parameters: none */
/* Return Value: double x - the value that will eventually be evaluated */
/* */
/*************************************************************************/

double getX()
{
  double x = 0.0;
  cout << "Enter a value for X: ";
  cin >> x;
  cout << endl;
  return x;
}

/*************************************************************************/
/* */
/* Function name: batch  */
/* Description: runs command line inputs */
/* Member Type: facilitator */
/* Parameters:  string fileName - import - the name of the file
                double x - the value to be evaluated*/
/* Return Value: none - void */
/* */
/*************************************************************************/

void batch(string fileName, double x)
{
  TermList* theTerms;

  batchArray(theTerms, fileName, x);

  batchSTL(theTerms, fileName, x);

  batchList(theTerms, fileName, x);
}

void batchArray(TermList* theTerms, string fileName, double x)
{
  theTerms = new TermArrayList;
  theTerms -> readIntoList(fileName);
  theTerms -> printIteratively();
  theTerms -> printPtr();
  cout <<"Evaluated for X: " << (*theTerms)(x) << endl;
  delete theTerms;
}

void batchSTL(TermList* theTerms, string fileName, double x)
{
  theTerms = new TermSTLObjList;
  theTerms -> readIntoList(fileName);
  theTerms -> printIteratively();
  cout << "Evaluated for X: " << (*theTerms)(x) << endl;
  delete theTerms;
}

void batchList(TermList* theTerms, string fileName, double x)
{
  theTerms = new TermDblLinkList;
  theTerms -> readIntoList(fileName);
  theTerms -> printIteratively();
  cout << "Evaluated for X: " << (*theTerms)(x) << endl;
  delete theTerms;
}
