# include <stdio.h>
#include "hitungfrekuensi.h"

char currentChar;
boolean EOP;

int hitungfrekuensi(){
    START();
    int count = 0;
    while (!EOP) {
        currentChar = GetCC();
        if (currentChar == 'T' || currentChar=='t') {
            ADV();
            currentChar = GetCC();
            if (currentChar == 'i' || currentChar=='I'){
                ADV();
                currentChar = GetCC();
                if (currentChar == 'G' || currentChar=='g'){
                    ADV();
                    currentChar = GetCC();
                    if (currentChar == 'A' || currentChar == 'a'){
                        count += 1;
                    }
                }
            }
        }
        else {
            ADV();
        }
    }
    return (count);

}