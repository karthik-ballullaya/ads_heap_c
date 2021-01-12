#ifndef _PRIORITY_QUEUE_H_INCLUDED_
#define _PRIORITY_QUEUE_H_INCLUDED_

#include <stdint.h>

typedef struct _task_node_ TaskNode;
typedef struct _priority_queue_ PriorityQueue;


struct _task_node_  {
  int32_t id;
  uint32_t priority;
  int32_t arrivalTime;
  int32_t executionTime;
  int32_t deadlineTime;
};

struct _priority_queue_ {
  TaskNode       **data;
  uint32_t       length;
  uint32_t       size;
};

PriorityQueue create_priority_queue(uint32_t size);
PriorityQueue * add_task(PriorityQueue *q, int32_t id, uint32_t priority, int32_t arrivalTime, int32_t executionTime, int32_t deadlineTime);
void perform_task(PriorityQueue * q);

#endif