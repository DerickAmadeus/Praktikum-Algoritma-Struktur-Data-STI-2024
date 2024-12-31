#include <stdio.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty(TabInt *T) {
    T->Neff = 0;  /* Set Neff to 0 indicating the array is empty */
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T) {
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl(TabInt T) {
    return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T) {
    return IdxMin;  /* The first index is IdxMin (which is 1) */
}

IdxType GetLastIdx(TabInt T) {
    return T.Neff + IdxMin - 1;  /* Adjust for starting index */
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt(TabInt T, IdxType i) {
    return T.TI[i - IdxMin];  /* Adjust index for zero-based array */
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
void SetTab(TabInt Tin, TabInt *Tout) {
    Tout->Neff = Tin.Neff;
    for (IdxType i = IdxMin; i <= Tin.Neff + IdxMin - 1; i++) {
        Tout->TI[i - IdxMin] = Tin.TI[i - IdxMin];
    }
}

void SetEl(TabInt *T, IdxType i, ElType v) {
    if (IsIdxValid(*T, i)) {
        T->TI[i - IdxMin] = v;
        if (i - IdxMin + 1 > T->Neff) {
            T->Neff = i - IdxMin + 1;
        }
    } else {
        printf("Error: Invalid index %d\n", i);
    }
}

void SetNeff(TabInt *T, IdxType N) {
    if (N >= 0 && N <= MaxNbEl(*T)) {
        T->Neff = N;
    } else {
        printf("Error: Invalid Neff value %d\n", N);
    }
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i) {
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff(TabInt T, IdxType i) {
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
boolean IsEmpty(TabInt T) {
    return (T.Neff == 0);
}

boolean IsFull(TabInt T) {
    return (T.Neff == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi(TabInt T) {
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    } else {
        for (IdxType i = IdxMin; i <= GetLastIdx(T); i++) {
            printf("%d:%d\n", i - IdxMin, GetElmt(T, i));
        }
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
TabInt PlusTab(TabInt T1, TabInt T2) {
    TabInt T3;
    MakeEmpty(&T3);
    if (NbElmt(T1) == NbElmt(T2)) {
        SetNeff(&T3, NbElmt(T1));
        for (IdxType i = IdxMin; i <= GetLastIdx(T1); i++) {
            SetEl(&T3, i, GetElmt(T1, i) + GetElmt(T2, i));
        }
    } else {
        printf("Error: Arrays have different sizes\n");
    }
    return T3;
}

TabInt MinusTab(TabInt T1, TabInt T2) {
    TabInt T3;
    MakeEmpty(&T3);
    if (NbElmt(T1) == NbElmt(T2)) {
        SetNeff(&T3, NbElmt(T1));
        for (IdxType i = IdxMin; i <= GetLastIdx(T1); i++) {
            SetEl(&T3, i, GetElmt(T1, i) - GetElmt(T2, i));
        }
    } else {
        printf("Error: Arrays have different sizes\n");
    }
    return T3;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax(TabInt T) {
    if (IsEmpty(T)) {
        printf("Error: Array is empty\n");
        return 0;
    }
    ElType maxVal = GetElmt(T, IdxMin);
    for (IdxType i = IdxMin + 1; i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i) > maxVal) {
            maxVal = GetElmt(T, i);
        }
    }
    return maxVal;
}

ElType ValMin(TabInt T) {
    if (IsEmpty(T)) {
        printf("Error: Array is empty\n");
        return 0;
    }
    ElType minVal = GetElmt(T, IdxMin);
    for (IdxType i = IdxMin + 1; i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i) < minVal) {
            minVal = GetElmt(T, i);
        }
    }
    return minVal;
}

IdxType IdxMaxTab(TabInt T) {
    if (IsEmpty(T)) {
        printf("Error: Array is empty\n");
        return IdxUndef;
    }
    IdxType idxMax = IdxMin;
    ElType maxVal = GetElmt(T, IdxMin);
    for (IdxType i = IdxMin + 1; i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i) > maxVal) {
            maxVal = GetElmt(T, i);
            idxMax = i;
        }
    }
    return idxMax;
}

IdxType IdxMinTab(TabInt T) {
    if (IsEmpty(T)) {
        printf("Error: Array is empty\n");
        return IdxUndef;
    }
    IdxType idxMin = IdxMin;
    ElType minVal = GetElmt(T, IdxMin);
    for (IdxType i = IdxMin + 1; i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i) < minVal) {
            minVal = GetElmt(T, i);
            idxMin = i;
        }
    }
    return idxMin;
}
