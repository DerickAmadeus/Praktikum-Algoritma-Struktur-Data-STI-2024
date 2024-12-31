#include <stdio.h>

int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        long long N, D;
        scanf("%lld %lld", &N, &D);

        // Case when there are no pempek
        if (N == 0) {
            printf("1\n"); // Participant 1 wins
            continue;
        }

        // Case when N is less than D
        if (N < D) {
            printf("1\n"); // Participant 1 wins
            continue;
        }

        // Determine winner based on rounds and remaining pempek
        while (N >= D) {
            N -= D; // Participant 0 eats
            if (N < D) {
                printf("0\n"); // Participant 0 can eat, Participant 1 loses
                break;
            }
            N -= D; // Participant 1 eats
            if (N < D) {
                printf("1\n"); // Participant 1 cannot eat, Participant 0 wins
                break;
            }
        }
    }

    return 0;
}