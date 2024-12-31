#include "queue.h"

int durasiAntre(Queue queue, int k) {
    int totalTime = 0;       // Total waktu antre
    int position = k;        // Posisi elemen yang dilacak dalam antrean

    while (1) {
        int current;
        dequeue(&queue, &current); // Proses elemen pertama dalam antrean
        totalTime++;               // Tambahkan waktu proses

        if (position == 0) {       // Jika elemen yang dilacak diproses
            if (current == 1) {    // Jika ini adalah tiket terakhir
                break;             // Selesai
            } else {
                enqueue(&queue, current - 1); // Masukkan kembali sisa tiket
            }
        } else {                   // Jika elemen lain diproses
            if (current > 1) {     // Jika tiket belum habis
                enqueue(&queue, current - 1); // Masukkan kembali sisa tiket
            }
        }

        // Update posisi elemen yang dilacak
        position--;
        if (position < 0) {
            position = length(queue) - 1; // Wrap-around ke elemen terakhir
        }
    }

    return totalTime;
}
