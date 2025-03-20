#include "linked.h"
#include <stdlib.h>

// Membuat list kosong
void CreateList(List *L) {
    first(L) = NULL;
}

// Menambahkan elemen di akhir list
void Ins_Akhir(List *L, infotype X) {
    address newNode = (address)malloc(sizeof(struct tElmtList));
    info(newNode) = X;
    next(newNode) = NULL;

    if (first(L) == NULL) {
        first(L) = newNode;
    } else {
        address current = first(L);
        while (next(current) != NULL) {
            current = next(current);
        }
        current->next = newNode;
    }
}

// Menghapus elemen di awal list
void Del_Awal(List *L, infotype *X) {
    if (first(L) == NULL) {
        *X = -1; // Nilai error jika list kosong
        return;
    }
    address temp = first(L);
    *X = info(temp);
    first(L) = next(first(L));
    free(temp);
}
