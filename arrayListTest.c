#include <stdio.h>
#include "intArrayList.h"
#include "intArrayList.c"

int main() {
  intArrayList* arrLi = intArrayList_create(10);
  intArrayList* source = intArrayList_create(5);

  intArrayList_add(arrLi, 10);
  intArrayList_set(arrLi, 9, 0);

  for (int i = 0; i < intArrayList_size(arrLi); i++) {
    printf("%3d\n", intArrayList_get(arrLi, i));
  }

  
  intArrayList_clear(&source);
  intArrayList_clear(&arrLi);
}
