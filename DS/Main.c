#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void TestSeqList()
{
	//SeqList mylist;
	//SeqListInit(&mylist);
	//SeqListPushFront(&mylist, 2);
	//SeqListPushFront(&mylist, 3);
	//SeqListPushFront(&mylist, 4);
	//SeqListPushFront(&mylist, 5);
	//SeqListPushFront(&mylist, 8);
	//SeqListPushFront(&mylist, 7);
	//SeqListPrint(&mylist);
	////SeqListBubbleSort(&mylist);
	////SeqListReverse(&mylist);
	////SeqListClear(&mylist);
	//SeqListPushBack(&mylist, 2);
	//SeqListPushBack(&mylist, 3);
	//SeqListPushBack(&mylist, 4);
	//SeqListPushBack(&mylist, 5);
	//SeqListPushBack(&mylist, 8);
	//SeqListPushBack(&mylist, 7);
	//SeqListPrint(&mylist);
	//printf("%d\n", SeqListLength(&mylist));
	//for (int k = 1; k < 9; k++)
	//{
	//	SeqListEraseByVal(&mylist, k);
	//	SeqListPrint(&mylist);
	//}
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopFront(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopFront(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopFront(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopFront(&mylist);
	//SeqListPrint(&mylist);
	//printf("%d\n", SeqListLength(&mylist));
	//SeqListPushFront(&mylist, 1);
	//printf("%d\n", SeqListLength(&mylist));
	//SeqListPushFront(&mylist, 2);
	//SeqListPushFront(&mylist, 3);
	//SeqListPushFront(&mylist, 4);
	//SeqListPushFront(&mylist, 5);
	//SeqListPushFront(&mylist, 6);
	//SeqListPushFront(&mylist, 7);
	//SeqListPrint(&mylist);
	//printf("%d\n", SeqListLength(&mylist));
	//int k = -1;
	//while (k < 9)
	//{
	//	int ret = SeqListFind(&mylist, k);
	//	if (ret == -1)
	//		printf("find none!\n");
	//	else
	//		printf("idx = %d\n", ret);
	//	k++;
	//}
	//SeqListPopFront(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopFront(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopFront(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopFront(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopFront(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopFront(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopFront(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPushFront(&mylist, 1);
	//SeqListPushFront(&mylist, 2);
	//SeqListPushFront(&mylist, 3);
	//SeqListPushFront(&mylist, 4);
	//SeqListPushFront(&mylist, 5);
	//SeqListPushFront(&mylist, 6);
	//SeqListPushFront(&mylist, 7);
	//SeqListPushBack(&mylist, 7);
	//SeqListPushBack(&mylist, 8);
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListPopBack(&mylist);
	//SeqListPrint(&mylist);
	//SeqListDestroy(&mylist);
}
void MergeSeqList(SeqList* l1, SeqList* l2, SeqList* res)
{
	assert(l1 != NULL && l2 != NULL, res != NULL);
	int i1 = 0, i2 = 0, ri = 0;
	while (i1 < l1->size && i2 < l2->size)
	{
		CheckCapacity(res);
		if (l1->base[i1] < l2->base[i2])
			res->base[ri++] = l1->base[i1++];
		else
			res->base[ri++] = l2->base[i2++];
		res->size++;
	}
	while (i1 < l1->size)
	{
		CheckCapacity(res);
		res->base[ri++] = l1->base[i1++];
		res->size++;
	}
	while (i2 < l2->size)
	{
		CheckCapacity(res);
		res->base[ri++] = l2->base[i2++];
		res->size++;
	}
}
void TestMergeSeqList()
{
	SeqList l1, l2, res;
	SeqListInit(&l1);
	SeqListInit(&l2);
	SeqListInit(&res);
	for (int i = 0; i < 20; i += 2)
		SeqListPushBack(&l1, i);
	for (int i = 1; i < 21; i += 2)
		SeqListPushBack(&l2, i);
	MergeSeqList(&l1, &l2, &res);
	SeqListPrint(&res);
	SeqListDestroy(&l1);
	SeqListDestroy(&l2);
	SeqListDestroy(&res);
}
void Test()
{
	SeqList la, lb, lc;
	SeqListInit(&la), SeqListInit(&lb), SeqListInit(&lc);
	for (int i = 0; i <= 10; i += 2)
		SeqListPushBack(&la, i),
		SeqListPushBack(&lb, i + 1);
	Merge(&la, &lb, &lc);
	SeqListPrint(&lc);
	SeqListDestroy(&la), SeqListDestroy(&lb), SeqListDestroy(&lc);
}
int main()
{
	//TestSeqList();
	//TestMergeSeqList();
	Test();
	return 0;
}