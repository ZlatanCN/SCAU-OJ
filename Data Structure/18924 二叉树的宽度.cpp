#include "iostream"

using namespace std;

int a[100000] = {0};  // �洢ÿ��ڵ���������

// ����������������ṹ��
typedef struct BSTNode
{
	int data;
	struct BSTNode *lchild, *rchild;
} BSTNode, *BiTree;

// �ݹ����������������ͳ��ÿ��ڵ���
int Traverse(int k, BiTree T)
{
	if (!T)  // ������Ϊ�գ�ֱ�ӷ���
	{
		return 0;
	}
	else
	{
		a[k]++;  // ͳ�Ƶ�ǰ��ڵ���
	}
	Traverse(k + 1, T->lchild);  // �ݹ����������
	Traverse(k + 1, T->rchild);  // �ݹ����������
}

int main()
{
	int n, i;
	cin >> n;  // ��������
	BiTree T[n + 1];  // ���������������������
	for (i = 1; i <= n; i++)
	{
		T[i] = new BSTNode;  // ��̬�����ڴ�
		T[i]->data = i;  // Ϊ��㸳ֵ
		T[i]->lchild = NULL;
		T[i]->rchild = NULL;
	}
	for (i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;  // �����
		if (T[x]->lchild == NULL)  // �������������Ϊ�գ����½����Ϊ������
		{
			T[x]->lchild = T[y];
		}
		else  // �����½����Ϊ���Һ���
		{
			T[x]->rchild = T[y];
		}
	}
	int k = 1;
	Traverse(k, T[1]);  // ����������������ͳ��ÿ��ڵ���
	int max = 0;
	for (i = 1; i <= n; i++)
	{
		if (a[i] > max)  // �ҵ����Ľڵ���
		{
			max = a[i];
		}
	}
	cout << max;  // ������Ľڵ���
}

