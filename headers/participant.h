#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <stdbool.h>
typedef struct Participant
{
    int id;
    char name[50];
} Participant;

bool WriteData(char *fileName, Participant *p, int total);
Participant *ReadData(char *fileName, int *total);
#endif