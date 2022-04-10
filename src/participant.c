
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../headers/participant.h"

void RegisterParticipant()
{
    Participant *participants;
    int numOfParticipants = 0;

    printf("Enter number of participants to register:\n");
    scanf("%d", &numOfParticipants);

    participants = malloc(sizeof(Participant) * numOfParticipants);

    for (int i = 0; i < numOfParticipants; i++)
    {
        participants[i].id = i + 1;
        fflush(stdin);
        printf("Enter date of birth:\n");
        scanf("");

        fflush(stdin);
        printf("Enter name:\n");
        scanf("%[^\n]s", participants[i].name);

        fflush(stdin);
        printf("Enter gender:\n");
        scanf(" %c", &participants[i].gender);

        fflush(stdin);
        printf("Enter school:\n");
        scanf("%[^\n]s", participants[i].school);
    }
}

void PrintParticipants() {}

void UpdateParticipant() {}

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