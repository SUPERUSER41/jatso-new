#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include "date.h"
typedef struct Participant
{
    int id;
    char name[50];
    char gender;
    Date *dob;
    char school[50];
    char competition[50];
    int swim;
    int cycle;
    int run;
    int score;
} Participant;
Participant *InitParticipant();
void RegisterParticipant(Participant *p);
void SaveParticipant(Participant *p);
void GenerateId(Participant *p);
void PrintParticipant(Participant *p);
void DestroyParticipant(Participant *p);
#endif