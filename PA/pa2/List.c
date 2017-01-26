// ---------------------------------------------------------------
// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa2
// 1/27/17
// List.c
// ----------------------------------------------------------------
//-----------------------------------------------------------------------------
// List.c
// Implementation file for List ADT
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include "List.h"
// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
    int data;
    struct NodeObj* next;
    struct NodeObj* prev;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private QueueObj type
typedef struct ListObj{
    Node head;// stores number of the nodes
    Node tail;// points to the back of the list
    Node cursor; // it will point to a specific index of an element
    int index; // index of the cursor
    int length; // stores number of the nodes
} ListObj;

// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
// Private.
Node newNode(int data){
    Node N = malloc(sizeof(NodeObj));
    N->data = data;
    N->next = N->prev = NULL;
    return(N);
}

// freeNode()
// pre: *pN != NULL, pN != NULL
// Frees heap memory pointed to by *pN, sets *pN to NULL.
// Private.
void freeNode(Node* pN){
    if( pN!=NULL && *pN!=NULL ){
        free(*pN);
        *pN = NULL;
    }
}

// newList()
// pre: *pL != NULL, pL != NULL
// Returns reference to new empty List object.
List newList(void){
    List L;
    L = malloc(sizeof(ListObj));
    L->head = L->tail = L->cursor= NULL;
    L->length = 0;
    L->index = 0;
    return(L);
}


// freeList()
// pre: *pL != NULL, pL != NULL
// Frees all heap memory associated with List *pL, and sets *pL to NULL
void freeList(List* pL){
    if(pL!=NULL && *pL!=NULL) {
        while( length(*pL) != 0 ) {
            deleteBack(*pL);
        }
        free(*pL);
        *pL = NULL;
    }
}
// Access functions -----------------------------------------------------------

// length()
// pre: L != NULL
// Returns the length of L.
int length(List L)
{
    if( L==NULL ){
        printf("List Error: calling length() on NULL List reference\n");
        exit(1);
    }
    return L->length;
}

//index()
// pre: L != NULL
// If cursor is defined, returns the index of the cursor element,
// otherwise returns -1.
int index(List L)
{
    if( L==NULL ){
        printf("List Error: calling index() on NULL List reference\n");
        exit(1);
    }
    if(L->cursor!=NULL)
    {
        return index;
    }
    else
    {
        return -1;
    }
}

// front()
// Pre: L != NULL, length()>0
// Returns front element.
int front(List L)
{
    if( L==NULL ){
        printf("List Error: calling front() on NULL List reference\n");
        exit(1);
    }
    if( length(L)<=0 ){
        printf("List Error: calling front() on an empty List\n");
        exit(1);
    }
    return L->head->data;
}

// back()
// Pre: L != NULL, length()>0
// Returns back element. 
int back(List L)
{
    if( L==NULL ){
        printf("List Error: calling back() on NULL List reference\n");
        exit(1);
    }
    if( length(L)<=0 ){
        printf("List Error: calling back() on an empty List\n");
        exit(1);
    }
    return L->tail->data;
}

// get()
// Pre: L != NULL, length()>0, index()>=0
// Returns cursor element.
int get(List L)
{
    if( L==NULL ){
        printf("List Error: calling get() on NULL List reference\n");
        exit(1);
    }
    if( length(L)<=0 ){
        printf("List Error: calling get() on an empty List\n");
        exit(1);
    }
    if( index(L)==-1 ){
        printf("List Error: calling get() on index -1\n");
        exit(1);
    }
    return L->index;
}

// equals()
// pre: L != NULL, C != NULL
// Returns true if this List and L are the same integer
// sequence. The cursor is ignored in both lists.
int equals(List L,List C)
{
    if( L==NULL ){
        printf("List Error: calling equals() on NULL List reference L\n");
        exit(1);
    }
    if( C==NULL ){
        printf("List Error: calling equals() on NULL List reference C\n");
        exit(1);
    }
    if(length(L) != length(C))
    {
        return 0;
    }
    else
    {
        Node r = L->head;
        Node l = C->head;
        int flag = 1;
        while(r != NULL && flag == 1)// since its already checked for same length,
            //it doesn't matter which Node pointer I use
        {
            if(r->data == l->data)
            {
                r = r->next;
                l = l->next;
            }
            else
            {
                flag = 0;
            }
        }
        return flag;

    }
}

