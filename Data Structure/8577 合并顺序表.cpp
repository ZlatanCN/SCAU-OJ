#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// �������
	int i;
	int n;
	// �����б� A �ĳ���
	cin >> n;
	// �����б� A�����������Ԫ��
	int lista[n];
	for(i = 0; i < n; i++)
	{
		cin >> lista[i];
	}
	// �����б� B �ĳ���
	int m;
	cin >> m;
	// �����б� B�����������Ԫ��
	int listb[m];
	for(i = 0; i < m; i++)
	{
		cin >> listb[i];
	}
	// �����б� C������Ϊ A �� B �ĳ���֮��
	int listc[n + m];
	// ���б� A ��Ԫ�ظ��Ƶ��б� C ��
	for(i = 0; i < n; i++)
	{
		listc[i] = lista[i];
	}
	// ���б� B ��Ԫ�ظ��Ƶ��б� C ��
	for(i = 0; i < m; i++)
	{
		listc[i + n] = listb[i];
	}
	// ����б� A ��Ԫ��
	cout << "List A:";
	for(i = 0; i < n; i++)
	{
		cout << lista[i] << ' ';
	}
	// ����
	cout << "\n";
	// ����б� B ��Ԫ��
	cout << "List B:";
	for(i = 0; i < m; i++)
	{
		cout << listb[i] << ' ';
	}
	// ����
	cout << "\n";
	// ���б� C ��������
	sort(listc, listc + n + m);
	// ����б� C ��Ԫ��
	cout << "List C:";
	for(i = 0; i < n + m; i++)
	{
		cout << listc[i] << ' ';
	}
}
