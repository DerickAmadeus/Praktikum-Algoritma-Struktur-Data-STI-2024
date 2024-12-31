#include "stacklinked.h"
#include <stdio.h>

int main() {
    int N, Si, Di;
    Stack towers[3]; // List Of Towers

    for (int i = 0; i < 3; i++) {
        CreateStack(&towers[i]);
    }

    for (int i = 5; i >= 1; i--) {
        push(&towers[0], i);
    }

    scanf("%d", &N);

    // moves
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &Si, &Di);
        Si--;
        Di--;

        if (isEmpty(towers[Si])) {
            printf("Menara kosong\n");
        } else if (!isEmpty(towers[Di]) && TOP(towers[Di]) < TOP(towers[Si])) {
            printf("Piringan tidak dapat dipindah\n");
        } else {
            ElType disk;
            pop(&towers[Si], &disk);
            push(&towers[Di], disk);
        }
    }

    // Print 
    for (int i = 0; i < 3; i++) {
        printf("Menara %d: ", i + 1);
        DisplayStack(towers[i]);
        printf("\n");
    }

    return 0;
}
