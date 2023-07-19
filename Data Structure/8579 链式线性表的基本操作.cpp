#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int // ������������Ϊint��

typedef struct LNode // ����������
{
	int data; // ������
	int length = 0; // ������
	struct LNode *next; // ָ����һ������ָ��
} LNode, *LinkList;

int CreateLink_L(LinkList &L, int n)
{
	// ��������n��Ԫ�صĵ�����
	LinkList p, q;
	int i;
	ElemType e;
	L = new LNode; // ����ͷ���
	L->next = NULL; // �Ƚ���һ����ͷ���ĵ�����
	q = L;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &e); // ����Ԫ�ص�ֵ
		p = new LNode; // �����½��
		p->data = e; // �������ֵ�洢�������
		p->next = NULL; // �½���nextָ��ָ��NULL
		q->next = p; // ���½����뵽�����β��
		q = q->next; // ��qָ�������β��
		L->length++; // �����ȼ�1
	}
	return OK;
}

int LoadLink_L(LinkList &L)
{
	// ���������
	LinkList p = L->next;
	if (p == NULL) // �������Ϊ��
	{
		printf("The List is empty!");
	}
	else
	{
		printf("The LinkList is:");
		while (p) // ��������
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}
	printf("\n");
	return OK;
}

int LinkInsert_L(LinkList &L, int i, ElemType e)
{
	// �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
	LinkList p, q;
	q = L;
	if (!q || i > L->length + 1 || i < 1) // �������Ϊ�ջ���i��ֵ���Ϸ�
	{
		return 0;
	}
	p = new LNode; // �����½��
	p->data = e; // ������Ԫ�ص�ֵ�洢���½����
	while (i - 1)
	{
		q = q->next; // ��λ����i������ǰһ�����
		i--;
	}
	p->next = q->next; // ���½����뵽������
	q->next = p;
	L->length++; // �����ȼ�1
	return 1;
}

int LinkDelete_L(LinkList &L, int i, ElemType &e)
{
	// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
	LinkList p = L;
	if (!p || i > L->length || i < 1) // �������Ϊ�ջ���i��ֵ���Ϸ�
	{
		return 0;
	}
	while (i - 1)
	{
		p = p->next; // ��λ����i������ǰһ�����
		i--;
	}
	LinkList q = p->next; // ��Ҫɾ���Ľ��ָ��洢��q��
	e = q->data; // ��Ҫɾ���Ľ���ֵ�洢��e��
	p->next = q->next; // ��Ҫɾ���Ľ���������ɾ��
	free(q); // �ͷ�Ҫɾ���Ľ����ڴ�ռ�
	L->length--; // �����ȼ�1
	return 1;
}

int main()
{
	LinkList T;
	int a, n, i;
	ElemType x, e;
	printf("Please input the init size of the linklist:\n");
	scanf("%d", &n);
	printf("Please input the %d element of the linklist:\n", n);
	if (CreateLink_L(T, n)) // �ж������Ƿ񴴽��ɹ�
	{
		printf("A Link List Has Created.\n");
		LoadLink_L(T);
	}
	while (1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			scanf("%d%d", &i, &x);
			if (!LinkInsert_L(T, i, x)) // �ж�iֵ�Ƿ�Ϸ�
			{
				printf("Insert Error!\n");
			}
			else
			{
				printf("The Element %d is Successfully Inserted!\n", x);
			}
			break;
		case 2:
			scanf("%d", &i);
			if (!LinkDelete_L(T, i, e)) // �ж�iֵ�Ƿ�Ϸ�
			{
				printf("Delete Error!\n");
			}
			else
			{
				printf("The Element %d is Successfully Deleted!\n", e);
			}
			break;
		case 3:
			LoadLink_L(T);
			break;
		case 0:
			return 1;
		}
	}
}

