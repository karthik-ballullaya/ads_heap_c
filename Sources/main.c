#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

void test_heap(void) {
  HEAP h = create_new_heap(10), *heap = &h;
  add_element(heap, 10);
  add_element(heap, 20);
  add_element(heap, 30);
  add_element(heap, 60);
  add_element(heap, 40);
  add_element(heap, 50);
  assert(heap_length(heap) == 6);
  assert(extract_max_element(heap) == 60);
  assert(test_heap_property(heap));
  assert(get_max_element(heap) == 50);
  assert(test_heap_property(heap));
}

int main() {
  test_heap();
  return 0;
}