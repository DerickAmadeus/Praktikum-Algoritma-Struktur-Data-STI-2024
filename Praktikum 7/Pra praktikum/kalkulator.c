#include <stdio.h>
#include "stack.h"
// #include "stackchar.h"
#include "boolean.h"

int main() {
    Stack hasil;
    // StackChar operasi;
    CreateEmpty(&hasil);
    // CreateEmptyChar(&operasi);

    int operand;
    long long int currentResult = 0;
    char op;

    // Push initial result (0) to the stack
    Push(&hasil, currentResult);

    while (1) {
        // Read operation
        scanf("%c", &op);

        if (op == '+') {
            // Addition operation
            scanf(" %lld", &operand);
            currentResult += operand;
            Push(&hasil, currentResult);
        } 
        else if (op == '-') {
            // Subtraction operation
            scanf(" %d", &operand);
            currentResult -= operand;
            Push(&hasil, currentResult);
        } 

        else if (op == 'u') {
            infotype buang;
            if (!IsEmpty(hasil)) { 
                Pop(&hasil, &buang);
                currentResult =  InfoTop(hasil);
            }
        } 
        else if (op == '=') {
            printf("%lld\n", currentResult);
            break;
        }
    }

    return 0;
}
