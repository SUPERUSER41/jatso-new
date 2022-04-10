
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "../headers/participant.h"

char *FILE_NAME = "./data/data.bin";
char *FILE_NAME_TMP = "./data/tmp.bin";
const char *KIDS_OF_STEEL = "Kids of Steel";
const char *IRON_KIDS = "Iron Kids";
const char *CAST_IRON_KIDS = "Cast Iron Kids";

void RegisterParticipant()
{
    Participant *participants;
    Date *dob;
    int numOfParticipants = 0, age = 0;

    printf("Enter number of participants to register:\n");
    scanf("%d", &numOfParticipants);

    participants = malloc(sizeof(Participant) * numOfParticipants);
    dob = malloc(sizeof(Participant) * numOfParticipants);

    for (int i = 0; i < numOfParticipants; i++)
    {
        fflush(stdin);
        printf("Enter date of birth (mm/dd/yyy):\n");
        scanf("%d/%d/%d", &dob[i].month, &dob[i].day, &dob[i].year);

        if (IsValidDate(dob) != 1)
        {
            printf("Invalid date.\n");
            break;
        }

        sprintf(participants[i].dob, "%d/%d/%d", dob[i].month, dob[i].day, dob[i].year);

        age = CalculateAge(dob[i].year);

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
        printf("Enter gender (M/F):\n");
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

    if (WriteData(FILE_NAME, participants, numOfParticipants, "wb"))
        printf("Successfully saved participants to %s.\n", FILE_NAME);
    else
    {
        printf("Error writing to file\n");
        exit(1);
    }

    free(dob);
    free(participants);
}

void PrintParticipants()
{
    int total = 0;
    Participant *participants = ReadData(FILE_NAME, &total);

    if (participants == NULL)
    {
        printf("Error reading from file.\n");
        exit(1);
    }

    for (int i = 0; i < total; i++)
    {
        printf("Id:\t\t%d\nName:\t\t%s\nGender:\t\t%c\nDob:\t\t%s\nSchool:\t\t%s\n",
               participants[i].id, participants[i].name, participants[i].gender, participants[i].dob, participants[i].school);
        printf("================================\n");
        printf("Competition:\t\t%s\nSwim Time:\t\t%d\nCycle Time:\t\t%d\nRun Time:\t\t%d\nScore:\t\t%d\n",
               participants[i].competition, participants[i].swim, participants[i].cycle, participants[i].run, participants[i].score);
        printf("\n");
    }

    free(participants);
}

void PrintParticipant(Participant *p)
{

    printf("Id:\t\t%d\nName:\t\t%s\nGender:\t\t%c\nDob:\t\t%s\nSchool:\t\t%s\n",
           p->id, p->name, p->gender, p->dob, p->school);
    printf("================================\n");
    printf("Competition:\t\t%s\nSwim Time:\t\t%d\nCycle Time:\t\t%d\nRun Time:\t\t%d\nScore:\t\t%d\n",
           p->competition, p->swim, p->cycle, p->run, p->score);
}

void PrintBestTriathlete()
{
    int total = 0, max;
    Participant *participants = ReadData(FILE_NAME, &total);

    if (participants == NULL)
    {
        printf("Error reading from file.\n");
        exit(1);
    }

    max = participants[0].score;

    for (int i = 0; i < total; i++)
    {
        if (participants[i].score > max)
            max = participants[i].score;
    }

    printf("Max: %d\n", max);

    free(participants);
}

void RegisterEventTimes()
{

    int choice, total = 0;

    Participant *participant = SearchParticipants(), *participants, *updatedParticipants;

    if (participant == NULL)
        return;

    participants = ReadData(FILE_NAME, &total);

    if (participants == NULL)
    {
        printf("Error reading from file.\n");
        exit(1);
    }

    updatedParticipants = malloc(sizeof(Participant) * total);

    for (int i = 0; i < total; i++)
    {
        if (participants[i].id == participant->id)
        {
            do
            {
                printf("1. Enter swim time\n");
                printf("2. Enter cycle time\n");
                printf("3. Enter run time\n");
                printf("0. Back\n");
                printf("Enter your choice:\n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Enter new swim time:\n");
                    scanf("%d", &participants[i].swim);
                    break;
                case 2:
                    printf("Enter new cycle time:\n");
                    scanf("%d", &participants[i].cycle);
                    break;
                case 3:
                    printf("Enter new run time:\n");
                    scanf("%d", &participants[i].run);
                    break;
                }
            } while (choice != 0);
            updatedParticipants[i] = participants[i];
        }
        updatedParticipants[i] = participants[i];
    }

    if (WriteData(FILE_NAME, updatedParticipants, total, "wb"))
        printf("Successfully updated participant to %s.\n", FILE_NAME);
    else
    {
        printf("Error writing to file\n");
        exit(1);
    }

    free(updatedParticipants);
}

Participant *SearchParticipants()
{
    int id;
    Participant *participant;

    printf("Enter id to search:\n");
    scanf("%d", &id);

    participant = GetParticipant(id);

    if (participant == NULL)
    {
        printf("Participant with id %d not found.\n", id);
        return NULL;
    }

    PrintParticipant(participant);

    return participant;
}

Participant *GetParticipant(int id)
{
    int total = 0;
    Participant *participants = ReadData(FILE_NAME, &total), *participant = NULL;

    if (participants == NULL)
    {
        printf("Error reading from file.\n");
        exit(1);
    }

    for (int i = 0; i < total; i++)
    {
        if (participants[i].id == id)
        {
            participant = &participants[i];
            return participant;
        }
    }

    free(participants);
    return participant;
}

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

bool WriteData(char *fileName, Participant *data, int total, char *mode)
{
    FILE *file = fopen(fileName, mode);

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
