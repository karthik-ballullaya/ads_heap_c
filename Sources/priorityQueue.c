#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "priorityQueue.h"

PriorityQueue create_priority_queue(uint32_t size) {
  PriorityQueue q;
  q.data = (TaskNode **) malloc(sizeof(TaskNode *) * size);
  q.length = 0;
  q.size = size;
  return q;
}

static TaskNode * _create_task_node(int32_t id, uint32_t priority, int32_t arrivalTime, int32_t executionTime, int32_t deadlineTime) {
  TaskNode *node = (TaskNode *) malloc(sizeof(TaskNode));
  node->id = id;
  node->priority = priority;
  node->arrivalTime = arrivalTime;
  node->executionTime = executionTime;
  node->deadlineTime = deadlineTime;
  return node;
}

static void _swap_(TaskNode **a, TaskNode **b) {
  TaskNode *temp = *a;
  *a = *b;
  *b = temp;
}

static void _heapify_(PriorityQueue *q, uint32_t index) {
  uint32_t smallest = index, l = (index * 2) + 1, r = (index * 2) + 2;
  if (l < q->length && q->data[l]->priority < q->data[smallest]->priority) {
    smallest = l;
  } if (r < q->length && q->data[r]->priority < q->data[smallest]->priority) {
    smallest = r;
  }
  if (smallest != index) {
    _swap_(&q->data[smallest], &q->data[index]);
    _heapify_(q, smallest);
  }
}

PriorityQueue * add_task(PriorityQueue *q, int32_t id, uint32_t priority, int32_t arrivalTime, int32_t executionTime, int32_t deadlineTime) {
  assert(q != NULL);
  if (q->length < q->size) {
    TaskNode *node = _create_task_node(id, priority, arrivalTime, executionTime, deadlineTime);
    q->data[q->length++] = node;
    for (int32_t i = q->length / 2 - 1; i >= 0; i--) {
      _heapify_(q, i);
    }
  }
}

static void _priority_sort_(PriorityQueue *q) {
  uint32_t q_length = q->length;
  while (q->length) {
    _swap_(&q->data[--q->length], &q->data[0]);
    _heapify_(q, 0);
  }
  q->length = q_length;
}

void perform_task(PriorityQueue *q) {
  int32_t time = 0;
  _priority_sort_(q);
  for (uint32_t i = 0; i < q->length; i++) {
    TaskNode *node = q->data[i];
    time = time + node->executionTime;
    printf("Task id %d is completed at %d time ", node->id, time);
    printf((time < node->deadlineTime) ? "and is completed within dealine\n" : "and not completed within dealine\n");
  }
}


int main(void) {
  PriorityQueue q1 = create_priority_queue(10), *q = &q1;
  add_task(q, 1, 10, 0, 5, 10);
  add_task(q, 2, 2, 5, 6, 15);
  add_task(q, 3, 1, 10, 7, 30);
  add_task(q, 4, 3, 15, 8, 45);
  add_task(q, 5, 5, 20, 9, 50);
  add_task(q, 6, 9, 25, 1, 55);
  add_task(q, 7, 6, 30, 10, 60);
  add_task(q, 8, 4, 35, 6, 50);
  perform_task(q);
}