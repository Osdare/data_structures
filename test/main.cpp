#define DYNAMIC_ARRAY_IMPLEMENTATION
#include "../ds_dynamic_array.h"
#include <stdio.h>

int main(void) {
  dynarray_t da;
  da_init(&da, sizeof(int));

  for (int x = 0; x < 10; x++) {
    da_append(&da, &x);
  }

  for (size_t i = 0; i < da.count; i++) {
    printf("%d\n", DA_GET(&da, int, i));
  }

  return 0;
}
