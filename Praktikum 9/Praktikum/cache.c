#include <stdio.h>
# include "listlinier.h"

int main () {
    int a;
    scanf ("%d", &a);
    List L;
    CreateEmpty(&L);
    for (int i = 0; i<a; i++) {
        InsVLast(&L, i+1);
    }
    int proses;
    scanf("%d", &proses);
    for (int i = 0; i < proses; i++) {
        int angka;
        scanf ("%d", &angka);
        address P = Search(L, angka);
        if(P != Nil) {
            DelP(&L, angka);
            InsVFirst(&L, angka);
            printf("hit ");
        } else {
            printf("miss ");
            DelLast(&L, &P);
            InsVFirst(&L, angka);
        }
        PrintInfo(L);
        printf("\n");

    }

}