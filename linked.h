#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>

// Accessor macros
#define next(P) (P)->next
#define info(P) (P)->info
#define first(L) (L).first

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address next;
}ElmtList;

typedef struct {
	address first;
}List;

void Ins_Akhir(List *L, infotype X);
void Del_Awal(List *L, infotype *X);
void CreateList(List *L);

#endif
