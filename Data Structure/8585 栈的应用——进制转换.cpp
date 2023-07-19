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
// �벹ȫ����
	S.base = new SElemType[STACK_INIT_SIZE];
	if(!S.base)
	{
		return ERROR;
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack &S,SElemType e)   
{
// ��ջS�в���Ԫ��eΪ�µ�ջ��Ԫ��
// �벹ȫ����
	if(S.top - S.base >= S.stacksize)
	{
		S.base = new SElemType[STACK_INIT_SIZE + STACKINCREMENT];
		if(!S.base)
		{
			return ERROR;
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
	return OK;
}

Status Pop(SqStack &S,SElemType &e)   
{
// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
// �벹ȫ����
	if(S.top == S.base)
	{
		return ERROR;
	}
	--S.top;
	e = *S.top;
	return OK;
}

Status GetTop(SqStack S,SElemType &e)   
{ 
// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
// �벹ȫ����
	if(S.top == S.base)
	{
		return ERROR;
	}
	--S.top;
	e = *S.top;
	++S.top;
	return OK;
}

int StackLength(SqStack S) 
{
// ����ջS��Ԫ�ظ���
// �벹ȫ����
	return S.top - S.base;
}

Status StackTraverse(SqStack S)
{
// ��ջ����ջ���������ջ�е�ÿ��Ԫ��
	SElemType *p  = S.top;       //�����
	if(S.top == S.base)printf("The Stack is Empty!"); //�����
	else
	{
		/*printf("The Stack is: ");*/
		while(p != S.base)            //�����
		{
			p--;
			printf("%d", *p);
		}
	}
	printf("\n");
	return OK;
}

int main()
{
	int n;
	scanf("%d",&n);
	SqStack S;
	InitStack(S);
	while(n != 0)
	{
		Push(S,n % 8);
		n = n / 8;
	}
	StackTraverse(S);
}
