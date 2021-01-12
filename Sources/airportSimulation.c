#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "airportSimulation.h"

EventList create_event_list(uint32_t size) {
  EventList e;
  e.data = (EventNode **) malloc(sizeof(EventNode *) * size);
  e.length = 0;
  e.size = size;
  return e;
}

static EventNode * _create_event_node(int32_t time_stamp, uint32_t plane_number, Event event) {
  EventNode *node = (EventNode *) malloc(sizeof(EventNode));
  node->time_stamp = time_stamp;
  node->plane_number = plane_number;
  node->event = event;
  return node;
}

static void _swap_(EventNode **a, EventNode **b) {
  EventNode *temp = *a;
  *a = *b;
  *b = temp;
}

static void _heapify_(EventList *q, uint32_t index) {
  uint32_t smallest = index, l = (index * 2) + 1, r = (index * 2) + 2;
  if (l < q->length && q->data[l]->time_stamp < q->data[smallest]->time_stamp) {
    smallest = l;
  } if (r < q->length && q->data[r]->time_stamp < q->data[smallest]->time_stamp) {
    smallest = r;
  }
  if (smallest != index) {
    _swap_(&q->data[smallest], &q->data[index]);
    _heapify_(q, smallest);
  }
}

EventList * add_event(EventList *q, int32_t time_stamp, uint32_t plane_number, Event event) {
  assert(q != NULL);
  if (q->length < q->size) {
    EventNode *node = _create_event_node(time_stamp, plane_number, event);
    q->data[q->length++] = node;
    for (int32_t i = q->length / 2 - 1; i >= 0; i--) {
      _heapify_(q, i);
    }
  }
}

EventNode * extract_event(EventList *q) {
  _swap_(&q->data[--q->length], &q->data[0]);
  return q->data[q->length + 1];
}

int main(void) {
  EventList e1 = create_event_list(10), *e = &e1;
  add_event(e, 20, 101023, LANDING);
  add_event(e, 15, 101024, TAKEOFF);
  add_event(e, 5, 101025, LANDING);
  add_event(e, 20, 101026, TAKEOFF);
  add_event(e, 10, 101027, TAKEOFF);
  add_event(e, 1, 101028, LANDING);
  assert(extract_event(e)->time_stamp == 1);
  assert(extract_event(e)->time_stamp == 5);
}