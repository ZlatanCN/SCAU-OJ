// ����ջ��Ԫ�ص�����Ϊ�ַ���
typedef char SElemType;
#include"malloc.h"
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // ���庯������ֵ����
#define STACK_INIT_SIZE 10 // ����ջ�ĳ�ʼ�洢�ռ��С
#define STACKINCREMENT 2 // ����ջ�Ĵ洢�ռ�����
struct SqStack
{
	SElemType *base; // ջ��ָ�룬��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType *top; // ջ��ָ��
	int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ����˳��ջ

Status InitStack(SqStack &S)
{
	// ����һ����ջS
	S.base = new SElemType[STACK_INIT_SIZE]; // ��̬����洢�ռ�
	if (!S.base) // ����ʧ��
	{
		return ERROR;
	}
	S.top = S.base; // ��ջ��ջ��ָ���ջ��ָ����ͬ
	S.stacksize = STACK_INIT_SIZE; // ջ�ĳ�ʼ�洢�ռ��С
	return OK;
}

Status StackEmpty(SqStack S)
{
	// �ж�ջ�Ƿ�Ϊ��
	if (S.top == S.base) // ջΪ��
	{
		return TRUE;
	}
	else // ջ��Ϊ��
	{
		return FALSE;
	}
}

Status ClearStack(SqStack &S)
{
	// ��ջ���
	S.top = S.base; // ֱ�ӽ�ջ��ָ����Ϊջ��ָ��
	return OK;
}

Status DestroyStack(SqStack &S)
{
	// ����ջ
	free(S.base); // �ͷ�ջ�Ĵ洢�ռ�
	S.base = NULL; // ��ջ��ָ����Ϊ��
	S.top = NULL; // ��ջ��ָ����Ϊ��
	S.stacksize = 0; // ��ջ�Ĵ洢�ռ��С��Ϊ0
	return OK;
}

Status Push(SqStack &S, SElemType e)
{
	// ��Ԫ��e��ջ
	if (S.top - S.base >= S.stacksize) // ջ��������Ҫ����洢�ռ�
	{
		S.base = (SElemType*)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType)); // ���·���洢�ռ�
		if (!S.base) // ����ʧ��
		{
			return ERROR;
		}
		S.top = S.base + S.stacksize; // ջ��ָ��ָ���¿ռ��ջ��λ��
		S.stacksize += STACKINCREMENT; // ����ջ�Ĵ洢�ռ��С
	}
	*S.top = e; // ��Ԫ��e��ջ
	S.top++; // ջ��ָ���1
	return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
	// ��ջ��Ԫ�ص���ջ��������洢��e��
	if (S.top == S.base) // ջΪ��
	{
		return ERROR;
	}
	S.top--; // ջ��ָ���1
	e = *S.top; // ��ջ��Ԫ�ش洢��e��
	return OK;
}

Status StackTraverse(SqStack S, Status(*visit)(SElemType))
{
	// ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ��
	while (S.top > S.base) // ջ��Ϊ��
	{
		visit(*S.base++); // ��ջ��ÿ��Ԫ�ص��ú���visit()
	}
	printf("\n"); // ������з�
	return OK;
}

Status visit(SElemType c)
{
	// ��ջ��ÿ��Ԫ��ִ�еĲ����������������Ԫ��
	printf("%c", c); // ���Ԫ��
	return OK;
}

void LineEdit()
{
	// �����ַ�ջs�����ն˽���һ�в��������ù��̵����������㷨3.2
	SqStack s; // �����ַ�ջs
	char ch, c;
	int n, i;
	InitStack(s); // ��ʼ��ջs
	scanf("%d", &n); // �������������
	ch = getchar();
	for (i = 1; i <= n; i++) // ����ÿһ������
	{
		ch = getchar(); // ���ն˽���һ���ַ�
		while (ch != '\n') // ������ǻ��з�
		{
			switch (ch)
			{
				case '#':
					Pop(s, c); // ��ջ
					break;
				case '@':
					ClearStack(s); // ��ջ���
					break;
				default:
					Push(s, ch); // ����Ч�ַ���ջ
			}
			ch = getchar(); // ���ն˽�����һ���ַ�
		}
		StackTraverse(s, visit); // ����ջ�׵�ջ����ջ���ַ����
		ClearStack(s); // ����ջΪ��ջ
	}
	DestroyStack(s); // ����ջs
}

int main()
{
	LineEdit(); // ����LineEdit()����
	return 0;
}
