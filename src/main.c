#include <stdio.h>
#include "../headers/participant.h"

int main()
{
    Participant *p = InitParticipant();
    p->PrintParticipant(p);
    DestroyParticipant(p);
    return 0;
}