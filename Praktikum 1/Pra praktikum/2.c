#include <stdio.h>

int arr[5];  // Global array, initialized to 0

int main() {
    // Printing values (will be zero)
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);  // Output will be 0 0 0 0 0
    }

    return 0;
}