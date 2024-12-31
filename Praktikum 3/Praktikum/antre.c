# include<stdio.h>

int main () {
    int l;
    scanf("%d", &l);
    int ant[l];
    int i;
    for (i = 0; i < l; i ++){
        scanf("%d", &ant[i]);
    }
    int curr;
    curr = ant[0];

    for(i = 1; i < l ; i++){
        if (curr == ant[i]) {
            ant[i-1] = 0;
            curr = ant[i];
        }
        else {
            curr = ant[i];
        }
    }
    // for(i = 0; i <l ; i++){
    //     printf("%d ", ant[i]);
    // }

    for(i=0; i<l;i++){
        if (ant[i] != 0){
            printf("%d", ant[i]);
        if (i == l-1) {
            break;
        }else {
            if (ant[i] != 0){
                printf(" ");
            }
        }}
    }
    // if (ant[l] != 0){
    //     printf("%d", ant[l]);
    // } 
    printf("\n");

}