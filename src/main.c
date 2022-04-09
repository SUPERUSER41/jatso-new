#include <stdio.h>
#include "../headers/participant.h"

int main()
{
    Participant *p = InitParticipant();
    RegisterParticipant(p);
    SearchParticipant();
    UpdateTime();
    DestroyParticipant(p);
    return 0;
}