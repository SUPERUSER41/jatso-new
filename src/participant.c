#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/participant.h"

const char *FILE_NAME = "./data/data.csv";
const char *FILE_FORMAT = "%d,%s,%c,%s,%s,%s,%d,%d,%d,%d\n";

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

    return p;
}

void RegisterParticipant(Participant *p)
{
    fflush(stdin);
    printf("Enter name:\n");
    scanf("%[^\n]s", p->name);
    fflush(stdin);
    printf("Enter gender (M/F):\n");
    scanf(" %c", &p->gender);
    fflush(stdin);
    printf("Enter date of birth (mm/dd/yyyy):\n");
    scanf("%[^\n]s", p->dob);
    fflush(stdin);
    printf("Enter school/club:\n");
    scanf("%[^\n]s", p->school);

    SaveParticipant(p);
    PrintParticipant(p);
}

void SaveParticipant(Participant *p)
{
    FILE *fp = fopen(FILE_NAME, "a+");

    if (fp == NULL)
    {
        perror("Error opening file");
    }

    int isSuccessful = fprintf(fp, FILE_FORMAT, p->id, p->name, p->gender, p->dob, p->school, p->competition, p->swim, p->cycle, p->run, p->score);

    if (isSuccessful == -1)
    {
        perror("Error writing to file");
    }
    else
    {
        printf("Successfully saved participant to file\n");
    }

    fclose(fp);
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
    free(p);
}