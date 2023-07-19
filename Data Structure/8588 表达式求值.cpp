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
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) return ERROR;
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack &S,SElemType e)
{
	// ��ջS�в���Ԫ��eΪ�µ�ջ��Ԫ��
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
	// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
	// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(S.top==S.base) return ERROR;
	e=*(S.top-1);
	return OK;
}

int StackLength(SqStack S)
{
	// ����ջS��Ԫ�ظ���
	int i;
	i=S.top-S.base;
	return i;
}

Status StackTraverse(SqStack S)
{
	// ��ջ����ջ���������ջ�е�ÿ��Ԫ��
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
	SqStack oprt, num; // �����ջ������ջ
	InitStack(oprt); // ��ʼ�������ջ
	InitStack(num); // ��ʼ������ջ
	char ch[100];
	gets(ch);
	for(int i = 0; ch[i] != '\0'; i++)
	{
		int n = 0;
		if(ch[i] >= '0' && ch[i] <= '9') // �ж��Ƿ�Ϊ����
		{
			while(ch[i] >= '0' && ch[i] <= '9') // ��������֣�����ת��Ϊ����
			{
				n = n * 10 + (ch[i] - '0');
				i++;
			}
			Push(num, n); // ������������ջ
		}
		if(ch[i] < '0' || ch[i] > '9') // �ж��Ƿ�Ϊ�����
		{
			if(StackLength(oprt) == 0) // ��������ջΪ�գ�ֱ�ӽ��������ջ
			{
				Push(oprt, ch[i]);
				continue;
			}
			else // ��������ջ��Ϊ��
			{
				int e;
				GetTop(oprt, e); // ��ȡ�����ջ��ջ��Ԫ��
				if(OperatorPriority(e, ch[i]) == '<') // �����ǰ��������ȼ�����ջ��Ԫ��
				{
					Push(oprt, ch[i]); // ����ǰ�������ջ
				}
				else if(OperatorPriority(e, ch[i]) == '=' && ch[i] == ')') // �����ǰ�����Ϊ�����ţ���ջ��Ԫ��Ϊ������
				{
					int t;
					Pop(oprt, t); // ����������
				}
				else if(OperatorPriority(e, ch[i]) == '>') // �����ǰ��������ȼ�С�ڵ���ջ��Ԫ��
				{
					int n1, n2, n3, op; // �����������������
					Pop(num, n2); // ������ջ��ȡ��������
					Pop(num, n1);
					Pop(oprt, op); // �������ջ��ȡ��һ�������
					if(op == '+') // ������������м���
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
					Push(num, n3); // ��������������ջ
					if(*(oprt.top - 1) == '(') // ��������ջ��ջ��Ԫ��Ϊ������
					{
						int go;
						Pop(oprt, go); // ����������
					}
					else if(oprt.top == oprt.base) // ��������ջ�Ѿ�Ϊ��
					{
						Push(oprt, ch[i]); // ֱ�ӽ���ǰ�������ջ
					}
				}
			}
		}
	}
	if(StackLength(num) > 1) // �������ջ�л�ʣ���������ϵ���
	{
		int n1, n2, n3, op;
		Pop(num, n2); // ������ջ��ȡ��������
		Pop(num, n1);
		Pop(oprt, op); // �������ջ��ȡ��һ�������
		if(op == '+') // ������������м���
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
		Push(num, n3); // ��������������ջ
	}
	int result; // �������ռ�����
	GetTop(num, result); // ������ջ��ȡ�����ս��
	printf("%d", result); // ������ս��
}
