/*描述
构造二叉链表表示的二叉树：按先序次序输入二叉树中结点的值，'#'字符表示空树，构造二叉链表表示的二叉树T,编写算法完成：对于树中每一个值为X的结点，删
去以它为根的子树，并释放相应的空间(说明：二叉树结点值为单字符，且树中可能出现值重复的结点)。

输入格式
第一行输入先序次序二叉树中结点
第二行输入一个要删除的结点值

输出格式
第一行输出删除后的二叉树先序遍历的序列（不输出空树）
第二行输出删除后的二叉树中序遍历的序列（不输出空树）

输入样例
ABDCG####E##CF###
C

输出样例
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
		CreateBiTree(T->rchild);  // 构造右子树
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

int main()   //主函数
{
	char c;
	BiTree T;
	CreateBiTree(T);
	cin >> c;
	preorder(T,c);
	cout << "\n";
	inorder(T,c);
}//main
