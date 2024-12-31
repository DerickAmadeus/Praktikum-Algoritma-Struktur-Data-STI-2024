#include "queuelist.h"

/* Prototype manajemen memori */
void Alokasi(address *P, infotype X) {
    *P = (address)malloc(sizeof(ElmtQueue));
    if (*P != Nil) {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi(address P) {
    free(P);
}

/* ********* Prototype Queue ********* */
boolean IsEmpty(Queue Q) {
    return Head(Q) == Nil && Tail(Q) == Nil;
}

int NbElmt(Queue Q) {
    int count = 0;
    address P = Head(Q);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

/* *** Kreator *** */
void CreateEmpty(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void Enqueue(Queue *Q, infotype X) {
    address P;
    Alokasi(&P, X);
    if (P != Nil) {
        if (IsEmpty(*Q)) {
            Head(*Q) = P;
        } else {
            Next(Tail(*Q)) = P;
        }
        Tail(*Q) = P;
    }
}

void Dequeue(Queue *Q, infotype *X) {
    if (!IsEmpty(*Q)) {
        address P = Head(*Q);
        *X = Info(P);
        Head(*Q) = Next(Head(*Q));
        if (Head(*Q) == Nil) {
            Tail(*Q) = Nil;
        }
        Dealokasi(P);
    }
}
