
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "../headers/participant.h"

const char *KIDS_OF_STEEL = "Kids of Steel";
const char *IRON_KIDS = "Iron Kids";
const char *CAST_IRON_KIDS = "Cast Iron Kids";

void RegisterParticipant()
{
    Participant *participants;
    int numOfParticipants = 0, age = 0;

    printf("Enter number of participants to register:\n");
    scanf("%d", &numOfParticipants);

    participants = malloc(sizeof(Participant) * numOfParticipants);
    participants->dob = malloc(sizeof(Date) * numOfParticipants);

    for (int i = 0; i < numOfParticipants; i++)
    {
        fflush(stdin);
        printf("Enter date of birth (mm/dd/yyy):\n");
        scanf("%d/%d/%d", &participants[i].dob->month, &participants[i].dob->day, &participants[i].dob->year);

        if (IsValidDate(participants[i].dob) != 1)
        {
            printf("Invalid date.\n");
            break;
        }

        age = CalculateAge(participants[i].dob->year);

        if (!IsEligible(age))
        {
            printf("Participant is not eligible to register.\n");
            break;
        }

        SetCompetition(age, &participants[i]);

        fflush(stdin);
        printf("Enter name:\n");
        scanf("%[^\n]s", participants[i].name);

        fflush(stdin);
        printf("Enter gender:\n");
        scanf(" %c", &participants[i].gender);

        fflush(stdin);
        printf("Enter school:\n");
        scanf("%[^\n]s", participants[i].school);

        participants[i].id = i + 1;
        participants[i].swim = 0;
        participants[i].cycle = 0;
        participants[i].run = 0;
        participants[i].score = 0;
    }
    free(participants->dob);
    free(participants);
}

void PrintParticipants() {}

void UpdateParticipant() {}

void SetCompetition(int age, Participant *p)
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

int CalculateAge(int birthYear)
{
    int age = 0;
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    age = (currentTime->tm_year + MIN_YR) - birthYear;
    return age;
}

bool IsEligible(int age)
{
    if (age == 0)
        return false;

    if ((age >= 6 && age <= 8) || (age >= 9 && age <= 11) || (age >= 12 && age <= 15))
        return true;

    return false;
}

bool WriteData(char *fileName, Participant *data, int total)
{
    FILE *file = fopen(fileName, "wb");

    if (file == NULL)
        return false;

    if (fwrite(&total, sizeof(int), 1, file) != 1)
        return false;

    if (fwrite(data, sizeof(Participant), total, file) != total)
        return false;

    if (fclose(file) == EOF)
        return false;

    return true;
}

Participant *ReadData(char *fileName, int *total)
{
    FILE *file = fopen(fileName, "rb");

    if (file == NULL)
        return NULL;

    if (fread(total, sizeof(int), 1, file) != 1)
        return NULL;

    Participant *data = malloc(sizeof(Participant) * *total);

    if (fread(data, sizeof(Participant), *total, file) != *total)
    {
        free(data);
        return NULL;
    }

    if (fclose(file) == EOF)
    {
        free(data);
        return NULL;
    }
    return data;
}