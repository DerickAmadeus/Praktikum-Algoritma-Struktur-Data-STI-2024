
#include "listlinier.h"
#include <stdio.h>

void OddEvenList(List L, List *Odd, List *Even){
    address P = First(L);
    CreateEmpty(Odd);
    CreateEmpty(Even);


    while (P != Nil){
        address NewEl = Alokasi(Info(P));
        if (NewEl != Nil) {
            if (Info(P) %2 == 0){
                if (IsEmpty(*Even ) || Info(First(*Even)) >= Info(NewEl)){
                    InsertFirst(Even, NewEl);
                } else {
                    address Prec = First(*Even);
                    while (Next(Prec) != Nil && Info(Next(Prec)) < Info(NewEl)){
                        Prec = Next(Prec);
                    }
                    Next(NewEl) = Next(Prec);
                    Next(Prec) = NewEl;
                }
            } else {
                if (IsEmpty(*Odd) || Info(First(*Odd)) >= Info(NewEl)){
                    InsertFirst(Odd, NewEl);
                } else {
                    address Prec = First(*Odd);
                    while (Next(Prec) != Nil && Info(Next(Prec)) < Info(NewEl)){
                        Prec = Next(Prec);
                    }
                    Next(NewEl) = Next(Prec);
                    Next(Prec) = NewEl;
                }
            }
        } 
        P = Next(P);
    }
}
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/