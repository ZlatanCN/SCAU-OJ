#include "iostream"

using namespace std;

int a[100000] = {0};  // 存储每层节点数的数组

// 定义二叉搜索树结点结构体
typedef struct BSTNode
{
	int data;
	struct BSTNode *lchild, *rchild;
} BSTNode, *BiTree;

// 递归遍历二叉搜索树，统计每层节点数
int Traverse(int k, BiTree T)
{
	if (!T)  // 如果结点为空，直接返回
	{
		return 0;
	}
	else
	{
		a[k]++;  // 统计当前层节点数
	}
	Traverse(k + 1, T->lchild);  // 递归遍历左子树
	Traverse(k + 1, T->rchild);  // 递归遍历右子树
}

int main()
{
	int n, i;
	cin >> n;  // 输入结点数
	BiTree T[n + 1];  // 创建二叉搜索树结点数组
	for (i = 1; i <= n; i++)
	{
		T[i] = new BSTNode;  // 动态分配内存
		T[i]->data = i;  // 为结点赋值
		T[i]->lchild = NULL;
		T[i]->rchild = NULL;
	}
	for (i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;  // 输入边
		if (T[x]->lchild == NULL)  // 如果结点的左子树为空，则将新结点作为其左孩子
		{
			T[x]->lchild = T[y];
		}
		else  // 否则将新结点作为其右孩子
		{
			T[x]->rchild = T[y];
		}
	}
	int k = 1;
	Traverse(k, T[1]);  // 遍历二叉搜索树，统计每层节点数
	int max = 0;
	for (i = 1; i <= n; i++)
	{
		if (a[i] > max)  // 找到最多的节点数
		{
			max = a[i];
		}
	}
	cout << max;  // 输出最多的节点数
}

