#include <stdio.h>

int main() {
    int Q;
    scanf("%d", &Q); 

    for (int i = 0; i < Q; i++) {
        long N, D;
        scanf("%ld %ld", &N, &D);  

        int turn = 1; 
        while (N >= D) {  
            N -= D;  
            turn = 1 - turn; 
        }


        printf("%d\n", turn);
    }

    return 0;
}

// GTW bener ato ga, dah kena limit nyoba
// Hehe