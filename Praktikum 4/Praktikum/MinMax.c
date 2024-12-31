# include <stdio.h>
#include "list.h"

List MinMax(List L){
    if (IsEmpty(L) || Length(L) == 1){
        return L;
    }

    List hasil = MakeList();
    int min = Get(L, 0);
    int indexMin = 0;
    for (int i = 0; i < Length(L); i++){
        if (Get(L, i) < min){
            min = Get(L, i);
            indexMin = i;
        }
    }

    DeleteAt(&L, indexMin);
    InsertLast(&L, min);

    int max = Get(L, 0);
    int indexMax = 0;
    for (int i = 0; i < Length(L); i++){
        if (Get(L, i) > max){
            max = Get(L, i);
            indexMax = i;
        }
    }

    DeleteAt(&L, indexMax);
    InsertLast(&L, max);

    return L;






    

}

// int main () {
//     List L = MakeList();
//     InsertFirst(&L, 2);
//     InsertLast(&L, 1);
//     InsertLast(&L, 3);
//     List hasil = MinMax(L);
//     for (int i = 0; i < Length(hasil); i++){
//         printf("%d\n", Get(hasil, i));
//     }
//     return 0;
// }


