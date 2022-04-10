
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../headers/participant.h"

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