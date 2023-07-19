#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int QElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)

typedef struct
{
	QElemType *base; // 初始化的动态分配存储空间
	int front; // 头指针,若队列不空,指向队列头元素
	int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
} SqQueue;

Status InitQueue(SqQueue &Q)
{
	// 构造一个空队列Q，该队列预定义大小为MAXQSIZE
	Q.base = new QElemType[MAXQSIZE]; // 动态分配存储空间
	if(!Q.base) // 存储分配失败
	{
		return ERROR;
	}
	Q.rear = Q.front = 0; // 队头、队尾指针置为0，表示空队列
	return OK;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
	// 插入元素e为Q的新的队尾元素
	if((Q.rear + 1) % MAXQSIZE == Q.front) // 队列满
	{
		return ERROR;
	}
	Q.base[Q.rear] = e; // 新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; // 队尾指针加1
	return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
	// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
	if(Q.rear == Q.front) // 队列空
	{
		return ERROR;
	}
	e = Q.base[Q.front]; // 将队头元素赋值给e
	Q.front = (Q.front + 1) % MAXQSIZE; // 队头指针加1
	return OK;
}

Status GetHead(SqQueue Q, QElemType &e)
{
	// 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
	if(Q.rear == Q.front) // 队列空
	{
		return ERROR;
	}
	e = Q.base[Q.front]; // 将队头元素赋值给e
	return OK;
}

int QueueLength(SqQueue Q)
{
	// 返回Q的元素个数
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE; // 队列长度为队尾指针减去队头指针再加上队列长度，对MAXQSIZE取模防止越界
}

Status QueueTraverse(SqQueue Q)
{
	// 若队列不空，则从队头到队尾依次输出各个队列元素，并返回OK；否则返回ERROR.
	int i;
	i = Q.front; // 从队头开始遍历
	if(Q.front == Q.rear) // 队列空
	{
		printf("The Queue is Empty!");
	}
	else
	{
		printf("The Queue is: ");
		while(i != Q.rear) // 遍历队列
		{
			printf("%d ",Q.base[i]);
			i = (i + 1) % MAXQSIZE; // 队列循环，对MAXQSIZE取模
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
	if(InitQueue(S)) // 判断队列是否创建成功
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
			if(!EnQueue(S, x)) // 判断入队是否合法
			{
				printf("Enter Error!\n");
			}
			else
			{
				printf("The Element %d is Successfully Entered!\n", x);
			}
			break;
		case 2:
			if(!DeQueue(S, e)) // 判断出队是否合法
			{
				printf("Delete Error!\n");
			}
			else
			{
				printf("The Element %d is Successfully Deleted!\n", e);
			}
			break;
		case 3:
			if(!GetHead(S, e)) // 判断Get Head是否合法
			{
				printf("Get Head Error!\n");
			}
			else
			{
				printf("The Head of the Queue is %d!\n", e);
			}
			break;
		case 4:
			printf("The Length of the Queue is %d!\n",QueueLength(S)); // 返回队列长度
			break;
		case 5:
			QueueTraverse(S); // 遍历队列
			break;
		case 0:
			return 1; // 退出程序
		}
	}
}