// Manipulation procedures ----------------------------------------------------

// clear()
// pre: L != NULL
// Resets this List to its original empty state.
void clear(List L)
{
    if( L==NULL ){
        printf("List Error: calling clear() on NULL List reference\n");
        exit(1);
    }
    while( length(L) != 0 ) {
        deleteBack(L);
    }
    free(L);
    L = NULL;
}


// moveFront()
// pre: L != NULL
// If List is non-empty, places the cursor under the front element,
// otherwise does nothing.
void moveFront(List L)
{
    if( L==NULL ){
        printf("List Error: calling moveFront() on NULL List reference\n");
        exit(1);
    }
    if(length(L)!=0)
    {
        L->cursor = L->head;
        L->index=0;
    }
}

// moveBack()
// pre: L != NULL
// If List is non-empty, places the cursor under the back element,
// otherwise does nothing.
void moveBack(List L)
{
    if( L==NULL ){
        printf("List Error: calling moveBack() on NULL List reference\n");
        exit(1);
    }
    if(length(L)!=0)
    {
        L->cursor = L->tail;
        L->index = length(L)-1;
    }
}

// movePrev()
// pre: L != NULL
// If cursor is defined and not at front, moves cursor one step toward
// front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.
void movePrev(List L)
{
    if( L==NULL ){
        printf("List Error: calling movePrev() on NULL List reference\n");
        exit(1);
    }
    if(L->cursor != NULL && L->cursor!=L->head)
    {
        L->cursor = L->cursor->prev;
        L->index--;
    }
    else if(L->cursor != NULL && L->cursor == L->head)// if cursor passes head
    {
        L->cursor = L->NULL;
        //index=-1;
    }
}

// moveNext()
// pre: L != NULL
// If cursor is defined and not at back, moves cursor one step toward
// back of this List, if cursor is defined and at back, cursor becomes
// undefined, if cursor is undefined does nothing.
void moveNext(List L)
{
    if( L==NULL ){
        printf("List Error: calling moveNext() on NULL List reference\n");
        exit(1);
    }
    if(L->cursor != NULL && L->cursor!=L->tail)
    {
        L->cursor = L->cursor->next;
        L->index++;
    }
    else if(L->cursor != NULL && L->cursor == L->tail) // if cursor passes tail
    {
        L->cursor = NULL;
        //index=-1;
    }
}

// prepend()
// pre: L != NULL
// Insert new element into this List. If List is non-empty,
// insertion takes place before front element.
void prepend(List L,int data)
{
    if( L==NULL ){
        printf("List Error: calling prepend() on NULL List reference\n");
        exit(1);
    }
    if(length(L) != 0)
    {
        L->head->prev = newNode(data);
        L->head->prev->next = L->head;
        L->head = L->head->prev;
    }
    else
    {
        L->tail = L->head = newNode(data);
    }
    L->length++;
}

// append()
// pre: L != NULL
// Insert new element into this List. If List is non-empty,
// insertion takes place after back element.
void append(List L,int data)
{
    if( L==NULL ){
        printf("List Error: calling append() on NULL List reference\n");
        exit(1);
    }
    if(length(L) != 0)
    {
        L->tail->next =  newNode(data);
        L->tail->next->prev = L->tail;
        L->tail = L->tail->next;
    }
    else
    {
        L->tail = L->head = newNode(data);
    }
    L->length++;
}

// insertBefore()
// Pre: L != NULL,length()>0, index()>=0
// Insert new element before cursor.
void insertBefore(List L,int data)
{
    if( L==NULL ){
        printf("List Error: calling insertBefore() on NULL List reference\n");
        exit(1);
    }
    if(length(L)<=0)
    {
        printf("List Error: calling insertBefore() on empty List\n");
        exit(1);
    }
    if(index(L)<0)
    {
        printf("List Error: calling insertBefore() on a cursor pointed to NULL\n");
        exit(1);
    }

    Node prev = L->cursor->prev;
    Node n = newNode(data); // new node
    L->cursor->prev = n;
    n->next = L->cursor;
    if(prev != NULL) // assuming the cursor is at head
    {
        prev->next = n;
    }
    n->prev = prev;
    if(L->index == 0) // cursor is at head therefore head needs to be relocated
    {
        L->head = n;
    }
    L->length++;
    L->index++;
}

