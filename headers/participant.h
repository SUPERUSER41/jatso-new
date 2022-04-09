#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <stdbool.h>
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
int GenerateId();
int CalculateAge(int birthYear);
bool IsValidAge(int age);
void AssignCompetition(int age, Participant *p);
void SearchParticipant();
void UpdateTime();
void UpdateParticipant(Participant *p);
void UpdateFile();
void PrintParticipant(Participant *p, char *dob);
void DestroyParticipant(Participant *p);
void pause();
void clrscr();
#endif