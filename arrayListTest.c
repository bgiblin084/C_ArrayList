#include <stdio.h>
#include "intArrayList.h"

int main() {
  intArrayList* arrLi = intArrayList_create(10);
  //intArrayList* source = intArrayList_create(5);

  intArrayList_add(arrLi, 1);
  intArrayList_add(arrLi, 2);
  intArrayList_add(arrLi, 3);
  intArrayList_add(arrLi, 4);
  intArrayList_add(arrLi, 5);

  for (int i = 0; i < intArrayList_size(arrLi); i++) {
    printf("%3d\n", intArrayList_get(arrLi, i));
  }


  //intArrayList_clear(&source);
  intArrayList_clear(&arrLi);
}
