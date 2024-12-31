#include<stdio.h>

int hitung(char a[]){
    int i = 0;
    while (a[i] != '.'){
        i += 1;
    }
    return i;
}

// void caesara(char a[], int len){
//     int i;
//     for (i = 0; i < len; i ++){
//         a[i] += len;
//         printf("%c", a[i]);

//     }
//     printf("\n");
// }

int main() { 
    char caesar[20]; 
    scanf("%s", caesar);
    int len = hitung(caesar);
    int i;
    for (i = 0; i < len; i ++){
        caesar[i] += len;
        if (caesar[i] > 90){
            caesar[i] -= 26;
        }
        printf("%c", caesar[i]);

    }
    printf("\n");
    return 0;
}