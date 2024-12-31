#include <stdio.h>
#include "arrayGames.h"

void MakeEmpty(TabGames *T) {
    (*T).Neff = 0; 
}

int NbElmt(TabGames T) {
    return T.Neff;
}

int MaxNbEl(TabGames T) {
    return IdxMax - IdxMin + 1;
}

IdxType GetFirstIdx(TabGames T) {
    return 1;
}

IdxType GetLastIdx(TabGames T) {
    return T.Neff;
}

ElType GetElmt(TabGames T, IdxType i) {
    return T.TI[i];
}

void SetTab (TabGames Tin, TabGames *Tout) {
    (*Tout).Neff = Tin.Neff;
	for(int i = IdxMin; i <= Tin.Neff; i++){
		(*Tout).TI[i] = Tin.TI[i];
	}
}

void SetEl(TabGames *T, IdxType i, ElType v) {
    (*T).TI[i] = v;
	if ((*T).Neff < i){
		(*T).Neff = i;
	}
}

void SetNeff(TabGames *T, IdxType N) {
    (*T).Neff = N;
}

boolean IsIdxValid(TabGames T, IdxType i) {
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff(TabGames T, IdxType i) {
    return (i >= IdxMin && i <= T.Neff);
}

boolean IsEmpty(TabGames T) {
    return (T.Neff == 0);
}

boolean IsFull(TabGames T) {
    return (T.Neff == IdxMax);
}

void TulisIsi(TabGames T) {
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    } else {
        for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            printf("%s | %d | %d\n", T.TI[i].nama, T.TI[i].rating, T.TI[i].harga);
        }
    }
}

ElType MakeGame(char *Nama, int Rating, int Harga) {
    ElType G;
    G.nama = Nama;
    G.rating = Rating;
    G.harga = Harga;
    return G;
}

float RataRataHarga(TabGames T) {
    float avgharga = 0.0;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        avgharga += T.TI[i].harga;
    }
    return avgharga / T.Neff;
}

float RataRataRating(TabGames T) {
    float avgrating = 0.0;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        avgrating += T.TI[i].rating;
    }
    return avgrating / T.Neff;
}

int MaxRating(TabGames T) {
    int max = T.TI[GetFirstIdx(T)].rating;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (T.TI[i].rating > max) {
            max = T.TI[i].rating;
        }
    }
    return max;
}

int MinRating(TabGames T) {
    int min = T.TI[GetFirstIdx(T)].rating;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (T.TI[i].rating < min) {
            min = T.TI[i].rating;
        }
    }
    return min;
}

char *MaxHargaNama(TabGames T) {
    int max = T.TI[GetFirstIdx(T)].harga;
    char *name = T.TI[GetFirstIdx(T)].nama;
    int temp = T.TI[GetFirstIdx(T)].rating;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (T.TI[i].harga > max) {
            max = T.TI[i].harga;
            name = T.TI[i].nama;
            temp = T.TI[i].rating;
        } else if (T.TI[i].harga == max) {
            if (T.TI[i].rating > temp) {
                name = T.TI[i].nama;
            }
        }
    }
    return name;
}

char *MinHargaNama(TabGames T) {
    int min = T.TI[GetFirstIdx(T)].harga;
    char *name = T.TI[GetFirstIdx(T)].nama;
    int temp = T.TI[GetFirstIdx(T)].rating;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (T.TI[i].harga < min) {
            min = T.TI[i].harga;
            name = T.TI[i].nama;
            temp = T.TI[i].rating;
        } else if (T.TI[i].harga == min) {
            if (T.TI[i].rating > temp) {
                name = T.TI[i].nama;
            }
        }
    }
    return name;
}

int JumlahGamesRating(TabGames T, int R) {
    int count = 0;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (T.TI[i].rating == R) {
            count++;
        }
    }
    return count;
}
