# include <stdio.h>
# include "array.h"

int main () {
    int inp;
    int len;
    scanf("%d", &inp);
    scanf("%d", &len);
    int angka1 = 0;
    int angka2 = 1;
    long long ganjil = 0;
    long long genap = 0;

    TabInt angka;
    MakeEmpty(&angka);
    SetEl(&angka, 0, angka1);
    SetEl(&angka, 1, angka2);

    for (int i = 2; i <= len; i++){
        SetEl(&angka, i, GetElmt(angka, i-1) + GetElmt(angka, i-2));
        if (GetElmt(angka, i) %2 == 0){
            genap += GetElmt(angka, i);
        } else {
            ganjil += GetElmt(angka, i);
        }
    }

    if (inp == 0){
        printf("%d\n", genap);
    } else if (inp == 1 && len > 0){
        printf("%lld\n", ganjil + 1);
    } else {
        printf("%lld\n", ganjil);
    }


    if (len == 0){
        printf("Tabel kosong\n");
        return 0;
    }
    printf("[");
    for (int i = 0; i <=len; i++){
        printf("%d", GetElmt(angka, i));
        if (i != len){
            printf(",");
        }
    }
    printf("]\n");
}