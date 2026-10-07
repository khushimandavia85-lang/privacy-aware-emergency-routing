#ifndef EMERGENCY_H
#define EMERGENCY_H

#define MAX_EMERGENCIES 100
#define TOKEN_SIZE 30
#define STATUS_SIZE 20

typedef struct
{
    int id;
    int severity;
    int location;
    int waitingTime;

    char patientToken[TOKEN_SIZE];
    char status[STATUS_SIZE];

} Emergency;

void registerEmergency(Emergency emergencies[], int *count);

void displayEmergencies(Emergency emergencies[], int count);

int findEmergency(Emergency emergencies[], int count, int id);

#endif