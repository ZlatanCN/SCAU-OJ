#include<cstdio>
#include <cstdlib>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
	int *elem;
	int length;
} SqList;

int InitList_Sq(SqList &L)
{
// �㷨2.3������һ���յ����Ա�L�������Ա�Ԥ�����СΪLIST_INIT_SIZE
// �벹ȫ����
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE* sizeof(ElemType));
	if(!L.elem)
		exit(ERROR);
	L.length=0;
	return OK;
}

int Load_Sq(SqList &L)
{
// ���˳����е�����Ԫ��
	int i;
	if(L.length==0) printf("The List is empty!");  // �����
	else
	{
		for(i=1; i<=L.length; i++) printf("%d ",L.elem[i]); // �����
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L, int n)
{
	int j;
	for(j = 1; j <= n; j++)
	{
		scanf("%d",&L.elem[j]);
		L.length++;
	}
	return 1;
}

void BinsertSort(SqList &L)
{
	int i, low, high, mid, j;
	for(i = 2; i <= L.length; ++i)
	{
		L.elem[0] = L.elem[i];
		low = 1;
		high = i - 1;
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(L.elem[0] < L.elem[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for(j = i - 1; j >= high + 1; --j)
		{
			L.elem[j + 1] = L.elem[j];
		}
		L.elem[high + 1] = L.elem[0];
		Load_Sq(L);
	}
}

int main()
{
	SqList L;
	InitList_Sq(L);
	int n;
	scanf("%d",&n);
	ListInsert_Sq(L, n);;
	BinsertSort(L);
}
