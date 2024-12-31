/* File: mesinkata.c */
/* Implementasi Mesin Kata */

#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks() {
    
    while (currentChar == BLANK && !IsEOP()) {
        ADV();
    }
}

void STARTWORD() {
    
    START();  
    IgnoreBlanks();
    if (IsEOP()) {
        EndWord = true;  
    } else {
        EndWord = false;
        CopyWord();  
    }
}

void ADVWORD() {
    
    IgnoreBlanks();
    if (IsEOP()) {
        EndWord = true;  
    } else {
        CopyWord();  
    }
}

void CopyWord() {
    
    CurrentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && CurrentWord.Length < NMax) {
        CurrentWord.TabWord[CurrentWord.Length] = currentChar;
        CurrentWord.Length++;
        ADV();
    }

    if (CurrentWord.Length < NMax) {
        CurrentWord.TabWord[CurrentWord.Length] = '\0';
    }
}
