#include <stdio.h>
#include <stdbool.h>
#include "../headers/participant.h"

int main()
{
    int choice;
    do
    {
        printf("1. Register Participant\n");
        printf("2. View All Participants\n");
        printf("3. Update Participant\n");
        printf("4. View Participant\n");
        printf("0. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            RegisterParticipant();
            break;
        case 2:
            PrintParticipants();
        case 3:
            UpdateParticipant();
        case 4:
            PrintParticipant();
            break;
        }
    } while (choice != 0);

    return 0;
}
