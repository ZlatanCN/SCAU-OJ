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
		T->data = ch; // 生成根结点
		CreateBiTree(T->lchild);   // 构造左子树
		CreateBiTree(T->rchild);  // 构造右子树
	}
	return OK;
} // CreateBiTree

Status PreOrderTraverse( BiTree T)
{
	// 前序遍历二叉树T的递归算法
	//补全代码,可用多个语句
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
	// 中序遍历二叉树T的递归算法
	//补全代码,可用多个语句
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
	// 后序遍历二叉树T的递归算法
	//补全代码,可用多个语句
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

int main()   //主函数
{
	BiTree T;	//补充代码
	CreateBiTree(T);
	PreOrderTraverse(T);
	cout << endl;
	InOrderTraverse(T);
	cout << endl;
	PostOrderTraverse(T);
}//main
