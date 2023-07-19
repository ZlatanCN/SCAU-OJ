#include <iostream>//C++��׼�������ͷ�ļ�
using namespace std;
struct LNode // ����������
{
	int data; // ������
	LNode * next; // ָ����һ������ָ��
};

void createList(LNode * &L,int n) // ��������n��Ԫ�صĵ�����
{
	LNode *r, *p; // ����βָ��r����ʱָ��p
	r = L = new LNode; // ����ͷ���
	L->next = NULL; // ͷ����nextָ��ָ��NULL
	for (int i = 1; i <= n; i++)
	{
		p = new LNode; // �����½��
		cin >> p->data; // ����Ԫ�ص�ֵ
		p->next = NULL; // �½���nextָ��ָ��NULL
		r->next = p; // ���½����뵽�����β��
		r = p; // ��βָ��rָ���½��
	}
}

void trv(LNode * L) // ��������
{
	L = L->next; // ָ������ĵ�һ�����
	while (L)
	{
		cout << L->data << ' '; // �������ֵ
		L = L->next; // ָ����һ�����
	}
}

void reverseList(LNode * &L) // ��ת����
{
	LNode *pre = NULL; // ����ǰ��ָ��pre
	LNode *cur = L->next; // ���嵱ǰָ��cur����ʼֵΪ��һ�����
	LNode *nex = NULL; // ������ָ��nex
	while (cur)
	{
		nex = cur;//����ǰ�ڵ㱣����nex��
		cur = cur->next;//��curָ����һ���ڵ�
		nex->next = pre;//����ǰ�ڵ��nextָ��ָ��ǰһ���ڵ㣬�Ӷ�ʵ�ֽ�����ת
		pre = nex;//��ǰһ���ڵ�ָ��ǰ�ڵ㣬Ϊ��һ��ѭ����׼��
	}
	L->next = pre; // ��ͷ����nextָ��ָ���µĵ�һ�����
}

int main()
{
	int n; // ����������
	LNode *L; // ��������ͷ���ָ��
	cin >> n; // ����������
	createList(L, n); // ��������
	reverseList(L); // ��ת����
	trv(L); // ��������
	return 0;
}

