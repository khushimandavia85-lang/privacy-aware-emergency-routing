#include <stdio.h>
#include "priority_queue.h"

void initializePriorityQueue(PriorityQueue *pq)
{
    pq->size = 0;
}

int isQueueEmpty(PriorityQueue *pq)
{
    return pq->size == 0;
}

int isQueueFull(PriorityQueue *pq)
{
    return pq->size == MAX_QUEUE_SIZE;
}

/*
    Higher severity = higher priority.

    If two emergencies have the same severity,
    the emergency with greater waiting time gets priority.
*/

static int hasHigherPriority(Emergency a, Emergency b)
{
    if (a.severity > b.severity)
    {
        return 1;
    }

    if (a.severity == b.severity &&
        a.waitingTime > b.waitingTime)
    {
        return 1;
    }

    return 0;
}

void enqueueEmergency(PriorityQueue *pq, Emergency emergency)
{
    if (isQueueFull(pq))
    {
        printf("\nPriority queue is full.\n");
        return;
    }

    int i = pq->size;

    /*
        Insert the emergency according to priority.
    */

    while (i > 0 &&
           hasHigherPriority(emergency, pq->data[i - 1]))
    {
        pq->data[i] = pq->data[i - 1];
        i--;
    }

    pq->data[i] = emergency;

    pq->size++;
}

Emergency dequeueEmergency(PriorityQueue *pq)
{
    Emergency emptyEmergency = {0};

    if (isQueueEmpty(pq))
    {
        printf("\nNo emergency is waiting.\n");
        return emptyEmergency;
    }

    Emergency selected = pq->data[0];

    for (int i = 1; i < pq->size; i++)
    {
        pq->data[i - 1] = pq->data[i];
    }

    pq->size--;

    return selected;
}

void displayPriorityQueue(PriorityQueue *pq)
{
    if (isQueueEmpty(pq))
    {
        printf("\nPriority queue is empty.\n");
        return;
    }

    printf("\n============================================\n");
    printf("           EMERGENCY PRIORITY QUEUE\n");
    printf("============================================\n");

    printf("%-8s %-10s %-10s %-12s\n",
           "ID",
           "Severity",
           "Location",
           "Waiting");

    printf("--------------------------------------------\n");

    for (int i = 0; i < pq->size; i++)
    {
        printf("%-8d %-10d %-10d %-12d\n",
               pq->data[i].id,
               pq->data[i].severity,
               pq->data[i].location,
               pq->data[i].waitingTime);
    }

    printf("============================================\n");
}