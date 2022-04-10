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
        printf("3. Search Participants\n");
        printf("4. Update Participant\n");
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
            SearchParticipants();
        case 4:
            UpdateParticipant();
            break;
        }
    } while (choice != 0);

    return 0;
}
