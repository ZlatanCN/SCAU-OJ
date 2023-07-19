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


Status ListInsert_L(LinkList &L, int i, ElemType e)    // �㷨2.9
{
	// �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
	LinkList p,s;
	p = L;
	int j = 0;
	while (p && j < i-1)    // Ѱ�ҵ�i-1�����
	{
		p = p->next;
		++j;
	}
	if (!p || j > i-1) return ERROR;      // iС��1���ߴ��ڱ�
	s = (LinkList)malloc(sizeof(LNode));  // �����½��
	s->data = e;
	s->next = p->next;      // ����L��
	p->next = s;
	return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e)    // �㷨2.10
{
	// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
	LinkList p,q;
	p = L;
	int j = 0;
	while (p->next && j < i-1)    // Ѱ�ҵ�i����㣬����pָ����ǰ��
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i-1) return ERROR;  // ɾ��λ�ò�����
	q = p->next;
	p->next = q->next;           // ɾ�����ͷŽ��
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
