/**********
 * Problem statement:
 * *  An airport is developing a computer simulation of air-traffic control that handles events such as landings and takeoffs.
 * *  Each event has a time stamp that denotes the time when the event will occur with additional information like:
 *       plane number, takeoff or landing.
 * *  The simulation program needs to efficiently perform the following two fundamental operations:
 *      1. Insert an event with a given time stamp, aircraft number, takeoff / landing (add a future event).
 *      2. Extract the event with smallest time stamp (that is, determine the next event to process).
 * Design and implement suitable data structures that work efficiently in terms of time.
 * 
**********/

#ifndef AIRPORT_SIMULATION_H_
#define AIRPORT_SIMULATION_H_

#include <stdint.h>

typedef enum _event_ Event;
typedef struct _event_node_ EventNode;
typedef struct _event_list_ EventList;

enum _event_ {
  LANDING,
  TAKEOFF
};

struct _event_node_  {
  int32_t       time_stamp;
  uint32_t      plane_number;
  Event         event;
};

struct _event_list_ {
  EventNode      **data;
  uint32_t       length;
  uint32_t       size;
};

#endif