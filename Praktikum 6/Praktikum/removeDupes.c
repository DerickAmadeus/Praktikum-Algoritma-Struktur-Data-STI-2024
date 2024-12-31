#include <stdio.h>
# include "removeDupes.h"

Queue removeDupes (Queue queue){
    Queue newq;
    CreateQueue(&newq);
    ElType val;

    if (isEmpty(queue)) {
        return queue;
    }


    dequeue(&queue, &val);
    enqueue(&newq, val);

    while (!isEmpty(queue)) {
        if (HEAD(queue) != TAIL(newq)){
            dequeue(&queue, &val);
            enqueue(&newq, val);
        } else {
            dequeue(&queue, &val);
        }
    }
    return newq;
}
