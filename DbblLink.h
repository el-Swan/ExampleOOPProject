/************************************************************/
/* Author: Elliot Swan - based off of Linked list by Dr. Spiegel
   Node class written by Dr. Spiegel */
/* Creation Date: 10/22/2022*/
/* Due Date: 10/25/2022 */
/* Course: CSC237 */
/* Professor Name: Dr. Spiegel */
/* Assignment: #2 */
/* Filename: DbblLink.h */
/* Purpose: Defines the double linked list class */
/*  defines a double linked list iterator as an interface*/
/*  */
/************************************************************/

#ifndef DBL_LINK_H
#define DBL_LINK_H

#include "TermList.h"
#include <iostream>
using namespace std;

template <class eltType> class DblLinkItr; 
template <class eltType> class DblLink;

template <class eltType> class Node
{       private:
                Node(eltType info, Node *pLink = 0, Node *rLink=0)
                                   : data(info), prev(pLink), next(rLink) {};
                eltType data;
                Node*   prev;
                Node*   next;
        friend class DblLink<eltType>;
        friend class DblLinkItr<eltType>;
};


template <class eltType> class DblLink 
{
public:
  //constructor
  DblLink();
  //construct a copy
  DblLink(DblLink&);
  //destructor
  ~DblLink();
  //Assignment operator
  DblLink<eltType> operator =(const DblLink<eltType>& toCopy);
  
  //checks to see if empty  
  bool empty();

  void destroy(Node<eltType> *);

  bool find(eltType);

  void orderedInsert(eltType);

  void remove(eltType);

  Node<eltType>* copy(Node<eltType> *); 

  private:
  Node<eltType>* head;

  friend class DblLinkItr<eltType>;
    
};


template <typename eltType>
  ostream& operator<<(ostream &output, const DblLink<eltType> &list); 

//DblLinkItr prototype
template <class eltType> class DblLinkItr
{
public:
  DblLinkItr(const DblLink<eltType> &list);

  DblLinkItr<eltType> operator =(const DblLinkItr<eltType>& toCopy); 

  void start();

  bool more();

  void next();

  eltType &value();

  bool isEmpty();

  bool isFirstNode();

  bool isLastNode();

  Node<eltType>* ptr();

  void operator--(int);

  void operator++(int);

  eltType operator*();

private:
  const DblLink<eltType> &ListRef;
  Node<eltType> *current;
};

/*************************************************************************/
/* */
/* Function name: DblLink constructor   */
/* Description: constructs an empty linked list*/
/* Member Type: constructor*/
/* Parameters: none*/
/* Return Value: void
/* */
/*************************************************************************/

template <typename eltType> DblLink<eltType>::DblLink() : head(NULL)
{}

/*************************************************************************/
/* */
/* Function name: copy constructor   */
/* Description: makes a replica of a list*/
/* Member Type: mutator*/
/* Parameters: DblLink& toCopy - import - the list to copy*/
/* Return Value: none - void
/* */
/*************************************************************************/

template <typename eltType> DblLink<eltType>::DblLink(DblLink& toCopy)
{
  head = copy(toCopy.head);
}

/*************************************************************************/
/* */
/* Function name: operator=  */
/* Description: assignment operator for linked list*/
/* Member Type: mutator*/
/* Parameters: const DblLink<eltType>& toCopy -import - the list to copy*/
/* Return Value: DblLink<eltType> - the copied list
/* */
/*************************************************************************/

template <typename eltType> DblLink<eltType >DblLink<eltType>::operator =(const DblLink<eltType>& toCopy)
{
  if (this != &toCopy)
    {
      destroy(head);
      head = copy(toCopy.head);
    }
  return *this;
}

/*************************************************************************/
/* */
/* Function name: ~DblLink  */
/* Description: destructor for the DblLink class*/
/* Member Type: mutator*/
/* Parameters: none*/
/* Return Value: void - none
/* */
/*************************************************************************/

template <typename eltType> DblLink<eltType>::~DblLink()
{
 destroy(head);
}

/*************************************************************************/
/* */
/* Function name: empty   */
/* Description: returns false if the list is empty*/
/* Member Type: facilitator*/
/* Parameters: none */
/* Return Value: none - void
/* */
/*************************************************************************/

template <typename eltType> bool DblLink<eltType>::empty()
{
  return (head == NULL);
}

/*************************************************************************/
/* */
/* Function name: find  */
/* Description: searches the list for data. if not found returns false*/
/* Member Type: facilitator*/
/* Parameters: toFind - import*/
/* Return Value: bool - true if the data is found false otherwise
/* */
/*************************************************************************/

