#include <stdio.h>
#include "hashmap.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M) {
    M->Count = Nil;
    for (int i = 0; i < MaxEl; i++) {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
    }
}

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K) {
    return K % MaxEl;
}

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k) {
    int i = Hash(k);
    int start = i; 
    while (M.Elements[i].Key != Undefined) {
        if (M.Elements[i].Key == k) {
            return M.Elements[i].Value;
        }
        i = (i + 1) % MaxEl; 
        if (i == start) {
            break; 
        }
    }
    return Undefined; 
}

void Insert(HashMap *M, keytype k, valuetype v) {
    if (Value(*M, k) == Undefined && M->Count < MaxEl) { 
        int i = Hash(k);
        while (M->Elements[i].Key != Undefined) { 
            i = (i + 1) % MaxEl; 
        }
        M->Elements[i].Key = k;
        M->Elements[i].Value = v;
        M->Count++;
    }
}
