#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <stdbool.h>
typedef struct Participant
{
    int id;
    char name[50];
    char gender;
    char school[50];
    char competition[50];
    int swim;
    int cycle;
    int run;
} Participant;
void RegisterParticipant();
void PrintParticipants();
void UpdateParticipant();
bool WriteData(char *fileName, Participant *p, int total);
Participant *ReadData(char *fileName, int *total);
#endif