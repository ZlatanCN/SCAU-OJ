#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BNode
{
	char data;            // ������
	struct BNode *lchild, *rchild;    // ���Һ���ָ��
} BNode, *BiTree;

// ������������������ĺ��������ع������Ķ�����
BiTree Creat_PostTraverse_BiTree(BiTree &T, char *pre, char *in, int len)
{
	if(len <= 0)    // �������Ϊ0��˵���Ѿ�û�нڵ��ˣ�����NULL
	{
		return NULL;
	}
	T = (BNode *)malloc(sizeof(BNode));    // ����ڵ�ռ�
	T->data = *pre;                        // ��pre��ָ����ַ���ֵ����ǰ�ڵ��������
	int root_index = 0;                    // ���ڴ洢��ǰ������������еĸ��ڵ�λ��
	while(root_index < len && *(in + root_index) != *pre)    // ��������������в��Ҹ��ڵ�λ��
	{
		root_index++;
	}
	// �ݹ鹹����������
	Creat_PostTraverse_BiTree(T->lchild, pre + 1, in, root_index);
	// pre+1��ʾ������������������У�in��ʾ������������������У�root_index��ʾ�������ĳ���
	Creat_PostTraverse_BiTree(T->rchild, pre + root_index + 1, in + root_index + 1, len - root_index - 1);
	// pre+root_index+1��ʾ������������������У�in+root_index+1��ʾ������������������У�len-root_index-1��ʾ�������ĳ���
	printf("%c",T->data);    // �����ǰ�ڵ�������򣬼�������������һ���ڵ�
}

int main()
{
	char pre[31], in[31];
	BiTree T;
	scanf("%s%s",pre,in);    // ������������������������
	int len = strlen(pre);    // ���г���
	Creat_PostTraverse_BiTree(T, pre, in, len);    // �����������������
	return 0;    // ������������
}