template <typename eltType> bool DblLink<eltType>::find(eltType toFind)
{
  Node<eltType>* search = head;
  while (search != NULL && search -> data != toFind)
    search = search -> next;
  return (search != NULL && search -> data == toFind);

}

/*************************************************************************/
/* */
/* Function name: orderedInsert   */
/* Description: inserts to the list in an ordered fashion*/
/* Member Type: mutator*/
/* Parameters: eltType insert - import - the data to be inserted */
/* Return Value: none - void
/* */
/*************************************************************************/

template <typename eltType> void DblLink<eltType>::orderedInsert(eltType insert)
{
  if (empty())
    head = new Node<eltType>(insert, NULL, head);
  else if (!empty() && insert < head->data)
  {
    Node<eltType>* placeholder = head;
    head = new Node<eltType>(insert, NULL, head);
    placeholder -> prev = head;
  }
  else
  {
    Node<eltType>* p = head -> next;
    Node<eltType>* trailp = head;
    while (p != NULL && insert > p->data)
    {
      trailp = p;
      p = p -> next;
    }
    if (p != NULL)
    {
      Node<eltType>* placeholder = p;
      trailp -> next = new Node<eltType>(insert, trailp, trailp -> next);
      p -> prev = trailp -> next;
    }
    else
      trailp -> next = new Node<eltType>(insert, trailp, trailp -> next);
  }
}

/*************************************************************************/
/* */
/* Function name: copy  */
/* Description: copies a linked list. For assignment operator*/
/* Member Type: mutator*/
/* Parameters: Node<eltType>* listPtr - import/
/* Return Value: Node<eltType>* a pointer to the coiped list
/* */
/*************************************************************************/

template <typename eltType> Node<eltType>* DblLink<eltType>::copy(Node<eltType>* listPtr)
{
  if (listPtr != NULL)
  {
    Node<eltType>* first = NULL;
    Node<eltType>* last = NULL;
    first = last = new Node<eltType>(listPtr -> data, NULL, NULL);
    for (Node<eltType>* source = listPtr -> next; source != NULL; source = source -> next, last = last -> next)
      {
	last -> next = new Node<eltType>(source -> data, source -> prev, NULL);
      }
    return (first);
  }
  return NULL;
}

/*************************************************************************/
/* */
/* Function name: remove */
/* Description: Removes the first node with matching data from the list*/
/* Member Type: mutator*/
/* Parameters: eltType toRemove - import - the data to be removed*/
/* Return Value: none - void
/* */
/*************************************************************************/

template <typename eltType> void DblLink<eltType>::remove(eltType toRemove)
{
  Node<eltType>* p = head;
  Node<eltType>* trailp = NULL;

  while (p != NULL && p -> data != toRemove)
  {
    trailp = p;
    p = p->next;
  }
  if (p == head && p -> next == NULL)
  {
    head = NULL;
  }
  //remove from the front of the list
  else if (p == head)
  {
    head = head -> next;
    head -> prev = NULL;
  }
  //remove from the back of the list
  else if (p -> next == NULL)
  {
    p -> prev -> next = NULL;
  }
  //remove from middle of the list
  else if (p != head && p -> next != NULL)
  {
    p -> prev -> next = p -> next;
    p -> next -> prev = p -> prev;
  } 
  delete p;
}

/*************************************************************************/
/* */
/* Function name: DblLink destroy   */
/* Description: destroys a linked list given a pointer to its head*/
/* Member Type: mutator*/
/* Parameters: Node<eltType>* toDestroy - import - the first node of the list/
/* Return Value: none - void
/* */
/*************************************************************************/

template <typename eltType> void DblLink<eltType>::destroy(Node<eltType>* toDestroy)
{
  while (toDestroy != NULL)
    {
      Node<eltType> *doomed = toDestroy;
      toDestroy = toDestroy -> next;
      delete doomed;
    }
}

/*************************************************************************/
/* */
/* Function name: ostream& operator<<  */
/* Description: outputs the list using an iterator */
/* Member Type: mutator*/
/* Parameters: ostream& output - the file stream - import export
               const DblLink<eltType> &list - the list to be output - import*/
/* Return Value: ostream& output - the output stream to enable cascading
/* */
/*************************************************************************/

template <typename eltType>
ostream& operator<<(ostream &output, const DblLink<eltType> &list)
{
  DblLinkItr<eltType> itr(list);
  for (itr.start(); itr.more(); itr.next())
    output << itr.value() << " ";
  return output;
}

//DblLinkItr implementations

