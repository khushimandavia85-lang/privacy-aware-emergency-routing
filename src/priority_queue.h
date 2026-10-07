#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "emergency.h"

#define MAX_QUEUE_SIZE 100

typedef struct
{
    Emergency data[MAX_QUEUE_SIZE];
    int size;

} PriorityQueue;

void initializePriorityQueue(PriorityQueue *pq);

int isQueueEmpty(PriorityQueue *pq);

int isQueueFull(PriorityQueue *pq);

void enqueueEmergency(PriorityQueue *pq, Emergency emergency);

Emergency dequeueEmergency(PriorityQueue *pq);

void displayPriorityQueue(PriorityQueue *pq);

#endif