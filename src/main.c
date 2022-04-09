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
        printf("2. View Participant/Update Time\n");
        printf("3. View Best Triathlete Per Competition\n");
        printf("4. View Winner For Each Competition\n");
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
            PrintBestTriathlete();
            break;
        case 4:
            PrintCompetitionWinner();
            break;
        }
    } while (ch != 0);
    DestroyParticipant(p);
    return 0;
}