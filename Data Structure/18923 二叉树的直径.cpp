#include "iostream"

using namespace std;

// ������������
typedef struct BSTNode
{
	int data;
	struct BSTNode *lchild, *rchild;
} BSTNode, *BiTree;

// ���Ե�ǰ���Ϊ���ڵ�Ķ����������ֱ���ĳ���
int Diameter(BiTree T)
{
	if (!T) // �����ǰ���Ϊ�գ��򷵻�0
	{
		return 0;
	}
	int n = Diameter(T->lchild); // �ݹ��������������ֱ��
	int m = Diameter(T->rchild); // �ݹ��������������ֱ��
	if (n > m) // ��������������ֱ�����������������ֱ�����򷵻������������ֱ��+1
	{
		return n + 1;
	}
	else // ���򷵻������������ֱ��+1
	{
		return m + 1;
	}
}

int main()
{
	int n, i;
	cin >> n; // ����������Ľ�����
	BiTree T[n + 1]; // ����һ��ָ�����飬���ڴ洢�������Ľ��
	for (i = 1; i <= n; i++) // ��ʼ���������Ľ�㣬����ֵΪ���ı�ţ���������Ϊ��
	{
		T[i] = new BSTNode;
		T[i]->data = i;
		T[i]->lchild = NULL;
		T[i]->rchild = NULL;
	}
	for (i = 1; i < n; i++) // ����������ıߣ�����������
	{
		int x, y;
		cin >> x >> y;
		if (T[x]->lchild == NULL) // �����ǰ����������Ϊ�գ�������Ľ����Ϊ��ǰ����������
		{
			T[x]->lchild = T[y];
		}
		else // ��������Ľ����Ϊ��ǰ����������
		{
			T[x]->rchild = T[y];
		}
	}
	int max = 0;
	for (i = 1; i <= n; i++) // ����ÿ����㣬����ÿ�����Ϊ���ڵ�Ķ����������ֱ�����ȣ�����¼���ֵ
	{
		T[i]->data = Diameter(T[i]->lchild) + Diameter(T[i]->rchild); // ���Ե�ǰ���Ϊ���ڵ�Ķ����������ֱ�����ȴ洢�ڽ���data����
		if (T[i]->data > max) // �����ǰ�������ֱ�����ȴ���֮ǰ�����ֵ����������ֵ
		{
			max = T[i]->data;
		}
	}
	cout << max; // ������ֱ������
}
