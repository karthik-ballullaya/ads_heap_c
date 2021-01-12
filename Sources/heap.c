#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include "heap.h"

HEAP create_new_heap(uint32_t size) {
  HEAP h;
  h.size = size;
  h.length = 0;
  h.data = (DATATYPE *)malloc(sizeof(DATATYPE *) * size);
  return h;
}

static void _swap_(DATATYPE *a, DATATYPE *b) {
  DATATYPE temp = *a;
  *a = *b;
  *b = temp;
}

static void _heapify_(HEAP * heap, uint32_t index) {
  uint32_t largest = index, l = (2 * index) + 1, r = (2 * index) + 2;
  if (l < heap->length && heap->data[l] > heap->data[largest])
    largest = l;
  if (r < heap->length && heap->data[r] > heap->data[largest])
    largest = r;
  if (largest != index) {
    _swap_(&heap->data[largest], &heap->data[index]);
    _heapify_(heap, largest);
  }
}

HEAP * add_element(HEAP *heap, int32_t ele) {
  assert(heap != NULL);
  if (heap->length < heap->size) {
    heap->data[heap->length++] = ele;
    for (int32_t i = heap->length / 2 - 1; i >= 0; i--) {
      _heapify_(heap, i);
    }
  }
}

int32_t get_max_element(HEAP* heap) {
  return heap->data[0];
}

int32_t extract_max_element(HEAP* heap) {
  _swap_(&heap->data[--heap->length], &heap->data[0]);
  _heapify_(heap, 0);
  return heap->data[heap->length];
}

uint32_t heap_length(HEAP* heap) {
  return heap->length;
}

uint32_t test_heap_property(HEAP* heap) {
  for (uint32_t i = 0; i < ((heap->length - 1) / 2); i++) {
    uint32_t largest = i, l = (i * 2) + 1, r = (i * 2) + 2;
    if (l < heap->length && heap->data[l] > heap->data[largest])
      largest = l;
    if (r < heap->length && heap->data[r] > heap->data[largest])
      largest = r;
    if (largest != i)
      return 0;
  }
  return 1;
}