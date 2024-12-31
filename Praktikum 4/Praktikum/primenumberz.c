# include <stdio.h>
# include <stdlib.h>
# include "arraydin.h"


int main() {
    ArrayDin array;
    array = MakeArrayDin();
    int n;
    int i = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        InsertLast(&array, x);
    }

    while (!IsEmpty(array)) {
        int prime = 2;
        int hasil = 0;
        while (Get(array, 0) % prime != 0 && prime < Get(array, 0)) {
            prime++;
        }
        hasil = Get(array, 0) / prime;
        printf("%d", prime);
        if (hasil > prime ) {
            DeleteFirst(&array);
            InsertFirst(&array, hasil);
        } else {
            if (hasil != 1) {
                printf(" %d", hasil);
                DeleteFirst(&array);
            } else {
                DeleteFirst(&array);
            }
        }
        if (!IsEmpty(array)) {
            printf(" ");
        }
    }
    printf("\n");
}

