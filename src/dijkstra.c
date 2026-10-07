#include <stdio.h>
#include "dijkstra.h"

static int findMinimumDistance(
    int distance[],
    int visited[],
    int vertices)
{
    int minimum = INF;
    int minimumIndex = -1;

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i] &&
            distance[i] < minimum)
        {
            minimum = distance[i];
            minimumIndex = i;
        }
    }

    return minimumIndex;
}

static void printPath(
    int parent[],
    int destination)
{
    if (parent[destination] == -1)
    {
        printf("%d", destination);
        return;
    }

    printPath(parent, parent[destination]);

    printf(" -> %d", destination);
}

void findShortestPath(
    Graph *graph,
    int source,
    int destination)
{
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int parent[MAX_VERTICES];

    int vertices = graph->vertices;

    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    distance[source] = 0;

    for (int count = 0; count < vertices - 1; count++)
    {
        int current =
            findMinimumDistance(
                distance,
                visited,
                vertices
            );

        if (current == -1)
        {
            break;
        }

        visited[current] = 1;

        for (int neighbour = 0;
             neighbour < vertices;
             neighbour++)
        {
            if (!visited[neighbour] &&
                graph->adjacency[current][neighbour] != INF &&
                distance[current] != INF &&
                distance[current] +
                graph->adjacency[current][neighbour]
                < distance[neighbour])
            {
                distance[neighbour] =
                    distance[current] +
                    graph->adjacency[current][neighbour];

                parent[neighbour] = current;
            }
        }
    }

    printf("\n============================================\n");
    printf("          SHORTEST ROUTE RESULT\n");
    printf("============================================\n");

    if (distance[destination] == INF)
    {
        printf("No route is available.\n");
    }
    else
    {
        printf("Starting Location : %d\n", source);
        printf("Destination       : %d\n", destination);

        printf("Shortest Distance : %d km\n",
               distance[destination]);

        printf("Best Route        : ");

        printPath(parent, destination);

        printf("\n");
    }

    printf("============================================\n");
}