#include <stdlib.h>
#include "Queue.h"

// Inisialisasi queue
void CreateQueue(Queue *Q) {
    CreateList(Q);
}

// Mengecek apakah queue kosong
boolean isEmpty(Queue Q) {
    return (first(Q) == NULL);
}

// Mengecek apakah queue penuh (tidak berlaku untuk linked list)
boolean isFull(Queue Q) {
    return false;
}

// Menambahkan elemen ke queue
void EnQueue(Queue *Q, infotype X) {
    Ins_Akhir(Q, X);
}

// Menghapus elemen dari queue
void DeQueue(Queue *Q, infotype *X) {
    Del_Awal(Q, X);
}

// Menghitung panjang queue
int PanjangQueue(Queue Q) {
    int count = 0;
    address current = first(Q);
    while (current != NULL) {
        count++;
        current = next(current);
    }
    return count;
}

// Mencetak semua antrian
void cetakAntrian(Queue *queues, int n_queues) {
    int i;
	for (i = 0; i < n_queues; i++) {
        printf("Antrian %d: ", i + 1);
        address current = first(queues[i]);
        if (current == NULL) {
            printf("Kosong");
        } else {
            while (current != NULL) {
                printf("%d ", info(current));
                current = next(current);
            }
        }
        printf("\n");
    }
}

// Mencari antrian terpendek
int cariAntrianTerpendek(Queue *queues, int n_queues) {
    int min_index = 0, i;
    int min_panjang = PanjangQueue(queues[0]);
    for (i = 1; i < n_queues; i++) {
        int panjang = PanjangQueue(queues[i]);
        if (panjang < min_panjang) {
            min_panjang = panjang;
            min_index = i;
        }
    }
    return min_index;
}

// Menunggu user untuk menekan Enter untuk lanjut
void waitForEnter() {
    printf("\nTekan Enter untuk melanjutkan...");
	getchar();
}

// Untuk Clear Buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Membersihkan layar
void clearScreen() {
    system("cls || clear");
}
