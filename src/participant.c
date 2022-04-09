#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../headers/participant.h"

const char *FILE_NAME = "./data/data.csv";
const char *FILE_FORMAT = "%d,%s,%c,%s,%s,%s,%d,%d,%d,%d\n";
const char *KIDS_OF_STEEL = "Kids of Steel";
const char *IRON_KIDS = "Iron Kids";
const char *CAST_IRON_KIDS = "Cast Iron Kids";

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
    p->dob = malloc(sizeof(Date));
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
    printf("Enter date of birth (mm/dd/yyyy):\n");
    scanf("%d/%d/%d", &p->dob->month, &p->dob->day, &p->dob->year);

    if (!IsValidDate(p->dob))
    {
        printf("Invalid date, please try again.\n");
    }
    else
    {
        int age = CalculateAge(p->dob->year);
        if (!IsValidAge(age))
        {
            printf("Participant is too old.\n");
        }
        else
        {
            fflush(stdin);
            printf("Enter name:\n");
            scanf("%[^\n]s", p->name);

            fflush(stdin);
            printf("Enter gender (M/F):\n");
            scanf(" %c", &p->gender);

            fflush(stdin);
            printf("Enter school/club:\n");
            scanf("%[^\n]s", p->school);

            SaveParticipant(p);
            PrintParticipant(p);
        }
    }
}

void SaveParticipant(Participant *p)
{
    FILE *fp = fopen(FILE_NAME, "a+");

    if (fp == NULL)
    {
        perror("Error opening file");
    }
    char dob[10];
    sprintf(dob, "%d/%d/%d", p->dob->month, p->dob->day, p->dob->year);

    int isSuccessful = fprintf(fp, FILE_FORMAT, p->id, p->name, p->gender, dob, p->school, p->competition, p->swim, p->cycle, p->run, p->score);

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

int CalculateAge(int birthYear)
{
    int age = 0;
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    age = (currentTime->tm_year + MIN_YR) - birthYear;
    return age;
}

bool IsValidAge(int age)
{
    bool isValid = false;
    if ((age >= 6 && age <= 8) || (age >= 9 && age <= 11) || (age >= 12 && age <= 15))
    {
        isValid = true;
    }
    return isValid;
}

void AssignCompetition(int age, Participant *p)
{
    if (age >= 6 && age <= 8)
    {
        strcpy(p->competition, KIDS_OF_STEEL);
    }
    else if (age >= 9 && age <= 11)
    {
        strcpy(p->competition, IRON_KIDS);
    }
    else if (age >= 12 && age <= 15)
    {
        strcpy(p->competition, CAST_IRON_KIDS);
    }
}

void PrintParticipant(Participant *p)
{
    char dob[10];
    sprintf(dob, "%d/%d/%d", p->dob->month, p->dob->day, p->dob->year);

    printf("Id:\t\t%d\nName:\t\t%s\nGender:\t\t%c\nDob:\t\t%s\n", p->id, p->name, p->gender, dob);
    printf("================================\n");
    printf("Competition:\t\t%s\nSwim Time:\t\t%d\nCycle Time:\t\t%d\nRun Time:\t\t%d\nScore:\t\t%d\n",
           p->competition, p->swim, p->cycle, p->run, p->score);
}

void DestroyParticipant(Participant *p)
{
    free(p->dob);
    free(p);
}