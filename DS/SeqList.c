#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void SeqListInit(SeqList* list)
{
	assert(list != NULL);
	list->capacity = SEQLIST_INIT_SIZE;
	list->size = 0;
	list->base = (ElemType*)malloc(list->capacity * sizeof(ElemType));
	assert(list->base != NULL);
}
void SeqListDestroy(SeqList* list)
{
	assert(list != NULL);
	if (list->base)
		free(list->base);
	list->base = NULL;
	list->capacity = list->size = 0;
}
void SeqListClear(SeqList* list)
{
	assert(list != NULL);
	list->size = 0;
}
void SeqListPrint(SeqList* list)
{
	assert(list != NULL);
	for (int i = 0; i < list->size; i++)
		printf("%d ", list->base[i]);
	printf("\n");
}
void CheckCapacity(SeqList* list)
{
	assert(list != NULL);
	if (list->size == list->capacity)
	{
		list->capacity *= MULTIPLE;
		ElemType* p = (ElemType*)realloc(list->base, list->capacity * sizeof(ElemType));
		if (p == NULL)
		{
			perror("p realloc error");
			free(list->base);
			list->base = NULL;
			list->size = list->capacity = 0;
			exit(-1);
		}
		list->base = p;
	}
}
void SeqListPushBack(SeqList* list, ElemType x)
{
	//assert(list != NULL);
	//if (list->size == list->capacity)
	//{
	//	printf("顺序表空间已满,不能尾部插入.\n");
	//	return;
	//}
	//list->base[list->size++] = x;
	SeqListInsertByPos(list, list->size, x);
}
void SeqListPushFront(SeqList* list, ElemType x)
{
	//assert(list != NULL);
	//if (list->size == list->capacity)
	//{
	//	printf("顺序表空间已满,不能头部插入.\n");
	//	return;
	//}
	//for (int i = list->size - 1; i >= 0; i--)
	//	list->base[i + 1] = list->base[i];
	//list->base[0] = x;
	//list->size++;
	SeqListInsertByPos(list, 0, x);
}
void SeqListPopBack(SeqList* list)
{
	//assert(list != NULL);
	//if (list->size == 0)
	//{
	//	printf("顺序表已空,不能尾部删除.\n");
	//	return;
	//}
	//list->size--;
	SeqListEraseByPos(list, list->size - 1);
}
void SeqListPopFront(SeqList* list)
{
	//assert(list != NULL);
	//if (list->size == 0)
	//{
	//	printf("顺序表已空,不能头部删除.\n");
	//	return;
	//}
	//for (int i = 0; i < list->size - 1; i++)
	//	list->base[i] = list->base[i + 1];
	//list->size--;
	SeqListEraseByPos(list, 0);
}
void SeqListInsertByPos(SeqList* list, int pos, ElemType x)
{
	//assert(list != NULL);
	//assert(pos >= 0 && pos <= list->size);
	//if (list->size == list->capacity)
	//{
	//	printf("顺序表已满,不能在%d下标处插入%d.\n", pos, x);
	//	return;
	//}
	//for (int i = list->size; i > pos; i--)
	//{
	//	list->base[i] = list->base[i - 1];
	//}
	//list->base[pos] = x;
	//list->size++;
	assert(list != NULL);
	assert(pos >= 0 && pos <= list->size);
	CheckCapacity(list);
	for (int i = list->size; i > pos; i--)
	{
		list->base[i] = list->base[i - 1];
	}
	list->base[pos] = x;
	list->size++;
}
int SeqListFind(SeqList* list, ElemType k)
{
	assert(list != NULL);
	int i = 0;
	for (i = 0; i < list->size && list->base[i] != k; i++);
	if (i == list->size)
		return -1;
	else
		return i;
}
int SeqListLength(SeqList* list)
{
	assert(list != NULL);
	return list->size;
}
void SeqListEraseByPos(SeqList* list, int pos)
{
	assert(list != NULL);
	assert(pos >= 0 && pos <= list->size - 1);
	if (list->size == 0)
	{
		printf("顺序表已空,无法在%d位置删除数据.\n", pos);
		return;
	}
	for (int i = pos; i < list->size - 1; i++)
		list->base[i] = list->base[i + 1];
	list->size--;
}
void SeqListEraseByVal(SeqList* list, ElemType k)
{
	assert(list != NULL);
	int pos = SeqListFind(list, k);
	if (pos != -1)
	{
		SeqListEraseByPos(list, pos);
		printf("删除数据%d成功.\n", k);
	}
	else
	{
		printf("顺序表中没有%d,删除数据失败.\n", k);
	}
}
static void Swap(ElemType* p1, ElemType* p2)
{
	assert(p1 != NULL && p2 != NULL);
	ElemType t = *p1;
	*p1 = *p2;
	*p2 = t;
}
void SeqListBubbleSort(SeqList* list)
{
	assert(list != NULL);
	bool flag = false;
	for (int i = 0; i < list->size - 1; i++)
	{
		flag = false;
		for (int j = 0; j < list->size - 1 - i; j++)
		{
			if (list->base[j] > list->base[j + 1])
			{
				Swap(list->base + j, list->base + j + 1);
				flag = true;
			}
		}
		if (!flag)	break;
	}
}
void SeqListReverse(SeqList* list)
{
	assert(list != NULL);
	int l = 0, r = list->size - 1;
	while (l < r)
	{
		ElemType t = list->base[l];
		list->base[l] = list->base[r];
		list->base[r] = t;
		l++, r--;
	}
}
void Merge(SeqList* pla, SeqList* plb, SeqList* plc)
{
	assert(pla != NULL && plb != NULL && plc != NULL);
	int ia = 0, ib = 0;
	while (ia < pla->size && ib < plb->size)
	{
		//CheckCapacity(plc);
		if (pla->base[ia] < plb->base[ib])
			//plc->base[plc->size++] = pla->base[ia++];
			SeqListPushBack(plc, pla->base[ia++]);
		else
			//plc->base[plc->size++] = plb->base[ib++];
			SeqListPushBack(plc, plb->base[ib++]);
	}
	while (ia < pla->size)
	{
		//CheckCapacity(plc);
		//plc->base[plc->size++] = pla->base[ia++];
		SeqListPushBack(plc, pla->base[ia++]);
	}
	while (ib < plb->size)
	{
		//CheckCapacity(plc);
		//plc->base[plc->size++] = plb->base[ib++];
		SeqListPushBack(plc, plb->base[ib++]);
	}
}