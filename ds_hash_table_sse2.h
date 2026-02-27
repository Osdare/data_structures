#ifndef DS_HASH_TABLE_H
#define DS_HASH_TABLE_H

#include <cstdint>
#include <immintrin.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum ctrl_t {
  ctrl_empty = 0b10000000,
  ctrl_deleted = 0b11111110,
  ctrl_sentinel = 0b11111111,
};

typedef struct {
  char *str;
  size_t len;
} hash_key;

#define GROUP_SIZE 16
typedef struct {
  hash_key key;
  size_t hash;
  void *item;
} hash_item;

typedef struct {
  hash_item *items;
  size_t item_size;
  uint8_t *ctrl;
  size_t capacity;
  size_t size;
} hash_table_t;

#ifdef __cplusplus
}
#endif

#endif // DS_HASH_TABLE_H

#define DS_HASH_TABLE_IMPLEMENTATION
#ifdef DS_HASH_TABLE_IMPLEMENTATION

size_t H1(size_t hash) { return hash >> 7; }
uint8_t H2(size_t hash) { return hash & 0x7F; }

void ht_init(hash_table_t *ht, size_t item_size) {
  *ht = {0};
  ht->item_size = item_size;
  ht->capacity = GROUP_SIZE;
}

int ht_match_group(uint8_t h2, const uint8_t *ctrl) {
  __m128i group = _mm_loadu_si128((const __m128i_u *)ctrl);
  __m128i match = _mm_set1_epi8(h2);
  __m128i cmp = _mm_cmpeq_epi8(group, match);
  return (_mm_movemask_epi8(cmp));
}

size_t ht_linear_probe(size_t group, size_t num_groups) {
  return (group + 1) % num_groups;
}

void ht_insert(hash_table_t *ht, hash_key *key, void *item) {

  size_t num_groups = ht->capacity / GROUP_SIZE;
  size_t hash = 
}

#endif // DS_HASH_TABLE_IMPLEMENTATION
