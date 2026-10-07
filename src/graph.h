#ifndef GRAPH_H
#define GRAPH_H

#define MAX_VERTICES 6
#define INF 999999

typedef struct
{
    int vertices;
    int adjacency[MAX_VERTICES][MAX_VERTICES];

} Graph;

void initializeGraph(Graph *graph);

void addRoad(Graph *graph, int source, int destination, int distance);

void displayGraph(Graph *graph);

#endif