#ifndef _HEAP_H_INCLUDED_
#define _HEAP_H_INCLUDED_

#ifndef DATATYPE
#define DATATYPE int32_t
#endif

#include <stdint.h>

typedef struct _heap_ HEAP;

struct _heap_ {
  DATATYPE       *data;
  uint32_t       length;
  uint32_t       size;
};

HEAP create_new_heap(uint32_t);
HEAP *  add_element(HEAP *, int32_t);
int32_t get_max_element(HEAP *);
int32_t  extract_max_element(HEAP *);
uint32_t heap_length(HEAP *);
uint32_t test_heap_property(HEAP *);


#endif