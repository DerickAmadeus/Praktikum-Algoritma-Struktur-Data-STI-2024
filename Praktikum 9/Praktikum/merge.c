# include <stdio.h>
# include "merge.h"
# include "listlinier.h"

List mergeSortedList(List L1, List L2) {
    List L3;
    List Res;
    CreateEmpty(&L3);
    CreateEmpty(&Res);
    Konkat1(&L1, &L2, &L3);
    address P = First(L3);
    while (P != Nil){
        address NewEl = Alokasi(Info(P));
        if (NewEl != Nil) {
            
            if (IsEmpty(Res) || Info(First(Res)) >= Info(NewEl)){
                InsertFirst(&Res, NewEl);
                } else {
                    address Prec = First(Res);
                    while (Next(Prec) != Nil && Info(Next(Prec)) < Info(NewEl)){
                        Prec = Next(Prec);
                    }
                    Next(NewEl) = Next(Prec);
                    Next(Prec) = NewEl;
                }

        }
        P = Next(P);

    }
    return Res;
}