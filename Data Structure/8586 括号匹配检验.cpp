typedef char SElemType; // 定义栈元素类型为字符类型
#include"malloc.h"
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // 定义状态类型，函数返回值为Status类型，其值是函数结果状态代码，如OK等
#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACKINCREMENT 2 // 存储空间分配增量

struct SqStack
{
	SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
	SElemType *top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S) // 初始化栈
{
	S.base = new SElemType[STACK_INIT_SIZE]; // 动态分配初始空间
	if(!S.base) // 内存分配失败
	{
		return 0; // 返回ERROR
	}
	S.top = S.base; // 栈顶指针指向栈底
	S.stacksize = STACK_INIT_SIZE; // 当前已分配的空间为初始空间
	return 1; // 返回OK
}

Status StackEmpty(SqStack S) // 判断栈是否为空
{
	if(S.top == S.base) // 栈顶指针等于栈底指针，说明栈为空
	{
		return 1; // 返回TRUE
	}
	else
	{
		return 0; // 返回FALSE
	}
}

Status Push(SqStack &S,SElemType e) // 元素e入栈
{
	if(S.top - S.base >= S.stacksize) // 栈满，需要重新分配空间
	{
		S.base = new SElemType[STACK_INIT_SIZE + STACKINCREMENT]; // 动态分配更多空间
		if(!S.base) // 内存分配失败
		{
			return 0; // 返回ERROR
		}
		S.top = S.base + S.stacksize; // 栈顶指针指向新空间的位置
		S.stacksize += STACKINCREMENT; // 当前已分配的空间增加
	}
	*S.top = e; // 将元素e放入栈顶位置
	S.top++; // 栈顶指针向上移动一个位置
	return 1; // 返回OK
}

Status Pop(SqStack &S,SElemType &e) // 元素出栈
{
	if(S.top == S.base) // 栈为空
	{
		return 0; // 返回ERROR
	}
	S.top--; // 栈顶指针向下移动一个位置
	e = *S.top; // 取出栈顶元素
	return 1; // 返回OK
}

void check() // 括号匹配检查函数
{
	SqStack s; // 定义一个栈
	SElemType ch[80],*p,e; // 定义字符数组和指针，以及一个元素e
	if(InitStack(s)) // 初始化栈成功
	{
		//printf("请输入表达式\n");
		fgets(ch, 79, stdin); // 从标准输入中读入字符串，最多读入79个字符
		p=ch; // 指针p指向字符串开头
		while(*p) // 没到串尾
			switch(*p) // 根据字符类型进行分类处理
			{
			case '(':
			case '[':
				Push(s, *p); // 左括号入栈
				p++; // 指针向后移动
				break;
			case ')':
			case ']':
				if(!StackEmpty(s)) // 栈不空
				{
					Pop(s, e); // 弹出栈顶元素
					if(*p == ')' && e != '(' || *p == ']' && e != '[') // 弹出的栈顶元素与*p不配对
					{
						printf("isn't matched pairs\n");
						exit(ERROR); // 立即退出程序
					}
					else
					{
						p++; // 指针向后移动
						break; // 跳出switch语句
					}
				}
				else // 栈空
				{
					printf("lack of left parenthesis\n");
					exit(ERROR); // 立即退出程序
				}
			default:
				p++; // 其它字符不处理，指针向后移动
			}
		if(StackEmpty(s)) // 字符串结束时栈空
			printf("matching\n");
		else
			printf("lack of right parenthesis\n");
	}
}
int main()
{
	check(); // 调用括号匹配检查函数
}
