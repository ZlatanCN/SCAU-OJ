/*����
������������ʾ�Ķ��������������������������н���ֵ��'#'�ַ���ʾ������������������ʾ�Ķ�����T,��д�㷨��ɣ���������ÿһ��ֵΪX�Ľ�㣬ɾ
ȥ����Ϊ�������������ͷ���Ӧ�Ŀռ�(˵�������������ֵΪ���ַ��������п��ܳ���ֵ�ظ��Ľ��)��

�����ʽ
��һ�������������������н��
�ڶ�������һ��Ҫɾ���Ľ��ֵ

�����ʽ
��һ�����ɾ����Ķ�����������������У������������
�ڶ������ɾ����Ķ�����������������У������������

��������
ABDCG####E##CF###
C

�������
ABDE
DBEA*/
#include "stdio.h"
#include <iostream>
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
		T->data = ch;// ���ɸ����
		CreateBiTree(T->lchild);// ����������
		CreateBiTree(T->rchild);  // ����������
	}
	return OK;
} // CreateBiTree

Status preorder(BiTree T,char c)
{
	if(!T)
	{
		return 0;
	}
	else
	{
		if(T->data == c)
		{
			T->lchild = NULL;
			T->rchild = NULL;
		}
		else
		{
			cout << T->data;
		}
		preorder(T->lchild,c);
		preorder(T->rchild,c);
	}
	return 1;
}

Status inorder(BiTree T,char c)
{
	if(!T)
	{
		return 0;
	}
	else
	{
		inorder(T->lchild,c);
		if(T->data == c)
		{
			T->lchild = NULL;
			T->rchild = NULL;
		}
		else
		{
			cout << T->data;
		}
		inorder(T->rchild,c);
	}
	return 1;
}

int main()   //������
{
	char c;
	BiTree T;
	CreateBiTree(T);
	cin >> c;
	preorder(T,c);
	cout << "\n";
	inorder(T,c);
}//main
