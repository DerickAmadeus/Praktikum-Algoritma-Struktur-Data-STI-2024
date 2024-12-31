#include "list.h"
#include <stdio.h>


List MakeList() {
    List L;
    for (int i = 0; i < MaxEl; i++) {
        L.A[i] = Mark; 
    }
    return L;
}


boolean IsEmpty(List L) {
    return L.A[0] == Mark;
}


ElType Get(List L, IdxType i) {
    return L.A[i];
}


void Set(List *L, IdxType i, ElType v) {
    L->A[i] = v;
}


int Length(List L) {
    int count = 0;
    while (count < MaxEl && L.A[count] != Mark) {
        count++;
    }
    return count;
}

IdxType FirstIdx(List L) {
    return IsEmpty(L) ? InvalidIdx : 0;
}

IdxType LastIdx(List L) {
    int len = Length(L);
    return len > 0 ? len - 1 : InvalidIdx;
}


boolean IsIdxValid(List L, IdxType i) {
    return i >= 0 && i < MaxEl;
}

boolean IsIdxEff(List L, IdxType i) {
    return i >= FirstIdx(L) && i <= LastIdx(L);
}


boolean Search(List L, ElType X) {
    for (int i = 0; i < Length(L); i++) {
        if (L.A[i] == X) {
            return true;
        }
    }
    return false;
}

void InsertFirst(List *L, ElType X) {
    int len = Length(*L);
    if (len < MaxEl) {
        for (int i = len; i > 0; i--) {
            L->A[i] = L->A[i - 1];
        }
        L->A[0] = X;
    }
}

void InsertAt(List *L, ElType X, IdxType i) {
    int len = Length(*L);
    if (len < MaxEl && IsIdxEff(*L, i)) {
        for (int j = len; j > i; j--) {
            L->A[j] = L->A[j - 1];
        }
        L->A[i] = X;
    }
}

void InsertLast(List *L, ElType X) {
    int len = Length(*L);
    if (len < MaxEl) {
        L->A[len] = X;
    }
}

void DeleteFirst(List *L) {
    int len = Length(*L);
    if (len > 0) {
        for (int i = 0; i < len - 1; i++) {
            L->A[i] = L->A[i + 1];
        }
        L->A[len - 1] = Mark;
    }
}

void DeleteAt(List *L, IdxType i) {
    int len = Length(*L);
    if (IsIdxEff(*L, i)) {
        for (int j = i; j < len - 1; j++) {
            L->A[j] = L->A[j + 1];
        }
        L->A[len - 1] = Mark;
    }
}

void DeleteLast(List *L) {
    int len = Length(*L);
    if (len > 0) {
        L->A[len - 1] = Mark;
    }
}

List Concat(List L1, List L2) {
    List L3 = MakeList();
    int len1 = Length(L1);
    int len2 = Length(L2);
    int total = len1 + len2;

    if (total <= MaxEl) {
        for (int i = 0; i < len1; i++) {
            L3.A[i] = L1.A[i];
        }
        for (int j = 0; j < len2; j++) {
            L3.A[len1 + j] = L2.A[j];
        }
    }
    return L3;
}
