#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"
typedef list* queue;

bool enqueue(queue q, Data d);
Data dequeue(queue q);
Data first(queue q);
#endif