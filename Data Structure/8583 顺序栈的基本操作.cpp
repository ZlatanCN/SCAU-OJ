#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
	SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
	SElemType *top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)
{
	// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
	// 功能：初始化栈
	S.base = new SElemType[STACK_INIT_SIZE]; // 动态分配存储空间
	if(!S.base) // 如果存储空间分配失败
	{
		return ERROR;
	}
	S.top = S.base; // 栈顶指针指向栈底
	S.stacksize = STACK_INIT_SIZE; // 栈的存储空间大小为STACK_INIT_SIZE
	return OK;
}

Status Push(SqStack &S,SElemType e)
{
	// 在栈S中插入元素e为新的栈顶元素
	// 功能：压栈
	if(S.top - S.base >= S.stacksize) // 如果栈满，即已经超过了存储空间大小
	{
		S.base = (SElemType*)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType)); // 动态分配新的存储空间
		if(!S.base) // 如果新的存储空间分配失败
		{
			return ERROR;
		}
		S.top = S.base + S.stacksize; // 栈顶指针指向栈的末尾
		S.stacksize += STACKINCREMENT; // 栈的存储空间大小增加STACKINCREMENT个元素
	}
	*S.top = e; // 将元素e压入栈顶
	S.top++; // 栈顶指针加1
	return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	// 功能：弹栈
	if(S.top == S.base) // 如果栈为空
	{
		return ERROR;
	}
	S.top--; // 栈顶指针减1
	e = *S.top; // 取出栈顶元素
	return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
	// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	// 功能：获取栈顶元素
	if(S.top == S.base) // 如果栈为空
	{
		return ERROR;
	}
	S.top--; // 栈顶指针减1
	e = *S.top; // 取出栈顶元素
	S.top++; // 栈顶指针加1
	return OK;
}

int StackLength(SqStack S)
{
	// 返回栈S的元素个数
	// 功能：求栈的长度
	return S.top - S.base; // 栈的长度就是栈顶指针减去栈底指针
}

Status StackTraverse(SqStack S)
{
	// 从栈顶到栈底依次输出栈中的每个元素
	// 功能：遍历栈
	SElemType *p = S.top; // 从栈顶开始遍历
	if(S.top == S.base) // 如果栈为空
	{
		printf("The Stack is Empty!"); // 输出提示信息
	}
	else
	{
		printf("The Stack is: ");
		while(p != S.base) // 如果栈不为空
		{
			p--; // 栈顶指针减1
			printf("%d ", *p); // 输出栈顶元素
		}
	}
	printf("\n");
	return OK;
}

int main()
{
	int a;
	SqStack S;
	SElemType x, e;
	if(InitStack(S)) // 如果栈创建成功
	{
		printf("A Stack Has Created.\n");
	}
	while(1)
	{
		printf("1:Push \n2:Pop \n3:Get the Top \n4:Return the Length of the Stack\n5:Load the Stack\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				scanf("%d", &x);
				if(!Push(S, x)) // 如果压栈失败
				{
					printf("Push Error!\n");
				}
				else
				{
					printf("The Element %d is Successfully Pushed!\n", x);
				}
				break;
			case 2:
				if(!Pop(S, e)) // 如果弹栈失败
				{
					printf("Pop Error!\n");
				}
				else
				{
					printf("The Element %d is Successfully Poped!\n", e);
				}
				break;
			case 3:
				if(!GetTop(S, e)) // 如果获取栈顶元素失败
				{
					printf("Get Top Error!\n");
				}
				else
				{
					printf("The Top Element is %d!\n", e);
				}
				break;
			case 4:
				printf("The Length of the Stack is %d!\n",StackLength(S)); // 输出栈的长度
				break;
			case 5:
				StackTraverse(S); // 遍历栈
				break;
			case 0:
				return 1;
		}
	}
}

