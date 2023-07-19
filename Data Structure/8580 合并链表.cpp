#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int

typedef int Status;
typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode,*LinkList;


Status ListInsert_L(LinkList &L, int i, ElemType e)    // 算法2.9
{
	// 在带头结点的单链线性表L的第i个元素之前插入元素e
	LinkList p,s;
	p = L;
	int j = 0;
	while (p && j < i-1)    // 寻找第i-1个结点
	{
		p = p->next;
		++j;
	}
	if (!p || j > i-1) return ERROR;      // i小于1或者大于表长
	s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
	s->data = e;
	s->next = p->next;      // 插入L中
	p->next = s;
	return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e)    // 算法2.10
{
	// 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
	LinkList p,q;
	p = L;
	int j = 0;
	while (p->next && j < i-1)    // 寻找第i个结点，并令p指向其前趋
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i-1) return ERROR;  // 删除位置不合理
	q = p->next;
	p->next = q->next;           // 删除并释放结点
	e = q->data;
	free(q);
	return OK;
} // ListDelete_L

int creat(LinkList &L,int n)
{
	LinkList p,q;
	int i,e;
	L = new LNode;
	L->next = NULL;
	q = L;
	for(i = 0; i < n; i++)
	{
		scanf("%d",&e);
		p = new LNode;
		p->data = e;
		p->next = NULL;
		q->next = p;
		q = p;
	}
	return 1;
}

int merge(LinkList A,LinkList B,LinkList &C)
{
	C = new LNode;
	C->next = NULL;
	LinkList i,j,k,p;
	i = A->next;
	j = B->next;
	k = C;
	while(i && j)
	{
		p = new LNode;
		p->next = NULL;
		if(i->data <= j->data)
		{
			p->data = i->data;
			i = i->next;
		}
		else
		{
			p->data = j->data;
			j = j->next;
		}
		k->next = p;
		k = p;
	}
	while(i)
	{
		p = new LNode;
		p->next = NULL;
		p->data = i->data;
		i = i->next;
		k->next = p;
		k = p;
	}
	while(j)
	{
		p = new LNode;
		p->next = NULL;
		p->data = j->data;
		j = j->next;
		k->next = p;
		k = p;
	}
	return 1;
}

int output(LinkList &L)
{
	LinkList p = L->next;
	if(!p)
	{
		return 0;;
	}
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return 1;
}

int main()
{
	LinkList A,B,C;
	int n,m;
	scanf("%d",&n);
	creat(A,n);
	printf("List A:");
	output(A);
	scanf("%d",&m);
	creat(B,m);
	printf("List B:");
	output(B);
	merge(A,B,C);
	printf("List C:");
	output(C);
}
