#include <stdio.h>

int main () {
    int N;
    scanf("%d", &N);
    int Arr[N];


    int i;
    for (i = 0; i < N; i ++){
        scanf("%d", &Arr[i]);
    }

    int max = Arr[0];
    int totalMax = 0;

    for (i = 0; i < N ; i ++) {
        if (Arr[i] > max) {
            max = Arr[i];
            totalMax = 1;
        }
        else if (Arr[i] == max) {
            totalMax += 1;
        }
    }
    printf("%d %d\n", max, totalMax);

    for (i = 0; i < N; i++){
        if (Arr[i] == max) { 
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}