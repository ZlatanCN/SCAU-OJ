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
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) return ERROR;
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack &S,SElemType e)
{
	// 在栈S中插入元素e为新的栈顶元素
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) return ERROR;
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
	// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S.top==S.base) return ERROR;
	e=*(S.top-1);
	return OK;
}

int StackLength(SqStack S)
{
	// 返回栈S的元素个数
	int i;
	i=S.top-S.base;
	return i;
}

Status StackTraverse(SqStack S)
{
	// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p = (SElemType *)malloc(sizeof(SElemType));
	p = S.top;
	if(S.top==S.base)printf("The Stack is Empty!");
	else
	{
		printf("The Stack is: ");
		p--;
		while(p>=S.base)
		{
			printf("%d ", *p);
			p--;
		}
	}
	printf("\n");
	return OK;
}

char OperatorPriority(char op1, char op2)
{
	char cpr;
	switch(op1)
	{
		case '+':
		case '-':
			switch(op2)
			{
				case '*':
				case '/':
				case '(':
					cpr = '<';
					break;
				default:
					cpr = '>';
					break;
			}
			break;
		case '*':
		case '/':
			switch(op2)
			{
				case '(':
					cpr = '<';
					break;
				default:
					cpr = '>';
					break;
			}
			break;
		case '(':
			switch(op2)
			{
				case ')':
					cpr = '=';
					break;
				default:
					cpr = '<';
					break;
			}
			break;
		case ')':
			cpr = '>';
			break;
		default:
			cpr = 0;
			break;
	}
	return cpr;
}

int main()
{
	SqStack oprt, num; // 运算符栈和数字栈
	InitStack(oprt); // 初始化运算符栈
	InitStack(num); // 初始化数字栈
	char ch[100];
	gets(ch);
	for(int i = 0; ch[i] != '\0'; i++)
	{
		int n = 0;
		if(ch[i] >= '0' && ch[i] <= '9') // 判断是否为数字
		{
			while(ch[i] >= '0' && ch[i] <= '9') // 如果是数字，将其转换为整数
			{
				n = n * 10 + (ch[i] - '0');
				i++;
			}
			Push(num, n); // 将整数入数字栈
		}
		if(ch[i] < '0' || ch[i] > '9') // 判断是否为运算符
		{
			if(StackLength(oprt) == 0) // 如果运算符栈为空，直接将运算符入栈
			{
				Push(oprt, ch[i]);
				continue;
			}
			else // 如果运算符栈不为空
			{
				int e;
				GetTop(oprt, e); // 获取运算符栈的栈顶元素
				if(OperatorPriority(e, ch[i]) == '<') // 如果当前运算符优先级大于栈顶元素
				{
					Push(oprt, ch[i]); // 将当前运算符入栈
				}
				else if(OperatorPriority(e, ch[i]) == '=' && ch[i] == ')') // 如果当前运算符为右括号，且栈顶元素为左括号
				{
					int t;
					Pop(oprt, t); // 弹出左括号
				}
				else if(OperatorPriority(e, ch[i]) == '>') // 如果当前运算符优先级小于等于栈顶元素
				{
					int n1, n2, n3, op; // 定义三个数和运算符
					Pop(num, n2); // 从数字栈中取出两个数
					Pop(num, n1);
					Pop(oprt, op); // 从运算符栈中取出一个运算符
					if(op == '+') // 根据运算符进行计算
					{
						n3 = n1 + n2;
					}
					else if(op == '-')
					{
						n3 = n1 - n2;
					}
					else if(op == '*')
					{
						n3 = n1 * n2;
					}
					else if(op == '/')
					{
						n3 = n1 / n2;
					}
					Push(num, n3); // 将计算结果入数字栈
					if(*(oprt.top - 1) == '(') // 如果运算符栈的栈顶元素为左括号
					{
						int go;
						Pop(oprt, go); // 弹出左括号
					}
					else if(oprt.top == oprt.base) // 如果运算符栈已经为空
					{
						Push(oprt, ch[i]); // 直接将当前运算符入栈
					}
				}
			}
		}
	}
	if(StackLength(num) > 1) // 如果数字栈中还剩下两个以上的数
	{
		int n1, n2, n3, op;
		Pop(num, n2); // 从数字栈中取出两个数
		Pop(num, n1);
		Pop(oprt, op); // 从运算符栈中取出一个运算符
		if(op == '+') // 根据运算符进行计算
		{
			n3 = n1 + n2;
		}
		else if(op == '-')
		{
			n3 = n1 - n2;
		}
		else if(op == '*')
		{
			n3 = n1 * n2;
		}
		else if(op == '/')
		{
			n3 = n1 / n2;
		}
		Push(num, n3); // 将计算结果入数字栈
	}
	int result; // 定义最终计算结果
	GetTop(num, result); // 从数字栈中取出最终结果
	printf("%d", result); // 输出最终结果
}
