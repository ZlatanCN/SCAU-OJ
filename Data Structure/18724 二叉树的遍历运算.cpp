#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BNode
{
	char data;            // 数据域
	struct BNode *lchild, *rchild;    // 左右孩子指针
} BNode, *BiTree;

// 构建后序遍历二叉树的函数，返回构建出的二叉树
BiTree Creat_PostTraverse_BiTree(BiTree &T, char *pre, char *in, int len)
{
	if(len <= 0)    // 如果长度为0，说明已经没有节点了，返回NULL
	{
		return NULL;
	}
	T = (BNode *)malloc(sizeof(BNode));    // 分配节点空间
	T->data = *pre;                        // 将pre所指向的字符赋值给当前节点的数据域
	int root_index = 0;                    // 用于存储当前树在中序遍历中的根节点位置
	while(root_index < len && *(in + root_index) != *pre)    // 在中序遍历序列中查找根节点位置
	{
		root_index++;
	}
	// 递归构建左右子树
	Creat_PostTraverse_BiTree(T->lchild, pre + 1, in, root_index);
	// pre+1表示左子树的先序遍历序列，in表示左子树的中序遍历序列，root_index表示左子树的长度
	Creat_PostTraverse_BiTree(T->rchild, pre + root_index + 1, in + root_index + 1, len - root_index - 1);
	// pre+root_index+1表示右子树的先序遍历序列，in+root_index+1表示右子树的中序遍历序列，len-root_index-1表示右子树的长度
	printf("%c",T->data);    // 输出当前节点的数据域，即后序遍历结果的一个节点
}

int main()
{
	char pre[31], in[31];
	BiTree T;
	scanf("%s%s",pre,in);    // 读入先序遍历和中序遍历序列
	int len = strlen(pre);    // 序列长度
	Creat_PostTraverse_BiTree(T, pre, in, len);    // 构建后序遍历二叉树
	return 0;    // 程序正常结束
}
