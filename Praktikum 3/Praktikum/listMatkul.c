#include "listMatkul.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ARRAY ********** */
void MakeEmpty(ListMatkul* L) {
    (*L).Neff = 0;
}

/* ********** SELEKTOR ********** */
int NbElmt(ListMatkul L) {
    return L.Neff;
}

int MaxNbEl(ListMatkul L) {
    return MAX_CAPACITY;
}

IdxType GetFirstIdx(ListMatkul L) {
    return 0;
}

IdxType GetLastIdx(ListMatkul L) {
    return L.Neff - 1;
}

ElType GetElmt(ListMatkul L, IdxType i) {
    return L.contents[i];
}

void SetTab(ListMatkul Lin, ListMatkul* Lout) {
    (*Lout).Neff = Lin.Neff;
    for (int i = 0; i < Lin.Neff; i++) {
        (*Lout).contents[i] = Lin.contents[i];
    }
}

void SetEl(ListMatkul* L, IdxType i, ElType v) {
    (*L).contents[i] = v;
    if ((*L).Neff < i + 1) {
        (*L).Neff = i + 1;
    }
}

void SetNeff(ListMatkul* L, IdxType N) {
    (*L).Neff = N;
}

boolean IsIdxValid(ListMatkul L, IdxType i) {
    return i >= 0 && i < MAX_CAPACITY;
}

boolean IsIdxEff(ListMatkul L, IdxType i) {
    return i >= 0 && i < L.Neff;
}

boolean IsEmpty(ListMatkul L) {
    return L.Neff == 0;
}

boolean IsFull(ListMatkul L) {
    return L.Neff == MAX_CAPACITY;
}

void PrintIsi(ListMatkul L) {
    if (IsEmpty(L)) {
        printf("List kosong\n");
    } else {
        for (int i = 0; i < L.Neff; i++) {
            printf("%s(%d) - %d: %c\n", L.contents[i].kode, L.contents[i].sks, L.contents[i].semester, L.contents[i].nilai);
        }
    }
}

ElType MakeMatkul(char* kode, int sks, int semester, char nilai) {
    ElType MK;
    MK.kode = kode;
    MK.sks = sks;
    MK.semester = semester;
    MK.nilai = nilai;
    return MK;
}

int SumNilai(ListMatkul L, int semester) {
    int sum = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (L.contents[i].semester == semester) {
            int nilai;
            switch (L.contents[i].nilai) {
                case 'A': nilai = 4; break;
                case 'B': nilai = 3; break;
                case 'C': nilai = 2; break;
                case 'D': nilai = 1; break;
                case 'E': nilai = 0; break;
                default: nilai = 0; break;
            }
            sum += nilai * L.contents[i].sks;
        }
    }
    return sum;
}

int CountMatkul(ListMatkul L, int semester) {
    int count = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (L.contents[i].semester == semester) {
            count++;
        }
    }
    return count;
}

int CountSKS(ListMatkul L, int semester) {
    int count = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (L.contents[i].semester == semester) {
            count += L.contents[i].sks;
        }
    }
    return count;
}

int CountTotalSKS(ListMatkul L) {
    int count = 0;
    for (int i = 0; i < L.Neff; i++) {
        count += L.contents[i].sks;
    }
    return count;
}

int MaxSemester(ListMatkul L) {
    int maxSemester = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (L.contents[i].semester > maxSemester) {
            maxSemester = L.contents[i].semester;
        }
    }
    return maxSemester;
}

float HitungIP(ListMatkul L, int semester) {
    int totalSKS = CountSKS(L, semester);
    if (totalSKS == 0) return 0.0;
    return (float)SumNilai(L, semester) / totalSKS;
}

float HitungIPK(ListMatkul L) {
    int totalSKS = CountTotalSKS(L);
    if (totalSKS == 0) return 0.0;
    int totalNilai = 0;
    for (int i = 1; i <= MaxSemester(L); i++) {
        totalNilai += SumNilai(L, i);
    }
    return (float)totalNilai / totalSKS;
}

int CountMatkulLuar(ListMatkul L, char* kodeJur) {
    int count = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (!(L.contents[i].kode[0] == kodeJur[0] && L.contents[i].kode[1] == kodeJur[1])) {
            count++;
        }
    }
    return count;
}

void DisplaySIX(ListMatkul L) {
    int semester = MaxSemester(L);
    printf("IPK: %.2f\n", HitungIPK(L));
    printf("IP: %.2f\n", HitungIP(L, semester));
    printf("SKS: Sudah Diambil %d SKS\n", CountTotalSKS(L));
    printf("Daftar Kuliah Semester %d:\n", semester);
    for (int i = 0; i < L.Neff; i++) {
        if (L.contents[i].semester == semester) {
            printf("%s(%d) - %d: %c\n", L.contents[i].kode, L.contents[i].sks, L.contents[i].semester, L.contents[i].nilai);
        }
    }
}
