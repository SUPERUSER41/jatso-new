#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../headers/participant.h"

const char *FILE_NAME = "./data/data.csv";
const char *FILE_FORMAT_IN = "%d,%[^,],%c,%[^,],%[^,],%[^,],%d,%d,%d,%d\n";
const char *FILE_FORMAT_OUT = "%d,%s,%c,%s,%s,%s,%d,%d,%d,%d\n";
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
    int age;
    clrscr();
    fflush(stdin);
    printf("Enter date of birth (mm/dd/yyyy):\n");
    scanf("%d/%d/%d", &p->dob->month, &p->dob->day, &p->dob->year);

    if (!IsValidDate(p->dob))
    {
        printf("Invalid date, please try again.\n");
        pause();
    }
    else
    {
        age = CalculateAge(p->dob->year);
        if (!IsValidAge(age))
        {
            printf("Participant is too old.\n");
            pause();
        }
        else
        {
            AssignCompetition(age, p);
            fflush(stdin);
            printf("Enter name:\n");
            scanf("%[^\n]s", p->name);

            fflush(stdin);
            printf("Enter gender (M/F):\n");
            scanf(" %c", &p->gender);

            fflush(stdin);
            printf("Enter school/club:\n");
            scanf("%[^\n]s", p->school);
            pause();

            SaveParticipant(p);
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

    p->id = GenerateId();

    int isSuccessful = fprintf(fp, FILE_FORMAT_OUT, p->id, p->name, p->gender, dob, p->school, p->competition, p->swim, p->cycle, p->run, p->score);

    if (isSuccessful == -1)
    {
        perror("Error writing to file");
        pause();
    }
    else
    {
        clrscr();
        printf("Successfully saved participant to file\n");
        pause();
        PrintParticipant(p, dob);
    }

    fclose(fp);
}

int GenerateId()
{
    FILE *fp = fopen(FILE_NAME, "r");
    int id = 0;
    Participant p;
    char dob[10];

    if (fp == NULL)
    {
        perror("Error reading file");
        pause();
        exit(1);
    }

    while (fscanf(fp, FILE_FORMAT_IN, &p.id, p.name, &p.gender, dob, p.school, p.competition, &p.swim, &p.cycle, &p.run, &p.score) != EOF)
    {
        id = p.id;
    }

    fclose(fp);
    return id + 1;
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

void SearchParticipant()
{
    clrscr();
    FILE *fp = fopen(FILE_NAME, "r");
    Participant p;
    int id, ch;
    char dob[10];
    bool found = false;

    if (fp == NULL)
    {
        perror("Error reading file");
        pause();
        exit(1);
    }

    printf("Enter id to search:\n");
    scanf("%d", &id);

    while (fscanf(fp, FILE_FORMAT_IN, &p.id, p.name, &p.gender, dob, p.school, p.competition, &p.swim, &p.cycle, &p.run, &p.score) != EOF)
    {
        if (p.id == id)
        {
            found = true;
            do
            {
                clrscr();
                printf("-------------------------\n");
                printf("View/Update Participant\n");
                printf("-------------------------\n");
                printf("1. View Participant\n");
                printf("2. Update Participant Time\n");
                printf("0. Back\n");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                    PrintParticipant(&p, dob);
                    break;
                case 2:
                    UpdateTime(&p);
                    break;
                }
            } while (ch != 0);
        }
    }

    if (!found)
    {
        printf("Participant not found!\n");
        pause();
    }
}

void UpdateTime(Participant *p)
{
    int ch;
    if (p != NULL)
    {
        do
        {
            clrscr();
            printf("------%s------\n", p->competition);
            printf("-------------------------\n");
            printf("Enter Participant Time\n");
            printf("-------------------------\n");
            printf("1. Update Swim Time\n");
            printf("2. Update Cycle Time\n");
            printf("3. Update Run Time\n");
            printf("0. Back\n");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                printf("Current swim time:\n");
                printf("Enter new swim time:\n");
                scanf("%d", &p->swim);
                break;
            case 2:
                printf("Current swim time:\n");
                printf("Enter new cycle time:\n");
                scanf("%d", &p->swim);
                break;
            case 3:
                printf("Current swim time:\n");
                printf("Enter new run time:\n");
                scanf("%d", &p->swim);
                break;
            }
        } while (ch != 0);
    }
    pause();
}

void PrintParticipant(Participant *p, char *dob)
{
    clrscr();

    printf("Id:\t\t%d\nName:\t\t%s\nGender:\t\t%c\nDob:\t\t%s\n", p->id, p->name, p->gender, dob);
    printf("================================\n");
    printf("Competition:\t\t%s\nSwim Time:\t\t%d\nCycle Time:\t\t%d\nRun Time:\t\t%d\nScore:\t\t%d\n",
           p->competition, p->swim, p->cycle, p->run, p->score);
    pause();
}

void DestroyParticipant(Participant *p)
{
    free(p->dob);
    free(p);
}

void pause()
{
    system("read -n1 -r -p \"Press any key to continue...\" key");
}

void clrscr()
{
    system("@cls||clear");
}