// 定义栈中元素的类型为字符型
typedef char SElemType;
#include"malloc.h"
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // 定义函数返回值类型
#define STACK_INIT_SIZE 10 // 定义栈的初始存储空间大小
#define STACKINCREMENT 2 // 定义栈的存储空间增量
struct SqStack
{
	SElemType *base; // 栈底指针，在栈构造之前和销毁之后，base的值为NULL
	SElemType *top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 定义顺序栈

Status InitStack(SqStack &S)
{
	// 构造一个空栈S
	S.base = new SElemType[STACK_INIT_SIZE]; // 动态分配存储空间
	if (!S.base) // 分配失败
	{
		return ERROR;
	}
	S.top = S.base; // 空栈的栈顶指针和栈底指针相同
	S.stacksize = STACK_INIT_SIZE; // 栈的初始存储空间大小
	return OK;
}

Status StackEmpty(SqStack S)
{
	// 判断栈是否为空
	if (S.top == S.base) // 栈为空
	{
		return TRUE;
	}
	else // 栈不为空
	{
		return FALSE;
	}
}

Status ClearStack(SqStack &S)
{
	// 将栈清空
	S.top = S.base; // 直接将栈顶指针置为栈底指针
	return OK;
}

Status DestroyStack(SqStack &S)
{
	// 销毁栈
	free(S.base); // 释放栈的存储空间
	S.base = NULL; // 将栈底指针置为空
	S.top = NULL; // 将栈顶指针置为空
	S.stacksize = 0; // 将栈的存储空间大小置为0
	return OK;
}

Status Push(SqStack &S, SElemType e)
{
	// 将元素e入栈
	if (S.top - S.base >= S.stacksize) // 栈已满，需要扩充存储空间
	{
		S.base = (SElemType*)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType)); // 重新分配存储空间
		if (!S.base) // 分配失败
		{
			return ERROR;
		}
		S.top = S.base + S.stacksize; // 栈顶指针指向新空间的栈顶位置
		S.stacksize += STACKINCREMENT; // 更新栈的存储空间大小
	}
	*S.top = e; // 将元素e入栈
	S.top++; // 栈顶指针加1
	return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
	// 将栈顶元素弹出栈，并将其存储到e中
	if (S.top == S.base) // 栈为空
	{
		return ERROR;
	}
	S.top--; // 栈顶指针减1
	e = *S.top; // 将栈顶元素存储到e中
	return OK;
}

Status StackTraverse(SqStack S, Status(*visit)(SElemType))
{
	// 从栈底到栈顶依次对栈中每个元素调用函数visit()。一旦visit()失败，则操作失败
	while (S.top > S.base) // 栈不为空
	{
		visit(*S.base++); // 对栈中每个元素调用函数visit()
	}
	printf("\n"); // 输出换行符
	return OK;
}

Status visit(SElemType c)
{
	// 对栈中每个元素执行的操作，本例中是输出元素
	printf("%c", c); // 输出元素
	return OK;
}

void LineEdit()
{
	// 利用字符栈s，从终端接收一行并送至调用过程的数据区。算法3.2
	SqStack s; // 定义字符栈s
	char ch, c;
	int n, i;
	InitStack(s); // 初始化栈s
	scanf("%d", &n); // 接收输入的行数
	ch = getchar();
	for (i = 1; i <= n; i++) // 对于每一行输入
	{
		ch = getchar(); // 从终端接收一个字符
		while (ch != '\n') // 如果不是换行符
		{
			switch (ch)
			{
				case '#':
					Pop(s, c); // 退栈
					break;
				case '@':
					ClearStack(s); // 将栈清空
					break;
				default:
					Push(s, ch); // 将有效字符入栈
			}
			ch = getchar(); // 从终端接收下一个字符
		}
		StackTraverse(s, visit); // 将从栈底到栈顶的栈内字符输出
		ClearStack(s); // 重置栈为空栈
	}
	DestroyStack(s); // 销毁栈s
}

int main()
{
	LineEdit(); // 调用LineEdit()函数
	return 0;
}
