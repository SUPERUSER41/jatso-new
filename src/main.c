#include <stdio.h>
#include "../headers/participant.h"

int main()
{
    Participant *p = InitParticipant();
    RegisterParticipant(p);
    SearchParticipant();
    DestroyParticipant(p);
    return 0;
}