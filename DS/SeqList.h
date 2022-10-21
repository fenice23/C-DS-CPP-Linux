#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#define SEQLIST_INIT_SIZE 8
#define MULTIPLE 2
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vld.h>
#include <stdbool.h>
typedef int ElemType;
typedef struct SeqList
{
	ElemType* base;
	int size;
	int capacity;
} SeqList;
void SeqListInit(SeqList* list);
void SeqListDestroy(SeqList* list);
void SeqListClear(SeqList* list);
void SeqListPrint(SeqList* list);
void CheckCapacity(SeqList* list);
void SeqListPushBack(SeqList* list, ElemType x);
void SeqListPushFront(SeqList* list, ElemType x);
void SeqListPopBack(SeqList* list);
void SeqListPopFront(SeqList* list);
void SeqListInsertByPos(SeqList* list, int pos, ElemType x);
int SeqListFind(SeqList* list, ElemType k);
int SeqListLength(SeqList* list);
void SeqListEraseByPos(SeqList* list, int pos);
void SeqListEraseByVal(SeqList* list, ElemType k);
void SeqListBubbleSort(SeqList* list);
void SeqListReverse(SeqList* list);
#endif//!__SEQLIST_H__