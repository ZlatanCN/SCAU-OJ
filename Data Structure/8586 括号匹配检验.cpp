typedef char SElemType; // ����ջԪ������Ϊ�ַ�����
#include"malloc.h"
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // ����״̬���ͣ���������ֵΪStatus���ͣ���ֵ�Ǻ������״̬���룬��OK��
#define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������
#define STACKINCREMENT 2 // �洢�ռ��������

struct SqStack
{
	SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType *top; // ջ��ָ��
	int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

Status InitStack(SqStack &S) // ��ʼ��ջ
{
	S.base = new SElemType[STACK_INIT_SIZE]; // ��̬�����ʼ�ռ�
	if(!S.base) // �ڴ����ʧ��
	{
		return 0; // ����ERROR
	}
	S.top = S.base; // ջ��ָ��ָ��ջ��
	S.stacksize = STACK_INIT_SIZE; // ��ǰ�ѷ���Ŀռ�Ϊ��ʼ�ռ�
	return 1; // ����OK
}

Status StackEmpty(SqStack S) // �ж�ջ�Ƿ�Ϊ��
{
	if(S.top == S.base) // ջ��ָ�����ջ��ָ�룬˵��ջΪ��
	{
		return 1; // ����TRUE
	}
	else
	{
		return 0; // ����FALSE
	}
}

Status Push(SqStack &S,SElemType e) // Ԫ��e��ջ
{
	if(S.top - S.base >= S.stacksize) // ջ������Ҫ���·���ռ�
	{
		S.base = new SElemType[STACK_INIT_SIZE + STACKINCREMENT]; // ��̬�������ռ�
		if(!S.base) // �ڴ����ʧ��
		{
			return 0; // ����ERROR
		}
		S.top = S.base + S.stacksize; // ջ��ָ��ָ���¿ռ��λ��
		S.stacksize += STACKINCREMENT; // ��ǰ�ѷ���Ŀռ�����
	}
	*S.top = e; // ��Ԫ��e����ջ��λ��
	S.top++; // ջ��ָ�������ƶ�һ��λ��
	return 1; // ����OK
}

Status Pop(SqStack &S,SElemType &e) // Ԫ�س�ջ
{
	if(S.top == S.base) // ջΪ��
	{
		return 0; // ����ERROR
	}
	S.top--; // ջ��ָ�������ƶ�һ��λ��
	e = *S.top; // ȡ��ջ��Ԫ��
	return 1; // ����OK
}

void check() // ����ƥ���麯��
{
	SqStack s; // ����һ��ջ
	SElemType ch[80],*p,e; // �����ַ������ָ�룬�Լ�һ��Ԫ��e
	if(InitStack(s)) // ��ʼ��ջ�ɹ�
	{
		//printf("��������ʽ\n");
		fgets(ch, 79, stdin); // �ӱ�׼�����ж����ַ�����������79���ַ�
		p=ch; // ָ��pָ���ַ�����ͷ
		while(*p) // û����β
			switch(*p) // �����ַ����ͽ��з��ദ��
			{
			case '(':
			case '[':
				Push(s, *p); // ��������ջ
				p++; // ָ������ƶ�
				break;
			case ')':
			case ']':
				if(!StackEmpty(s)) // ջ����
				{
					Pop(s, e); // ����ջ��Ԫ��
					if(*p == ')' && e != '(' || *p == ']' && e != '[') // ������ջ��Ԫ����*p�����
					{
						printf("isn't matched pairs\n");
						exit(ERROR); // �����˳�����
					}
					else
					{
						p++; // ָ������ƶ�
						break; // ����switch���
					}
				}
				else // ջ��
				{
					printf("lack of left parenthesis\n");
					exit(ERROR); // �����˳�����
				}
			default:
				p++; // �����ַ�������ָ������ƶ�
			}
		if(StackEmpty(s)) // �ַ�������ʱջ��
			printf("matching\n");
		else
			printf("lack of right parenthesis\n");
	}
}
int main()
{
	check(); // ��������ƥ���麯��
}
