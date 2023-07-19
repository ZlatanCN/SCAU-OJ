#include<stdio.h>
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
	int listsize;
}SqList;

int InitList_Sq(SqList &L)
{
// 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE
// 请补全代码
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) return ERROR;
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
}

int input_Sq(SqList &L,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&L.elem[i]);
		L.length++;
	}
	return OK;
}

void output_Sq(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
}

void MergeList_Sq(SqList LA,SqList LB,SqList &LC)
{
	int *pa,*pb,*pc,*pa_last,*pb_last;
	LC.length=LA.length+LB.length;
	LC.elem=new ElemType[LC.length];
	pc=LC.elem;pa=LA.elem;pb=LB.elem;
	pa_last=LA.elem+LA.length-1;pb_last=LB.elem+LB.length-1;
	while((pa<=pa_last)&&(pb<=pb_last))
	{
		if(*pa<=*pb) *pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last) *pc++=*pa++;
	while(pb<=pb_last) *pc++=*pb++;
}

int main()
{
	SqList LA,LB,LC;
	int a,b;
	scanf("%d",&a);InitList_Sq(LA);input_Sq(LA,a);
	scanf("%d",&b);InitList_Sq(LB);input_Sq(LB,b);
	printf("List A:");output_Sq(LA);printf("\n");
	printf("List B:");output_Sq(LB);printf("\n");
	MergeList_Sq(LA,LB,LC);
	printf("List C:");output_Sq(LC);printf("\n");
}
