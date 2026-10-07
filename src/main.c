#include <stdio.h>

#include "emergency.h"
#include "priority_queue.h"
#include "graph.h"
#include "dijkstra.h"

void displayMainMenu()
{
    printf("\n\n");
    printf("====================================================\n");
    printf("       PRIVACY-AWARE EMERGENCY RESPONSE SYSTEM\n");
    printf("====================================================\n");

    printf("1. Register Emergency\n");
    printf("2. Display All Emergencies\n");
    printf("3. Display Priority Queue\n");
    printf("4. Process Highest Priority Emergency\n");
    printf("5. Find Shortest Ambulance Route\n");
    printf("6. Display Road Network\n");
    printf("7. Exit\n");

    printf("====================================================\n");
    printf("Enter your choice: ");
}

int main()
{
    Emergency emergencies[MAX_EMERGENCIES];

    int emergencyCount = 0;

    PriorityQueue priorityQueue;

    Graph graph;

    initializePriorityQueue(&priorityQueue);

    initializeGraph(&graph);

    int choice;

    printf("\n");
    printf("====================================================\n");
    printf("   PRIVACY-AWARE INTELLIGENT EMERGENCY SYSTEM\n");
    printf("====================================================\n");

    printf("\nSystem initialized successfully.\n");

    do
    {
        displayMainMenu();

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                /*
                    Register emergency in array.
                */

                registerEmergency(
                    emergencies,
                    &emergencyCount
                );

                /*
                    Add the newly registered emergency
                    to the priority queue.
                */

                if (emergencyCount > 0)
                {
                    enqueueEmergency(
                        &priorityQueue,
                        emergencies[emergencyCount - 1]
                    );
                }

                break;
            }

            case 2:
            {
                displayEmergencies(
                    emergencies,
                    emergencyCount
                );

                break;
            }

            case 3:
            {
                displayPriorityQueue(
                    &priorityQueue
                );

                break;
            }

            case 4:
            {
                if (isQueueEmpty(&priorityQueue))
                {
                    printf("\nNo emergency is waiting.\n");
                    break;
                }

                Emergency selected =
                    dequeueEmergency(
                        &priorityQueue
                    );

                int index =
                    findEmergency(
                        emergencies,
                        emergencyCount,
                        selected.id
                    );

                if (index != -1)
                {
                    snprintf(
                        emergencies[index].status,
                        STATUS_SIZE,
                        "Dispatched"
                    );
                }

                printf("\n============================================\n");
                printf("        EMERGENCY DISPATCHED\n");
                printf("============================================\n");

                printf("Emergency ID : %d\n",
                       selected.id);

                printf("Severity     : %d\n",
                       selected.severity);

                printf("Location     : %d\n",
                       selected.location);

                printf("Patient Token: %s\n",
                       selected.patientToken);

                printf("Status       : Ambulance Dispatched\n");

                printf("============================================\n");

                /*
                    Ambulance starts from location 0.
                    The emergency location is the destination.
                */

                printf("\nCalculating best route...\n");

                findShortestPath(
                    &graph,
                    0,
                    selected.location
                );

                break;
            }

            case 5:
            {
                int destination;

                printf("\nEnter emergency location (1-5): ");
                scanf("%d", &destination);

                if (destination < 1 ||
                    destination >= MAX_VERTICES)
                {
                    printf("\nInvalid destination.\n");
                    break;
                }

                /*
                    Ambulance starts from node 0.
                */

                findShortestPath(
                    &graph,
                    0,
                    destination
                );

                break;
            }

            case 6:
            {
                displayGraph(&graph);

                break;
            }

            case 7:
            {
                printf("\nExiting system...\n");
                printf("Thank you.\n");

                break;
            }

            default:
            {
                printf("\nInvalid choice. Please try again.\n");
            }
        }

    } while (choice != 7);

    return 0;
}