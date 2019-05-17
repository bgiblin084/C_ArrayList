#include <stdlib.h>
#include "intArrayList.h"

intArrayList* intArrayList_create(int length) {
  if (length <= 0) length = 1;

  intArrayList* arrLi = (intArrayList*) malloc(sizeof(intArrayList));
  arrLi->length = length;
  arrLi->arr = malloc(sizeof(int) * length);
  arrLi->back = 0;

  if (arrLi->arr == NULL) {
    fprintf(stderr, "Error Allocating Memory\n");
    return NULL;
  }

  return arrLi;
}

int intArrayList_get(intArrayList* arrLi, int index) {
  if (index > arrLi->back || index < 0) {
    fprintf(stderr, "Out of bounds!\n");
    return -1;
  }

  return arrLi->arr[index];
}

void intArrayList_add(intArrayList* arrLi, int val) {
  if(arrLi->back >= arrLi->length) {
    intArrayList_grow(arrLi, 3.0/2.0);
  }

  arrLi->arr[arrLi->back] = val;
  arrLi->back++;

}

void intArrayList_addAll(intArrayList* target, intArrayList* source){
  if(target->arr == NULL || source->arr == NULL) {
    fprintf(stderr, "Invalid Arguments: both lists must be initialized\n");
    return;
  }
  for (int i = 0; i < intArrayList_size(source); i ++) {
    intArrayList_add(target, intArrayList_get(source, i));
  }
}

void intArrayList_addAtIndex(intArrayList* arrLi, int val, int index){
  if (index < 0 || index >= arrLi->back) {
    fprintf(stderr, "Index out of bounds\n");
    return;
  }
  if (index < arrLi->back) {
    int temp = intArrayList_get(arrLi, index);
    arrLi->arr[index] = val;
    intArrayList_addAtIndex(arrLi, temp, index + 1);
  }
  else intArrayList_add(arrLi, val);
}

int intArrayList_remove(intArrayList* arrLi, int index) {
  int val;
  if (index < 0 || index >= intArrayList_size(arrLi)) {
    fprintf(stderr, "Index out of bounds\n");
    return - 1;
  }
  val = intArrayList_get(arrLi, index);
  for (int i = index; i < intArrayList_size(arrLi) - 1; i ++){
    intArrayList_set(arrLi, intArrayList_get(arrLi, i + 1), i);
  }
  arrLi->back--;
  return val;
}

int intArrayList_set(intArrayList* arrLi, int val, int index) {
  if (index < 0 || index > arrLi->back) {
    fprintf(stderr, "Index out of bounds\n");
    return -1;
  }
  int temp = intArrayList_get(arrLi, index);
  arrLi->arr[index] = val;

  return temp;
}

void intArrayList_grow(intArrayList* arrLi, int mult) {
  arrLi->length *= mult;
  arrLi->arr = realloc(arrLi->arr, arrLi->length * sizeof(int));

  if (arrLi->arr == NULL) {
    fprintf(stderr, "Error Allocating Memory\n");
    arrLi = NULL;
    return;
  }
}

intArrayList* intArrayList_clone(intArrayList* arrLi) {
  intArrayList* new = intArrayList_create(arrLi->length);

  for (int i = 0; i < intArrayList_size(arrLi); i++) {
    intArrayList_add(new, intArrayList_get(arrLi, i));
  }

  return new;
}

int intArrayList_indexOf(intArrayList* arrLi, int val){
  int i = -1;
  int index = 0;
  while(i < 0 && index < intArrayList_size(arrLi)) {
    i = val == intArrayList_get(arrLi, index) ? index : i;
    index++;
  }

  return i;
}

int intArrayList_lastIndexOf(intArrayList* arrLi, int val){
  int i = -1;
  int index = intArrayList_size(arrLi) - 1;
  while(i < 0 && index >= 0) {
    i = val == intArrayList_get(arrLi, index) ? index : i;
    index--;
  }

  return i;
}

void intArrayList_ensureCapacity(intArrayList* arrLi, int numElem){
  int size = intArrayList_size(arrLi);
  if (size >= numElem) {
    return;
  }
  int multi = numElem / size + (numElem % size != 0);

  intArrayList_grow(arrLi, multi);
}

int intArrayList_size(intArrayList* arrLi) {
  return arrLi->back;
}

void intArrayList_clear(intArrayList** arrLi) {
  free((*arrLi)->arr);
  free(*arrLi);
}
