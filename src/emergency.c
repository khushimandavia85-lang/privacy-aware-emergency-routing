#include <stdio.h>
#include "emergency.h"

void registerEmergency(Emergency emergencies[], int *count)
{
    if (*count >= MAX_EMERGENCIES)
    {
        printf("\nEmergency storage is full.\n");
        return;
    }

    Emergency *e = &emergencies[*count];

    printf("\n========================================\n");
    printf("        REGISTER EMERGENCY\n");
    printf("========================================\n");

    printf("Enter Emergency ID: ");
    scanf("%d", &e->id);

    printf("Enter Severity (1-5): ");
    scanf("%d", &e->severity);

    if (e->severity < 1 || e->severity > 5)
    {
        printf("Invalid severity. Setting severity to 1.\n");
        e->severity = 1;
    }

    printf("Enter Location ID (1-5): ");
    scanf("%d", &e->location);

    if (e->location < 1 || e->location > 5)
    {
        printf("Invalid location. Setting location to 1.\n");
        e->location = 1;
    }

    printf("Enter Waiting Time in minutes: ");
    scanf("%d", &e->waitingTime);

    printf("Enter Anonymous Patient Token: ");
    scanf("%29s", e->patientToken);

    snprintf(e->status, STATUS_SIZE, "Waiting");

    (*count)++;

    printf("\nEmergency registered successfully!\n");
}

void displayEmergencies(Emergency emergencies[], int count)
{
    if (count == 0)
    {
        printf("\nNo emergencies registered.\n");
        return;
    }

    printf("\n====================================================================\n");
    printf("                    EMERGENCY LIST\n");
    printf("====================================================================\n");

    printf("%-8s %-10s %-10s %-12s %-18s %-12s\n",
           "ID",
           "Severity",
           "Location",
           "Wait(min)",
           "Patient Token",
           "Status");

    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-8d %-10d %-10d %-12d %-18s %-12s\n",
               emergencies[i].id,
               emergencies[i].severity,
               emergencies[i].location,
               emergencies[i].waitingTime,
               emergencies[i].patientToken,
               emergencies[i].status);
    }

    printf("====================================================================\n");
}

int findEmergency(Emergency emergencies[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (emergencies[i].id == id)
        {
            return i;
        }
    }

    return -1;
}