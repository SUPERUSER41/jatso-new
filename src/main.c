#include <stdio.h>
#include "../headers/participant.h"

int main()
{
    int ch;
    Participant *p = InitParticipant();
    do
    {
        clrscr();
        printf("-------------------------\n");
        printf("\tMain Menu\n");
        printf("-------------------------\n");
        printf("1. Register Participant\n");
        printf("2. Search Participant\n");
        printf("3. Enter Participant Time\n");
        printf("4. View Best Triathlete Per Competition\n");
        printf("5. View Winner For Each Competition\n");
        printf("0. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            RegisterParticipant(p);
            break;
        case 2:
            SearchParticipant();
            break;
        case 3:
            UpdateTime();
            break;
        case 4:
            break;
        case 5:
            break;
        }
    } while (ch != 0);
    DestroyParticipant(p);
    return 0;
}