#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100 // ���Ա�ĳ�ʼ����洢�ռ�
#define LISTINCREMENT 10   // ���Ա�洢�ռ������
#define ElemType int       // ���Ա�洢����������

// ����˳���Ľṹ��
typedef struct
{
	int *elem;  // �洢�ռ�Ļ���ַ
	int length; // ��ǰԪ�ظ���
	int listsize; // ��ǰ�洢�ռ��С����sizeof(ElemType)Ϊ��λ��
} SqList;

// ��ʼ��˳���
int InitList_Sq(SqList &L)
{
	// �㷨2.3������һ���յ����Ա�L�������Ա�Ԥ�����СΪLIST_INIT_SIZE
	// �벹ȫ����
	L.elem = new ElemType[LIST_INIT_SIZE]; // ����洢�ռ�
	if(!L.elem) // ����ʧ��
	{
		return 0;
	}
	L.length = 0; // ��ʼ����ǰԪ�ظ���Ϊ0
	L.listsize = LIST_INIT_SIZE; // ��ʼ���洢�ռ��СΪLIST_INIT_SIZE
	return 1; // ��ʼ���ɹ�
}

// ���˳����е�����Ԫ��
int Load_Sq(SqList &L)
{
	int i;
	if(L.length == 0) printf("The List is empty!"); // ���Ա�Ϊ��
	else
	{
		printf("The List is: ");
		for(i = 0; i < L.length; i++) printf("%d ",L.elem[i]); // ���ÿ��Ԫ��
	}
	printf("\n");
	return OK;
}

// ��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
int ListInsert_Sq(SqList &L,int i,int e)
{
	// �㷨2.4����˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
	// i�ĺϷ�ֵΪ1��i��L.length +1
	// �벹ȫ����
	if(i < 1 || i > L.length + 1) // �ж�i�Ƿ�Ϸ�
	{
		return 0;
	}
	for(int j = L.length - 1; j >= i - 1; j--) // ����i��λ��֮���Ԫ�ض������ƶ�һλ���ڳ�λ�ò�����Ԫ��
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e; // ����Ԫ�ز��뵽��i��λ��
	L.length++; // ��ǰԪ�ظ�����1
	return 1; // ����ɹ�
}

// ��˳�����Ա�L��ɾ����i��λ�õ�Ԫ�أ�����e������ֵ
int ListDelete_Sq(SqList &L,int i, int &e)
{
	// �㷨2.5,��˳�����Ա�L��ɾ����i��λ�õ�Ԫ�أ�����e������ֵ
	// i�ĺϷ�ֵΪ1��i��L.length
	// �벹ȫ����
	if(i < 1 || i > L.length) // �ж�i�Ƿ�Ϸ�
	{
		return 0;
	}
	e = L.elem[i - 1]; // ��e���ر�ɾ����Ԫ�ص�ֵ
	for(int j = i - 1; j < L.length - 1; j++) // ����i��λ��֮���Ԫ�ض���ǰ�ƶ�һλ�����ǵ���ɾ����Ԫ��
	{
		L.elem[j] = L.elem[j + 1];
	}
	L.length--; // ��ǰԪ�ظ�����1
	return 1; // ɾ���ɹ�
}

int main()
{
	SqList T;
	int a, i;
	ElemType e, x;
	if(InitList_Sq(T))    // �ж�˳����Ƿ񴴽��ɹ�
	{
		printf("A Sequence List Has Created.\n");
	}
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
		case 1:
			scanf("%d%d",&i,&x);
			if(!ListInsert_Sq(T, i, x)) printf("Insert Error!\n"); // ִ�в��뺯�������ݷ���ֵ�ж�iֵ�Ƿ�Ϸ�
			else printf("The Element %d is Successfully Inserted!\n", x);
			break;
		case 2:
			scanf("%d",&i);
			if(!ListDelete_Sq(T, i, e)) printf("Delete Error!\n"); // ִ��ɾ�����������ݷ���ֵ�ж�iֵ�Ƿ�Ϸ�
			else printf("The Element %d is Successfully Deleted!\n", e);
			break;
		case 3:
			Load_Sq(T);
			break;
		case 0:
			return 1;
		}
	}
}

