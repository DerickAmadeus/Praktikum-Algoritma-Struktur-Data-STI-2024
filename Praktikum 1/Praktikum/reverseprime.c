#include <stdio.h>

int is_prime_digit(int digit) {
    return (digit == 2 || digit == 3 || digit == 5 || digit == 7);
}

int main() {
    int num, digit, found_prime = 0;
    scanf("%d", &num);
    

    while (num > 0) {
        digit = num % 10;  
        if (is_prime_digit(digit)) {
            printf("%d", digit);  
            found_prime = 1;  
        }
        num /= 10;  
    }
    
    
    if (!found_prime) {
        printf("0");
    }
    
    printf("\n");
    
    return 0;
}