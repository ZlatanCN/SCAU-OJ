#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int // 定义数据类型为int型

typedef struct LNode // 定义链表结点
{
	int data; // 数据域
	int length = 0; // 链表长度
	struct LNode *next; // 指向下一个结点的指针
} LNode, *LinkList;

int CreateLink_L(LinkList &L, int n)
{
	// 创建含有n个元素的单链表
	LinkList p, q;
	int i;
	ElemType e;
	L = new LNode; // 创建头结点
	L->next = NULL; // 先建立一个带头结点的单链表
	q = L;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &e); // 输入元素的值
		p = new LNode; // 生成新结点
		p->data = e; // 将输入的值存储到结点中
		p->next = NULL; // 新结点的next指针指向NULL
		q->next = p; // 将新结点插入到链表的尾部
		q = q->next; // 将q指向链表的尾部
		L->length++; // 链表长度加1
	}
	return OK;
}

int LoadLink_L(LinkList &L)
{
	// 单链表遍历
	LinkList p = L->next;
	if (p == NULL) // 如果链表为空
	{
		printf("The List is empty!");
	}
	else
	{
		printf("The LinkList is:");
		while (p) // 遍历链表
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
	// 在带头结点的单链线性表L中第i个位置之前插入元素e
	LinkList p, q;
	q = L;
	if (!q || i > L->length + 1 || i < 1) // 如果链表为空或者i的值不合法
	{
		return 0;
	}
	p = new LNode; // 创建新结点
	p->data = e; // 将插入元素的值存储到新结点中
	while (i - 1)
	{
		q = q->next; // 定位到第i个结点的前一个结点
		i--;
	}
	p->next = q->next; // 将新结点插入到链表中
	q->next = p;
	L->length++; // 链表长度加1
	return 1;
}

int LinkDelete_L(LinkList &L, int i, ElemType &e)
{
	// 在带头结点的单链线性表L中，删除第i个元素，并用e返回其值
	LinkList p = L;
	if (!p || i > L->length || i < 1) // 如果链表为空或者i的值不合法
	{
		return 0;
	}
	while (i - 1)
	{
		p = p->next; // 定位到第i个结点的前一个结点
		i--;
	}
	LinkList q = p->next; // 将要删除的结点指针存储到q中
	e = q->data; // 将要删除的结点的值存储到e中
	p->next = q->next; // 将要删除的结点从链表中删除
	free(q); // 释放要删除的结点的内存空间
	L->length--; // 链表长度减1
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
	if (CreateLink_L(T, n)) // 判断链表是否创建成功
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
			if (!LinkInsert_L(T, i, x)) // 判断i值是否合法
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
			if (!LinkDelete_L(T, i, e)) // 判断i值是否合法
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

