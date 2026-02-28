#define DYNAMIC_ARRAY_IMPLEMENTATION
#include "../ds_dynamic_array.h"
#include <stdio.h>

typedef struct {
  float x;
  float y;
  float z;
} vec3;
DA_DECLARE(vec3, vec3_array);

int main(void) {
  vec3_array da;
  vec3_array_init(&da);

  for (int x = 0; x < 10; x++) {
    vec3 y = {(float)x, (float)x + 1.0f, (float)x + 2.0f};
    vec3_array_append(&da, y);
  }

  for (size_t i = 0; i < da.base.count; i++) {
    printf("%f\n", vec3_array_get(&da, i).x);
  }

  return 0;
}
