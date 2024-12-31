# include <stdio.h>
# include "awasketahuan.h"
Stack awasKetahuan(Stack stack) {
    Stack temp;
    Stack end;
    int ang;

    CreateEmpty(&temp);
    CreateEmpty(&end);

    while(!IsEmpty(stack)) { 
        Pop(&stack, &ang);
        if (ang%2 == 0) { 
            ang /=2;
            Push(&temp, ang);
        }
        else {
            Push(&temp, ang);
        }
    }

    while(!IsEmpty(temp)) { 
        Pop(&temp, &ang);
        Push(&end, ang);

    }
    return end;
}