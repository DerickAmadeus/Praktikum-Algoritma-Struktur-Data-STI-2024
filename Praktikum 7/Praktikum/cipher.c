#include <stdio.h>


int main() {
    char kata[90];
    scanf("%s", kata);
    char katapertama[90];
    int total = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    while (kata[i] != ' ' || kata[i] != '.'){
        katapertama[i] = kata[i];
        i +=1;
        if (kata[i] == ' ' || kata[i] == '.'){
            break;
        }
        }
    
    while (katapertama[j] != '\0') {
        total += 1;
        j += 1;

    }
    while (kata[k] != '.') {
        if (kata[k] == 35){
            printf("%c", kata[k]);
        }
        else {printf("%c", kata[k] + total);}
        
        k +=1;
        if (kata[k] == '.') {
            break;
        }

    }
        

    
    printf("\n");

    // while (kata[k] != '.') {
    //         kata[k] += total;
    //         k +=1 ;
    //         printf("%c", kata[i]);
        
    // }
    
}