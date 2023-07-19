#include "stdio.h"
#include <iostream>
#include <cstring>
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
	struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T)    // 算法6.4
{
	// 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
	// 构造二叉链表表示的二叉树T。
	char ch;
	scanf("%c",&ch);
	if (ch=='#') T = NULL;
	else
	{
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
		T->data = ch;// 生成根结点
		CreateBiTree(T->lchild);// 构造左子树
		CreateBiTree(T->rchild);// 构造右子树
	}
	return OK;
} // CreateBiTree

int leapcount(BiTree T, int k)
{
	if(!T || k <= 0)
	{
		return 0;
	}
	if(T->lchild == NULL && T->rchild == NULL)
	{
		if(k == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return leapcount(T->lchild, k - 1) + leapcount(T->rchild, k - 1);
}

int main()   //主函数
{
	BiTree(T);
	int k;
	CreateBiTree(T);
	cin >> k;
	cout << leapcount(T, k) << endl;
}//main

