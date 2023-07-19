#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int QElemType;
#define MAXQSIZE 100 // �����г���(����ѭ�����У������г���Ҫ��1)

typedef struct
{
	QElemType *base; // ��ʼ���Ķ�̬����洢�ռ�
	int front; // ͷָ��,�����в���,ָ�����ͷԪ��
	int rear; // βָ��,�����в���,ָ�����βԪ�ص���һ��λ��
} SqQueue;

Status InitQueue(SqQueue &Q)
{
	// ����һ���ն���Q���ö���Ԥ�����СΪMAXQSIZE
	Q.base = new QElemType[MAXQSIZE]; // ��̬����洢�ռ�
	if(!Q.base) // �洢����ʧ��
	{
		return ERROR;
	}
	Q.rear = Q.front = 0; // ��ͷ����βָ����Ϊ0����ʾ�ն���
	return OK;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
	// ����Ԫ��eΪQ���µĶ�βԪ��
	if((Q.rear + 1) % MAXQSIZE == Q.front) // ������
	{
		return ERROR;
	}
	Q.base[Q.rear] = e; // ��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MAXQSIZE; // ��βָ���1
	return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
	// �����в���, ��ɾ��Q�Ķ�ͷԪ��, ��e������ֵ, ������OK; ���򷵻�ERROR
	if(Q.rear == Q.front) // ���п�
	{
		return ERROR;
	}
	e = Q.base[Q.front]; // ����ͷԪ�ظ�ֵ��e
	Q.front = (Q.front + 1) % MAXQSIZE; // ��ͷָ���1
	return OK;
}

Status GetHead(SqQueue Q, QElemType &e)
{
	// �����в��գ�����e���ض�ͷԪ�أ�������OK�����򷵻�ERROR
	if(Q.rear == Q.front) // ���п�
	{
		return ERROR;
	}
	e = Q.base[Q.front]; // ����ͷԪ�ظ�ֵ��e
	return OK;
}

int QueueLength(SqQueue Q)
{
	// ����Q��Ԫ�ظ���
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE; // ���г���Ϊ��βָ���ȥ��ͷָ���ټ��϶��г��ȣ���MAXQSIZEȡģ��ֹԽ��
}

Status QueueTraverse(SqQueue Q)
{
	// �����в��գ���Ӷ�ͷ����β���������������Ԫ�أ�������OK�����򷵻�ERROR.
	int i;
	i = Q.front; // �Ӷ�ͷ��ʼ����
	if(Q.front == Q.rear) // ���п�
	{
		printf("The Queue is Empty!");
	}
	else
	{
		printf("The Queue is: ");
		while(i != Q.rear) // ��������
		{
			printf("%d ",Q.base[i]);
			i = (i + 1) % MAXQSIZE; // ����ѭ������MAXQSIZEȡģ
		}
	}
	printf("\n");
	return OK;
}

int main()
{
	int a;
	SqQueue S;
	QElemType x, e;
	if(InitQueue(S)) // �ж϶����Ƿ񴴽��ɹ�
	{
		printf("A Queue Has Created.\n");
	}
	while(1)
	{
		printf("1:Enter \n2:Delete \n3:Get the Front \n4:Return the Length of the Queue\n5:Load the Queue\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
		case 1:
			scanf("%d", &x);
			if(!EnQueue(S, x)) // �ж�����Ƿ�Ϸ�
			{
				printf("Enter Error!\n");
			}
			else
			{
				printf("The Element %d is Successfully Entered!\n", x);
			}
			break;
		case 2:
			if(!DeQueue(S, e)) // �жϳ����Ƿ�Ϸ�
			{
				printf("Delete Error!\n");
			}
			else
			{
				printf("The Element %d is Successfully Deleted!\n", e);
			}
			break;
		case 3:
			if(!GetHead(S, e)) // �ж�Get Head�Ƿ�Ϸ�
			{
				printf("Get Head Error!\n");
			}
			else
			{
				printf("The Head of the Queue is %d!\n", e);
			}
			break;
		case 4:
			printf("The Length of the Queue is %d!\n",QueueLength(S)); // ���ض��г���
			break;
		case 5:
			QueueTraverse(S); // ��������
			break;
		case 0:
			return 1; // �˳�����
		}
	}
}

