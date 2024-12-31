# include <stdio.h>
# include "stack.h"
# include "boolean.h"

int main() {
    int panjang;
    scanf("%d", &panjang);
    char par[panjang];
    scanf("%s", par);
    Stack masa;
    CreateEmpty(&masa);
    infotype bebas;

    for (int i = 0; i <= panjang; i ++) { 
        if (par[i] == '<') { 
            Push(&masa, par[i]);
        }
        else if (par[i] == '>' && !IsEmpty(masa)) {
            Pop(&masa, &bebas);
            printf("<>");
    }

    }
    printf("\n");


    
}