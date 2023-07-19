#include <iostream>
#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;
using namespace std;

typedef char  ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild,*rchild;//���Һ���ָ��
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T)    // �㷨6.4
{
	// �������������������н���ֵ��һ���ַ�������#���ַ���ʾ������
	// ������������ʾ�Ķ�����T��
	char ch;
	scanf("%c",&ch);
	if (ch=='#') T = NULL;
	else
	{
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
		T->data = ch; // ���ɸ����
		CreateBiTree(T->lchild);   // ����������
		CreateBiTree(T->rchild);  // ����������
	}
	return OK;
} // CreateBiTree

Status PreOrderTraverse( BiTree T)
{
	// ǰ�����������T�ĵݹ��㷨
	//��ȫ����,���ö�����
	if(T == NULL)
	{
		return 0;
	}
	else
	{
		cout << T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return 1;
} // PreOrderTraverse

Status InOrderTraverse( BiTree T)
{
	// �������������T�ĵݹ��㷨
	//��ȫ����,���ö�����
	if(T == NULL)
	{
		return 0;
	}
	else
	{
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
	return 1;
} // InOrderTraverse

Status PostOrderTraverse( BiTree T)
{
	// �������������T�ĵݹ��㷨
	//��ȫ����,���ö�����
	if(T == NULL)
	{
		return 0;
	}
	else
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data;
	}
	return 1;
} // PostOrderTraverse

int main()   //������
{
	BiTree T;	//�������
	CreateBiTree(T);
	PreOrderTraverse(T);
	cout << endl;
	InOrderTraverse(T);
	cout << endl;
	PostOrderTraverse(T);
}//main
