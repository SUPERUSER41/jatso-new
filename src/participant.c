#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/participant.h"

Participant *InitParticipant()
{
    Participant *p = malloc(sizeof(Participant));

    if (!p)
    {
        perror("Error in RegisterParticipant");
    }

    p->id = 0;
    strcpy(p->name, "");
    p->gender = ' ';
    strcpy(p->dob, "");
    strcpy(p->school, "");
    strcpy(p->competition, "");
    p->swim = 0;
    p->cycle = 0;
    p->run = 0;
    p->score = 0;
    p->PrintParticipant = &PrintParticipant;

    return p;
}

void PrintParticipant(Participant *p)
{
    printf("Id:\t\t%d\nName:\t\t%s\nGender:\t\t%c\nDob:\t\t%s\n", p->id, p->name, p->gender, p->dob);
    printf("================================\n");
    printf("Competition:\t\t%s\nSwim Time:\t\t%d\nCycle Time:\t\t%d\nRun Time:\t\t%d\nScore:\t\t%d\n",
           p->competition, p->swim, p->cycle, p->run, p->score);
}

void DestroyParticipant(Participant *p)
{
    p->PrintParticipant = NULL;
    free(p);
}