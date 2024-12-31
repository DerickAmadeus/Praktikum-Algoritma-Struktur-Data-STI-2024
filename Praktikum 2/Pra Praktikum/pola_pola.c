#include <stdio.h> 

int main () { 
    char pola[100], kata[100]; 
    int cocok = 1;
    scanf("%s", pola);
    scanf("%s", kata);


    for (int i = 0; pola[i] != '\0' && kata[i] != '\0'; i++) {
        if (pola[i] != '*' && pola[i] != kata[i]) {
            cocok = 0;
        }
    }
    printf("%d\n", cocok);
    return 0;
}