#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../headers/participant.h"

char *FILE_NAME = "./data/data.bin";

int main()
{
    Participant *p = malloc(sizeof(Participant) * 3);

    p[0].id = 1;
    strcpy(p[0].name, "John");

    p[1].id = 2;
    strcpy(p[1].name, "Dan");

    p[2].id = 3;
    strcpy(p[2].name, "Jane");

    if (WriteData(FILE_NAME, p, 3))
        printf("Write data OK.\n");
    else
    {
        printf("Error writing to file.\n");
        return 1;
    }

    int total = 0;
    Participant *fileData = ReadData(FILE_NAME, &total);

    if (fileData == NULL)
    {
        printf("Error reading from file.\n");
        return 1;
    }

    printf("\nData read OK.\n\n");

    for (int i = 0; i < total; i++)
    {
        printf("Participant %d\n", i + 1);
        printf("Id: %d\n", fileData[i].id);
        printf("Name: %s\n", fileData[i].name);
        printf("\n");
    }
    free(fileData);
    free(p);
    return 0;
}
