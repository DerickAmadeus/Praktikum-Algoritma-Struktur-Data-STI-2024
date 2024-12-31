#include <stdio.h>
#include "mesinkarakter.h"

// Deklarasi variabel global
char currentChar; // Karakter saat ini
boolean EOP;      // Status akhir pita

void START() {
    // Membaca karakter pertama dari stdin
    currentChar = getchar();
    // Memeriksa apakah karakter yang dibaca adalah MARK
    if (currentChar == MARK) {
        EOP = true;  // EOP aktif
    } else {
        EOP = false; // EOP tidak aktif
    }
}

void ADV() {
    // Memastikan karakter saat ini bukan MARK
    if (!IsEOP()) {
        currentChar = getchar(); // Membaca karakter berikutnya
        if (currentChar == MARK) {
            EOP = true; // Mengatur EOP aktif jika karakter baru adalah MARK
        }
    }
}

char GetCC() {
    return currentChar; // Mengembalikan karakter saat ini
}

boolean IsEOP() {
    return (currentChar == MARK); // Mengembalikan true jika karakter saat ini adalah MARK
}
