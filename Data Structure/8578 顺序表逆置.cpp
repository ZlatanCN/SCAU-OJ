#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	// �������
	int i;
	int n;
	// �����б�ĳ���
	cin >> n;
	// �����б����������Ԫ��
	int list[n];
	for(i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	// ���ԭʼ�б�
	cout << "The List is:";
	for(i = 0; i < n; i++)
	{
		cout << list[i] << ' ';
	}
	// ����
	cout << "\n";
	// �����ת����б�
	cout << "The turned List is:";
	// ���б�����һ��Ԫ�ؿ�ʼ�����ֱ����һ��Ԫ��
	for(i = n - 1; i >= 0; i--)
	{
		cout << list[i] << ' ';
	}
}
