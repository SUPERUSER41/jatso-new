#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <stdbool.h>
#include "date.h"
typedef struct Participant
{
    int id;
    char name[50];
    char gender;
    char dob[10];
    char school[50];
    char competition[50];
    int swim;
    int cycle;
    int run;
    int score;
} Participant;
void RegisterParticipant();
void PrintParticipants();
void PrintParticipant(Participant *p);
void RegisterEventTimes();
Participant *GetParticipant(int id);
Participant *SearchParticipants();
void SetCompetition(int age, Participant *p);
int CalculateAge(int birthYear);
bool IsEligible(int age);
bool WriteData(char *fileName, Participant *p, int total);
Participant *ReadData(char *fileName, int *total);
#endif