#include "stdio.h"
#include "malloc.h"
#include <iostream>
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

// �����������Ҷ�ӽ��ĸ���
int LeafCount(BiTree T)
{
	if(!T)
	{
		// �����ǰ�ڵ�Ϊ�գ��򷵻�0
		return 0;
	}
	if(!T->lchild && !T->rchild)
	{
		// �����ǰ�ڵ���Ҷ�ӽڵ㣬�򷵻�1
		return 1;
	}
	else
	{
		// �����ǰ�ڵ㲻��Ҷ�ӽڵ㣬��ݹ��������������Ҷ�ӽڵ�ĸ���֮��
		return LeafCount(T->lchild) + LeafCount(T->rchild);
	}
}

// ����������з�Ҷ�ӽ��ĸ���
int NodeCount(BiTree T)
{
	if(!T)
	{
		// �����ǰ�ڵ�Ϊ�գ��򷵻�0
		return 0;
	}
	else
	{
		// �����ǰ�ڵ㲻Ϊ�գ���ݹ�������������Ľڵ����֮���ټ���1
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}
int main()   //������
{
	//�������
	BiTree T;
	CreateBiTree(T);
	cout << LeafCount(T) - 1 << endl;
	cout << NodeCount(T) - LeafCount(T) + 1 - LeafCount(T) << endl;
	cout << LeafCount(T) << endl;
}//main
