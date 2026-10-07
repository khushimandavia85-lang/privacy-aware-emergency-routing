#include <stdio.h>
#include "graph.h"

void initializeGraph(Graph *graph)
{
    graph->vertices = MAX_VERTICES;

    for (int i = 0; i < MAX_VERTICES; i++)
    {
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            if (i == j)
            {
                graph->adjacency[i][j] = 0;
            }
            else
            {
                graph->adjacency[i][j] = INF;
            }
        }
    }

    /*
        Sample road network.

        0 = Ambulance Base
        1 = Location A
        2 = Location B
        3 = Location C
        4 = Location D
        5 = Hospital
    */

    addRoad(graph, 0, 1, 4);
    addRoad(graph, 0, 2, 2);

    addRoad(graph, 1, 2, 1);
    addRoad(graph, 1, 3, 5);

    addRoad(graph, 2, 3, 3);
    addRoad(graph, 2, 4, 7);

    addRoad(graph, 3, 4, 2);
    addRoad(graph, 3, 5, 6);

    addRoad(graph, 4, 5, 1);
}

void addRoad(Graph *graph, int source, int destination, int distance)
{
    if (source < 0 || source >= MAX_VERTICES ||
        destination < 0 || destination >= MAX_VERTICES)
    {
        return;
    }

    /*
        The road is bidirectional.
    */

    graph->adjacency[source][destination] = distance;
    graph->adjacency[destination][source] = distance;
}

void displayGraph(Graph *graph)
{
    printf("\n============================================\n");
    printf("              ROAD NETWORK\n");
    printf("============================================\n");

    printf("0 = Ambulance Base\n");
    printf("1 = Location A\n");
    printf("2 = Location B\n");
    printf("3 = Location C\n");
    printf("4 = Location D\n");
    printf("5 = Hospital\n");

    printf("\nRoad Connections:\n");

    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = i + 1; j < graph->vertices; j++)
        {
            if (graph->adjacency[i][j] != INF &&
                graph->adjacency[i][j] != 0)
            {
                printf("%d <---- %d km ----> %d\n",
                       i,
                       graph->adjacency[i][j],
                       j);
            }
        }
    }

    printf("============================================\n");
}