#include <stdio.h>

// Fungsi untuk mengurutkan array angka secara ascending (naik)
void sort_asc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Fungsi untuk mengubah integer menjadi array digit
void int_to_array(int n, int arr[]) {
    for (int i = 0; i < 4; i++) {
        arr[3 - i] = n % 10;
        n /= 10;
    }
}

// Fungsi untuk mengubah array digit menjadi integer
int array_to_int(int arr[]) {
    int result = 0;
    for (int i = 0; i < 4; i++) {
        result = result * 10 + arr[i];
    }
    return result;
}

// Fungsi untuk menghitung berapa langkah menuju 6174
int kaprekar_steps(int n) {
    if (n == 6174) {
        return 0;
    }
    int steps = 0;

    while (n != 6174) {
        int digits[4];
        int_to_array(n, digits);

        // Urutkan secara ascending
        sort_asc(digits, 4);
        int min_num = array_to_int(digits);

        // Urutkan secara descending 
        for (int i = 0; i < 2; i++) {
            int temp = digits[i];
            digits[i] = digits[3 - i];
            digits[3 - i] = temp;
        }
        int max_num = array_to_int(digits);

        n = max_num - min_num;
        steps++;

        // Jika n menjadi 0, return -1 (tidak mungkin mencapai 6174)
        if (n == 0) {
            return -1;
        }
    }

    return steps;
}

int main() {
    int n;
    scanf("%d", &n);

    int result = kaprekar_steps(n);
    printf("%d\n", result);

    return 0;
}