/*************************************************************************/
/* */
/* Function name: DblLinkItr operator=  */
/* Description: sets an iterator to equal another */
/* Member Type: mutator*/
/* Parameters: DblLinkItr<eltType>& toCopy - the iterator 
   that will be copied - import*/
/* Return Value: DblLinkItr<eltType> - the copied iterator
/* */
/*************************************************************************/

template <typename eltType> DblLinkItr<eltType>
DblLinkItr<eltType>::operator =(const DblLinkItr<eltType>& toCopy)
{
  current = toCopy.current;
  return *this;
}

/*************************************************************************/
/* */
/* Function name: DblLinkItr constructor  */
/* Description: constructs an iterator for a doubly linked list */
/* Member Type: constructor*/
/* Parameters: &list the list that will be operated on. - import/export */
/* Return Value: none - constructor 
/* */
/*************************************************************************/

template <typename eltType>
  DblLinkItr<eltType>::DblLinkItr(const DblLink<eltType> &list)
    : ListRef(list), current(NULL)
{}

/*************************************************************************/
/* */
/* Function name: start()  */
/* Description: moves the iterator to point at the first element of the list */
/* Member Type: mutator*/
/* Parameters:  none*/
/* Return Value: none
/* */
/*************************************************************************/

template <typename eltType> void DblLinkItr<eltType>::start()
{
  current = ListRef.head;
}

/*************************************************************************/
/* */
/* Function name: more  */
/* Description: determines if there is more data to be iterated through
   the list */
/* Member Type: facilitator */
/* Parameters: none */
/* Return Value: none - void
/* */
/*************************************************************************/

template <typename eltType> bool DblLinkItr<eltType>::more()
{
  return (current != NULL);
}

/*************************************************************************/
/* */
/* Function name: next */
/* Description: moves the iterator to the next element in the list */
/* Member Type: mutator*/
/* Parameters: none */
/* Return Value: void - none
/* */
/*************************************************************************/

template <typename eltType> void DblLinkItr<eltType>::next()
{
  current = current -> next;
}

/*************************************************************************/
/* */
/* Function name: value  */
/* Description: gets a value the iterator is pointed at  */
/* Member Type: inspector*/
/* Parameters:  none*/
/* Return Value: eltType- the datatype contained in the list
/* */
/*************************************************************************/

template <typename eltType> eltType &DblLinkItr<eltType>::value()
{
  return current -> data;
}

/*************************************************************************/
/* */
/* Function name: isEmpty  */
/* Description: determines if the list is empty */
/* Member Type: facilitator*/
/* Parameters:  none*/
/* Return Value: bool - true if the list is empty
/* */
/*************************************************************************/

template <typename eltType> bool DblLinkItr<eltType>::isEmpty()
{
  return (ListRef.head == NULL);
}

/*************************************************************************/
/* */
/* Function name: isFirstNode */
/* Description:  Determines if the iterator is pointing at the first node
                 in the list*/
/* Member Type: facilitator*/
/* Parameters:  none*/
/* Return Value: bool - true if pointing at the first node of the list
/* */
/*************************************************************************/

template <typename eltType> bool DblLinkItr<eltType>::isFirstNode()
{
  return (current -> prev == NULL);
}

/*************************************************************************/
/* */
/* Function name: isLastNode  */
/* Description: determines if the pointer is pointed at the first node 
                of the list */
/* Member Type: facilitator*/
/* Parameters:  none*/
/* Return Value: bool - true if pointing at the last node of the list false
   otherwise
/* */
/*************************************************************************/

template <typename eltType> bool DblLinkItr<eltType>::isLastNode()
{
  return (current -> next == NULL); 
}

/*************************************************************************/
/* */
/* Function name: operator--(int)  */
/* Description: moves the iterator to the previous node in the list */
/* Member Type: mutator*/
/* Parameters:  none*/
/* Return Value: none- void
/* */
/*************************************************************************/

template <typename eltType> void DblLinkItr<eltType>::operator--(int)
{
  current = (current -> prev);
}

/*************************************************************************/
/* */
/* Function name: operator++(int)  */
/* Description: moves the iterator to the next node in the list */
/* Member Type: mutator*/
/* Parameters:  none*/
/* Return Value: void - none
/* */
/*************************************************************************/

template <typename eltType> void DblLinkItr<eltType>::operator++(int)
{
  current = current -> next;
}

/*************************************************************************/
/* */
/* Function name: operator* */
/* Description:  gets the data held in the list at a pointed node*/
/* Member Type: inspector */
/* Parameters:  none*/
/* Return Value: eltType - the data type held in the list
/* */
/*************************************************************************/

template <typename eltType> eltType DblLinkItr<eltType>::operator*()
{
  return (current -> data);
}

#endif
