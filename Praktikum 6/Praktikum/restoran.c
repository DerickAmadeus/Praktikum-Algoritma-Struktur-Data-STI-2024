#include <stdio.h>
#include "queue.h"
#include "boolean.h"

int main() {
    Queue queue;
    CreateQueue(&queue);

    int totalDishes = 0;
    int minTime = 0;     
    int maxTime = 0;   

    while (1) {
        int command;
        scanf("%d", &command);

        if (command == 0) {
            break; 
        } else if (command == 1) {
            int cookTime;
            scanf("%d", &cookTime);
            if (cookTime > 0) { 
                enqueue(&queue, cookTime);
            }
        } else if (command == 2) {
            if (!isEmpty(queue)) {
                int cookTime;
                dequeue(&queue, &cookTime);

                // Update statistik masakan
                totalDishes++;
                if (totalDishes == 1) {
                    minTime = maxTime = cookTime; 
                } else {
                    if (cookTime < minTime) {
                        minTime = cookTime;
                    }
                    if (cookTime > maxTime) {
                        maxTime = cookTime;
                    }
                }
            }
        }
    }

    // Cetak hasil
    printf("%d\n", totalDishes);
    printf("%d\n", minTime);
    printf("%d\n", maxTime);

    return 0;
}
