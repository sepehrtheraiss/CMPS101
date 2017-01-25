// ---------------------------------------------------------------
// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa2
// 1/27/17
// List.h
// ----------------------------------------------------------------

//-----------------------------------------------------------------------------
// List.h
// Header file for List ADT
//-----------------------------------------------------------------------------

#ifndef _LIST_H_INCLUDE_
#define _LIST_H_INCLUDE_


// Exported type --------------------------------------------------------------
typedef struct ListObj* List;

// Constructors-Destructors ---------------------------------------------------

// newList()
// Returns reference to new empty List object. 
List newList(void);

// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.
void freeList(List* pL);

// Access functions -----------------------------------------------------------

// length()
// pre:none
// Returns the length of L.
int length(List L);

//index()
// pre:none
// If cursor is defined, returns the index of the cursor element,
// otherwise returns -1.
int index(List L);

// front()
// Pre: length()>0
// Returns front element.
int front(List L);

// back()
// Pre: length()>0
// Returns back element. 
int back();

// get()
// Pre: length()>0, index()>=0
// Returns cursor element.
int get();

// equals()
// pre:none
// Returns true if this List and L are the same integer
// sequence. The cursor is ignored in both lists.
int equals(List L);

// Manipulation procedures ----------------------------------------------------

// clear()
// pre:none
// Resets this List to its original empty state.
void clear();

// moveFront()
// pre:none
// If List is non-empty, places the cursor under the front element,
// otherwise does nothing.
void moveFront();

// moveBack()
// pre:none
// If List is non-empty, places the cursor under the back element,
// otherwise does nothing.
void moveBack();

// movePrev()
// pre: none
// If cursor is defined and not at front, moves cursor one step toward
// front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.
void movePrev();

// moveNext()
// pre: none
// If cursor is defined and not at back, moves cursor one step toward
// back of this List, if cursor is defined and at back, cursor becomes
// undefined, if cursor is undefined does nothing.
void moveNext();

// prepend()
// pre:none
// Insert new element into this List. If List is non-empty,
// insertion takes place before front element.
void prepend(int data);

// append()
// pre:none
// Insert new element into this List. If List is non-empty,
// insertion takes place after back element.
void append(int data); 

// insertBefore()
// Pre: length()>0, index()>=0
// Insert new element before cursor.
void insertBefore(int data);

// insertAfter()
// Pre: length()>0, index()>=0
// Inserts new element after cursor.
void insertAfter(int data);

// deleteFront()
// Pre: length()>0
// Deletes the front element. 
void deleteFront();

// deleteBack()
// Pre: length()>0
// Deletes the back element.
void deleteBack();

// delete() 
// Pre: length()>0, index()>=0
// Deletes cursor element, making cursor undefined.
void delete();

// Other operations -----------------------------------------------------------

// printList()
// pre:none
// Overrides Object's toString method. Returns a String
// representation of this List consisting of a space
// separated sequence of integers, with front on left.
void printList(FILE* out, List L);

// copy()
// pre:none
// Returns a new List representing the same integer sequence as this
// List. The cursor in the new list is undefined, regardless of the
// state of the cursor in this List. This List is unchanged.
List copyList(List L);


#endif
