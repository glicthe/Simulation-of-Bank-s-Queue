// Nama: Fauzan Juniar Mulyana 
// Kelas: 1A-D4
// Prodi: D4 Teknik informatika
// Tanggal: 20 Mar 2025
// Nama File: main.c

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(int argc, char *argv[]) {
    int n_queues, i;
    printf("Masukkan jumlah antrian: ");
    scanf("%d", &n_queues);

    Queue *queues = (Queue *)malloc(n_queues * sizeof(Queue));
    for (i = 0; i < n_queues; i++) {
        CreateQueue(&queues[i]);
    }

    int nomor_antrian = 1;
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
		clearBuffer();
		
        switch (pilihan) {
            case 1: {
                int target = cariAntrianTerpendek(queues, n_queues);
                EnQueue(&queues[target], nomor_antrian);
                printf("Nomor antrian %d ditambahkan ke antrian %d\n", nomor_antrian, target + 1);
                nomor_antrian++;
                cetakAntrian(queues, n_queues);
                waitForEnter();
                break;
            }
            case 2: {
                int queue_pilihan;
                printf("Pilih antrian yang akan diproses (1-%d): ", n_queues);
                scanf("%d", &queue_pilihan);
                clearBuffer();
                if (queue_pilihan < 1 || queue_pilihan > n_queues) {
                    printf("Pilihan tidak valid!\n");
                    waitForEnter();
					break;
                }
                int idx = queue_pilihan - 1;
                if (isEmpty(queues[idx])) {
                    printf("Antrian %d kosong!\n", queue_pilihan);
                } else {
                    infotype nomor;
                    DeQueue(&queues[idx], &nomor);
                    printf("Nomor %d diproses dari antrian %d\n", nomor, queue_pilihan);
                    cetakAntrian(queues, n_queues);
                }
                waitForEnter();
                break;
            }
            case 3:
                cetakAntrian(queues, n_queues);
                waitForEnter();
				break;
            case 4:
                printf("Terima kasih!\n");
				break;
            default:
                printf("Pilihan tidak valid!\n");
        		waitForEnter();
		}
        clearScreen();
    } while (pilihan != 4);

    // Membersihkan memori
    for (i = 0; i < n_queues; i++) {
        address current = queues[i].first;
        while (current != NULL) {
            address temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(queues);

    return 0;
}
