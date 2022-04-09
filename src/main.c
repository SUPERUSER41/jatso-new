#include <stdio.h>
#include "../headers/participant.h"

int main()
{
    Participant *p = InitParticipant();
    RegisterParticipant(p);
    PrintParticipant(p);
    DestroyParticipant(p);
    return 0;
}