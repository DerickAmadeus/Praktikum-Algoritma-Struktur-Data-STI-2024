# include <stdio.h>
# include "secret_code.h"

int count_length(char str[]) { 
    int i;
    int j=0;

    for (i =0 ; str [i] != '#' && str[i] != '\0'; i ++){
        j += 1;
    }
    return j;
}

void print_decrypted(char str[]) {
    int n = count_length (str);
    for(int i = 0; i <=n ; i ++) {
        if ((str[i] <= 122 && str[i] >= 97) || (str[i] <= 90 && str[i]>= 65)){
            printf("%c", str[i]);
        }
    }
    printf("\n");
    
}


// int main () { 
//     char str[100]; 
//     scanf("%s", str);
//     print_decrypted(str);
//     return 0;
// }