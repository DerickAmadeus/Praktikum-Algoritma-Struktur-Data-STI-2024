/* Tuliskan header di sini berisi nama, dll */

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
    if (IsEmpty(L)) {
        return 0;
    }
    address P = First(L);
    int i = 0;
    while (i < r) {
        if (Next(P) == Nil) {
            P = First(L);
            i++;
        } else {
            P = Next(P);
            i++;
        }
    }
    return Info(P);
  /* Tuliskan implementasi di sini */
}

int main () {
    List L;
    int r ;
  /* Tuliskan implementasi di sini */
    CreateEmpty(&L);
    while (r != 0) {
        int ang;
        scanf("%d", &ang);
        if (ang != 0) {
            InsVLast(&L, ang);
        }
        else {
            break;
        }
    }
    scanf("%d", &r);
    if (IsEmpty(L)) {
        printf("List Kosong\n");
        return 0;
    }
    printf("%d\n", ElemenKeN(L, r));
    return 0;
}