// insertAfter()
// Pre: L != NULL,length()>0, index()>=0
// Inserts new element after cursor.
void insertAfter(List L,int data)
{

    if( L==NULL ){
        printf("List Error: calling insertAfter() on NULL List reference\n");
        exit(1);
    }
    if(length(L)<=0)
    {
        printf("List Error: calling insertAfter() on empty List\n");
        exit(1);
    }
    if(index(L)<0)
    {
        printf("List Error: calling insertAfter() on a cursor pointed to NULL\n");
        exit(1);
    }

    Node n = newNode(data);
    Node next = L->cursor->next;
    L->cursor->next = n;
    n->prev = L->cursor;
    n->next = next;
    if(next != NULL) // assuming the cursor is at tail
    {
        next->prev = n;
    }
    if(index(L) == length(L)-1) //cursor is at tail therefore tail needs to be relocated
    {
        L->tail = n;
    }
    L->length++;
}

// deleteFront()
// Pre: L != NULL,length()>0
// Deletes the front element. 
void deleteFront(List L)
{
    if( L==NULL ){
        printf("List Error: calling deleteFront() on NULL List reference\n");
        exit(1);
    }
    if(length(L)<=0)
    {
        printf("List Error: calling deleteFront() on empty List\n");
        exit(1);
    }
    Node delete = L->head;
    L->head = L->head->next;
    L->head->prev = NULL;
    freeNode(&L);
    L->length--;
}

// deleteBack()
// Pre: L != NULL, length()>0
// Deletes the back element.
void deleteBack(List L)
{
    if( L==NULL ){
        printf("List Error: calling deleteBack() on NULL List reference\n");
        exit(1);
    }
    if(length(L)<=0)
    {
        printf("List Error: calling deleteBack() on empty List\n");
        exit(1);
    }
    Node delete = L->tail;
    L->tail = L->tail->prev;
    L->tail->next = NULL;
    freeNode(&L);
    L->length--;
}

// delete() 
// Pre: L != NULL, length()>0, index()>=0
// Deletes cursor element, making cursor undefined.
void delete(List L)
{

    if( L==NULL ){
        printf("List Error: calling delete() on NULL List reference\n");
        exit(1);
    }
    if(length(L)<=0)
    {
        printf("List Error: calling delete() on empty List\n");
        exit(1);
    }
    if(index(L)<0)
    {
        printf("List Error: calling delete() on a cursor pointed to NULL\n");
        exit(1);
    }
    Node delete = L->cursor;
    Node prev = L->cursor->prev;
    Node next = L->cursor->next;
    if(prev != NULL && next != NULL)//cursor is between two nodes
    {
        prev->next = next;
        next->prev = prev;
    }
    else if(next == NULL) // cursor is at the back  of the list
    {
        prev->next = next;
    }
    else if(prev == NULL) // cursor is at the front of the list
    {
        next->prev = prev;
    }
    L->cursor->next=NULL;
    L->cursor->prev=NULL;
    L->cursor = NULL;
    freeNode(&delete);
    L->length--;
}

// Other operations -----------------------------------------------------------

// printList()
// pre: L != NULL
// Prints data elements in L on a single line to stdout.
void printList(FILE* out, List L)
{
    if( L==NULL ){
        printf("List Error: calling delete() on NULL List reference\n");
        exit(1);
    }
    for(Node ptr = L->head;ptr!=NULL;ptr=ptr->next)
    {
        fprintf(out,"%i\n",ptr->data);
    }
}

// copy()
// pre: L != NULL
// Returns a new List representing the same integer sequence as this
// List. The cursor in the new list is undefined, regardless of the
// state of the cursor in this List. This List is unchanged.
List copyList(List L)
{
    if( L==NULL ){
        printf("List Error: calling delete() on NULL List reference\n");
        exit(1);
    }
    List n = newList();
    for(Node ptr = L->head;ptr!=NULL;ptr=ptr->next)
    {
        append(n,ptr->data);
    }
    return n;
}


#endif
