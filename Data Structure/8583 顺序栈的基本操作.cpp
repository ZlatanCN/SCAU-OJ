#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // �洢�ռ��ʼ������
#define STACKINCREMENT 10 // �洢�ռ��������

typedef int SElemType; // ����ջԪ������
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��

struct SqStack
{
	SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType *top; // ջ��ָ��
	int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

Status InitStack(SqStack &S)
{
	// ����һ����ջS����ջԤ�����СΪSTACK_INIT_SIZE
	// ���ܣ���ʼ��ջ
	S.base = new SElemType[STACK_INIT_SIZE]; // ��̬����洢�ռ�
	if(!S.base) // ����洢�ռ����ʧ��
	{
		return ERROR;
	}
	S.top = S.base; // ջ��ָ��ָ��ջ��
	S.stacksize = STACK_INIT_SIZE; // ջ�Ĵ洢�ռ��СΪSTACK_INIT_SIZE
	return OK;
}

Status Push(SqStack &S,SElemType e)
{
	// ��ջS�в���Ԫ��eΪ�µ�ջ��Ԫ��
	// ���ܣ�ѹջ
	if(S.top - S.base >= S.stacksize) // ���ջ�������Ѿ������˴洢�ռ��С
	{
		S.base = (SElemType*)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType)); // ��̬�����µĴ洢�ռ�
		if(!S.base) // ����µĴ洢�ռ����ʧ��
		{
			return ERROR;
		}
		S.top = S.base + S.stacksize; // ջ��ָ��ָ��ջ��ĩβ
		S.stacksize += STACKINCREMENT; // ջ�Ĵ洢�ռ��С����STACKINCREMENT��Ԫ��
	}
	*S.top = e; // ��Ԫ��eѹ��ջ��
	S.top++; // ջ��ָ���1
	return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
	// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	// ���ܣ���ջ
	if(S.top == S.base) // ���ջΪ��
	{
		return ERROR;
	}
	S.top--; // ջ��ָ���1
	e = *S.top; // ȡ��ջ��Ԫ��
	return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
	// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	// ���ܣ���ȡջ��Ԫ��
	if(S.top == S.base) // ���ջΪ��
	{
		return ERROR;
	}
	S.top--; // ջ��ָ���1
	e = *S.top; // ȡ��ջ��Ԫ��
	S.top++; // ջ��ָ���1
	return OK;
}

int StackLength(SqStack S)
{
	// ����ջS��Ԫ�ظ���
	// ���ܣ���ջ�ĳ���
	return S.top - S.base; // ջ�ĳ��Ⱦ���ջ��ָ���ȥջ��ָ��
}

Status StackTraverse(SqStack S)
{
	// ��ջ����ջ���������ջ�е�ÿ��Ԫ��
	// ���ܣ�����ջ
	SElemType *p = S.top; // ��ջ����ʼ����
	if(S.top == S.base) // ���ջΪ��
	{
		printf("The Stack is Empty!"); // �����ʾ��Ϣ
	}
	else
	{
		printf("The Stack is: ");
		while(p != S.base) // ���ջ��Ϊ��
		{
			p--; // ջ��ָ���1
			printf("%d ", *p); // ���ջ��Ԫ��
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
	if(InitStack(S)) // ���ջ�����ɹ�
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
				if(!Push(S, x)) // ���ѹջʧ��
				{
					printf("Push Error!\n");
				}
				else
				{
					printf("The Element %d is Successfully Pushed!\n", x);
				}
				break;
			case 2:
				if(!Pop(S, e)) // �����ջʧ��
				{
					printf("Pop Error!\n");
				}
				else
				{
					printf("The Element %d is Successfully Poped!\n", e);
				}
				break;
			case 3:
				if(!GetTop(S, e)) // �����ȡջ��Ԫ��ʧ��
				{
					printf("Get Top Error!\n");
				}
				else
				{
					printf("The Top Element is %d!\n", e);
				}
				break;
			case 4:
				printf("The Length of the Stack is %d!\n",StackLength(S)); // ���ջ�ĳ���
				break;
			case 5:
				StackTraverse(S); // ����ջ
				break;
			case 0:
				return 1;
		}
	}
}

