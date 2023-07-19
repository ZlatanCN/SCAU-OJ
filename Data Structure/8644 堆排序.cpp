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
// 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE
// 请补全代码
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE* sizeof(ElemType));
	if(!L.elem)
		exit(ERROR);
	L.length=0;
	return OK;
}

int Load_Sq(SqList &L)
{
// 输出顺序表中的所有元素
	int i;
	if(L.length==0) printf("The List is empty!");  // 请填空
	else
	{
		for(i=1; i<=L.length; i++) printf("%d ",L.elem[i]); // 请填空
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

void HeapAdjust(SqList &L, int s, int m)
{
	int j;
	int rc = L.elem[s];
	for(j = 2 * s; j <= m; j *= 2)
	{
		if(j < m && L.elem[j] < L.elem[j + 1])
		{
			++j;
		}
		if(rc >= L.elem[j])
		{
			break;
		}
		L.elem[s] = L.elem[j];
		s = j;
	}
	L.elem[s] = rc;
}

void CreatHeap(SqList &L)
{
	int n = L.length, i;
	for(i = n / 2; i > 0; --i)
	{
		HeapAdjust(L, i, n);
	}
}

void HeapSort(SqList &L)
{
	int i;
	CreatHeap(L);
	Load_Sq(L);
	for(i = L.length; i > 1; --i)
	{
		int x = L.elem[1];
		L.elem[1] = L.elem[i];
		L.elem[i] = x;
		HeapAdjust(L, 1, i - 1);
		Load_Sq(L);
	}
}

int main()
{
	int n;
	SqList L;
	InitList_Sq(L);
	scanf("%d",&n);
	ListInsert_Sq(L,n);
	HeapSort(L);
}
