# include <stdio.h>
# include <stdlib.h>
# include "listlinier.h"

int main () {
    List L;
    int total = 0;
    CreateEmpty(&L);
    while (true) {
        infotype angka = 0;
        scanf("%d", &angka);
        if (angka < 0 || angka > 100) {
            break;
        }
        InsVFirst(&L, angka);
        total +=1;
    }
    if (IsEmpty(L)) {
        printf("Daftar nilai kosong\n");
        return 0;
    }

    printf("%d\n", NbElmt(L));
    printf("%d\n", Max(L));
    printf("%d\n", Min(L));
    printf("%.2f\n", Average(L));
    InversList(&L);
    PrintInfo(L);
    printf("\n");
    InversList(&L);
    PrintInfo(L);
    printf("\n");
    return 0;
}