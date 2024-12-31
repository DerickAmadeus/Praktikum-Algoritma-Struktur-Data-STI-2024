# include <stdio.h>
# include "mesinkata.h"


int main () {
    STARTWORD();
    int shift = currentWord.Length;
    Word kata = currentWord;


    while (!isEndWord()) {
        for (int i = 0; i < currentWord.Length; i++) {
        if (currentWord.TabWord[i] >= 'A' && currentWord.TabWord[i] <= 'Z') {
            currentWord.TabWord[i] = (currentWord.TabWord[i] - 'A' + shift) % 26 + 'A';
            printf("%c", currentWord.TabWord[i]);
        }
        }
        ADVWORD();
        if (isEndWord()) {
            break;
        }
        printf(" ");
    }
    printf(".\n");
}





