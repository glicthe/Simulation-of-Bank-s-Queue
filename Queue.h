#ifndef QUEUE_H
#define QUEUE_H


#include "linked.h"
#include "boolean.h"

typedef List Queue;

// Membuat Queue
void CreateQueue(Queue *Q);

// cek apakah Queue kosong
boolean isEmpty(Queue Q);

// cek apakah Queue penuh
boolean isFull(Queue Q);

void EnQueue(Queue *Q, infotype X);
void DeQueue(Queue *Q, infotype *X);
int PanjangQueue(Queue Q);

void cetakAntrian(Queue *queues, int n_queues);
int cariAntrianTerpendek(Queue *queues, int n_queues);


//fungsi tambahan
void waitForEnter();
void clearScreen();
void clearBuffer();

#endif
