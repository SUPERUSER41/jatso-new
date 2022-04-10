#include <stdio.h>
#include <stdbool.h>
#include "../headers/participant.h"

int main()
{
    int choice;
    do
    {
        fflush(stdin);
        printf("1. Register Participant\n");
        printf("2. View All Participants\n");
        printf("3. Search Participants\n");
        printf("4. Enter Participant Times\n");
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
            break;
        case 3:
            SearchParticipants();
            break;
        case 4:
            RegisterEventTimes();
            break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}
