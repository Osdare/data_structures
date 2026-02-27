#define DYNAMIC_ARRAY_IMPLEMENTATION
#include "../ds_dynamic_array.h"
#include <stdio.h>

typedef struct {
  float x;
  float y;
  float z;
} vec3;

int main(void) {
  dynarray_t da;
  da_init(&da, sizeof(vec3));

  for (int x = 0; x < 10; x++) {
    vec3 y = {(float)x, (float)x + 1.0f, (float)x + 2.0f};
    da_append(&da, &y);
  }

  for (size_t i = 0; i < da.count; i++) {
    printf("%f\n", DA_GET(&da, vec3, i).x);
  }

  return 0;
}
