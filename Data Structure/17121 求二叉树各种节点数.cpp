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

// 计算二叉树中叶子结点的个数
int LeafCount(BiTree T)
{
	if(!T)
	{
		// 如果当前节点为空，则返回0
		return 0;
	}
	if(!T->lchild && !T->rchild)
	{
		// 如果当前节点是叶子节点，则返回1
		return 1;
	}
	else
	{
		// 如果当前节点不是叶子节点，则递归计算左右子树中叶子节点的个数之和
		return LeafCount(T->lchild) + LeafCount(T->rchild);
	}
}

// 计算二叉树中非叶子结点的个数
int NodeCount(BiTree T)
{
	if(!T)
	{
		// 如果当前节点为空，则返回0
		return 0;
	}
	else
	{
		// 如果当前节点不为空，则递归计算左右子树的节点个数之和再加上1
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}
int main()   //主函数
{
	//补充代码
	BiTree T;
	CreateBiTree(T);
	cout << LeafCount(T) - 1 << endl;
	cout << NodeCount(T) - LeafCount(T) + 1 - LeafCount(T) << endl;
	cout << LeafCount(T) << endl;
}//main
