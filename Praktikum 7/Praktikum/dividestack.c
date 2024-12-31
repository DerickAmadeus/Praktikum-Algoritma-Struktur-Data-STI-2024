# include <stdio.h>
# include "dividestack.h"

void divideStack(Stack *s, Stack *oddS, Stack *evenS){
    Stack temp;
    infotype apalah;
    CreateEmpty (&temp);

    while(!IsEmpty(*s)) { 
        Pop(s, &apalah);
        Push(&temp, apalah);
    }


    while (!IsEmpty(temp)){
        Pop(&temp, &apalah);
        if (apalah %2 != 0) {
            Push(oddS, apalah);
        } else {
            Push(evenS, apalah);
        }


    }
}