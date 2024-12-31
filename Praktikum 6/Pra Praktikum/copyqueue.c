#include "queue.h"
#include "copyqueue.h"

void copyQueue(Queue *queueInput, Queue *queueOutput) {

    CreateQueue(queueOutput);
    
    Queue tempQueue;
    CreateQueue(&tempQueue);
    
    ElType val;

    while (!isEmpty(*queueInput)) {
        dequeue(queueInput, &val);
        enqueue(&tempQueue, val);
        enqueue(queueOutput, val);
    }
    

    while (!isEmpty(tempQueue)) {

        dequeue(&tempQueue, &val);

        enqueue(queueInput, val);
    }
}
