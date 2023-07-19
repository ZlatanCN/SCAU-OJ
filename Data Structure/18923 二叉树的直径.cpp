#include "iostream"

using namespace std;

// 定义二叉树结点
typedef struct BSTNode
{
	int data;
	struct BSTNode *lchild, *rchild;
} BSTNode, *BiTree;

// 求以当前结点为根节点的二叉树的最大直径的长度
int Diameter(BiTree T)
{
	if (!T) // 如果当前结点为空，则返回0
	{
		return 0;
	}
	int n = Diameter(T->lchild); // 递归求左子树的最大直径
	int m = Diameter(T->rchild); // 递归求右子树的最大直径
	if (n > m) // 如果左子树的最大直径大于右子树的最大直径，则返回左子树的最大直径+1
	{
		return n + 1;
	}
	else // 否则返回右子树的最大直径+1
	{
		return m + 1;
	}
}

int main()
{
	int n, i;
	cin >> n; // 输入二叉树的结点个数
	BiTree T[n + 1]; // 定义一个指针数组，用于存储二叉树的结点
	for (i = 1; i <= n; i++) // 初始化二叉树的结点，结点的值为结点的编号，左右子树为空
	{
		T[i] = new BSTNode;
		T[i]->data = i;
		T[i]->lchild = NULL;
		T[i]->rchild = NULL;
	}
	for (i = 1; i < n; i++) // 输入二叉树的边，构建二叉树
	{
		int x, y;
		cin >> x >> y;
		if (T[x]->lchild == NULL) // 如果当前结点的左子树为空，则将输入的结点作为当前结点的左子树
		{
			T[x]->lchild = T[y];
		}
		else // 否则将输入的结点作为当前结点的右子树
		{
			T[x]->rchild = T[y];
		}
	}
	int max = 0;
	for (i = 1; i <= n; i++) // 遍历每个结点，求以每个结点为根节点的二叉树的最大直径长度，并记录最大值
	{
		T[i]->data = Diameter(T[i]->lchild) + Diameter(T[i]->rchild); // 将以当前结点为根节点的二叉树的最大直径长度存储在结点的data域中
		if (T[i]->data > max) // 如果当前结点的最大直径长度大于之前的最大值，则更新最大值
		{
			max = T[i]->data;
		}
	}
	cout << max; // 输出最大直径长度
}
