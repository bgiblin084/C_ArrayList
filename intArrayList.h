/*
 * ArrayList Implementation
 * Author: Braedon Giblin <bgiblin@iastate.edu>
 */
#ifndef INTARRAYLIST_H
#define INTARRAYLIST_H 1

typedef struct intArrayList_struct {
  int length;
  int* arr;
  int back;
} intArrayList;

//creates a new arraylist of the specificed length
intArrayList* intArrayList_create(int length);

//gets the element in the specified arrayList at index
int intArrayList_get(intArrayList* arrLi, int index);

//appends a value to the end of an arrayList
void intArrayList_add(intArrayList* arrLi ,int val);

//appends all elements of arrayList source to target list
void intArrayList_addAll(intArrayList* target, intArrayList* source);

//adds a value at the given index, then shifts all following values
void intArrayList_addAtIndex(intArrayList* arrLi, int val, int index);

//adds a value at the given index, then shifts all following values
void intArrayList_addAtIndex(intArrayList* arrLi, int val, int index); //TODO

//returns a new arrayList containing a clone
intArrayList* intArrayList_clone(intArrayList* arrLi);

//doubles the size of the arrayList
void intArrayList_grow(intArrayList* arrLi, int mult);

//gets the total size of the arrayList
int intArrayList_size(intArrayList* arrLi);

//removes all elements from arrayList
void intArrayList_clear(intArrayList** arrLi);

//finds the index of a specified element;
int intArrayList_indexOf(intArrayList* arrLi, int val);

//finds the last index of a specified element
int intArrayList_lastIndexOf(intArrayList* arrLi, int val);

//sets the element at index to a new value, and returns the previous value
int intArrayList_set(intArrayList* arrLi, int val, int index);

//ensures that the given arrayList can hold the speciied number of elements, and grows if needed
void intArrayList_ensureCapacity(intArrayList* arrLi, int numElem);

//Removes element at index from list and shifts the remaining list elements to fill gap
int intArrayList_remove(intArrayList* arrLi, int index);

#endif
