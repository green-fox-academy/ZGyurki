#include <stdio.h>
#include <stdlib.h>

int main() {
  int* pointer = (int*) calloc(5, sizeof(int));

  // TODO:
  // Please allocate a 5 long array and fill it with numbers from 0 to 4, then print the whole array
  // Please delete the array before the program exits

  for(int i = 0; i < 5; ++i){
    pointer[i] = i;
    printf("%d ", pointer[i]);
  }

  free(pointer);

  return 0;
}
