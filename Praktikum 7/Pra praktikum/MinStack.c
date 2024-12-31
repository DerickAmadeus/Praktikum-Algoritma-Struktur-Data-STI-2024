#include <stdio.h>
#include "stack.h"
#include "boolean.h"

int main() {
    int Q;
    scanf("%d", &Q);

    Stack residents;   // Stack to store residents' money
    CreateEmpty(&residents);

    int currentMaxMoney = -1000000000;  // Initialize to a very low value, representing the minimum possible money
    int currentMaxFloor = 0;  // To track the floor of the resident with max money

    for (int i = 0; i < Q; i++) {
        int command;
        scanf("%d", &command);

        if (command == 1) {
            int money;
            scanf("%d", &money);

            // Push the new resident's money to the residents stack
            Push(&residents, money);

            // Update the currentMaxMoney and currentMaxFloor
            if (money > currentMaxMoney) {
                currentMaxMoney = money;
                currentMaxFloor = Top(residents);  // 0-based index, so it's the current floor
            }

        } else if (command == 2) {
            // Pop the top resident's money
            int temp;
            Pop(&residents, &temp);

            // Recalculate currentMaxMoney after removal
            if (!IsEmpty(residents)) {
                // Recalculate the max value by traversing the stack
                currentMaxMoney = InfoTop(residents);
                currentMaxFloor = Top(residents);

                // Traverse to find the actual maximum money in the stack
                for (int j = 0; j <= Top(residents); j++) {
                    int moneyAtFloor = residents.T[j];
                    if (moneyAtFloor > currentMaxMoney) {
                        currentMaxMoney = moneyAtFloor;
                        currentMaxFloor = j;  // Update the floor
                    }
                }
            } else {
                currentMaxMoney = -1000000000;  // Reset if no residents are left
                currentMaxFloor = 0;
            }

        } else if (command == 3) {
            // Print the floor (1-based) and the max money
            printf("%d %d\n", currentMaxFloor + 1, currentMaxMoney);  // Convert floor to 1-based
        }
    }

    return 0;
}
