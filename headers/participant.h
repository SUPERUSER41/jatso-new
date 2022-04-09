#ifndef PARTICIPANT_H
#define PARTICIPANT_H
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
Participant *InitParticipant();
#endif