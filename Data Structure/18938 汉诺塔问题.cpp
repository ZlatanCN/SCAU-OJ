#include <stdio.h>
#include <iostream>

using namespace std;

void hanoi(int n, char a, char b, char c)
{
	// ���ֻ��һ�����ӣ�ֱ�Ӵ� a �ƶ��� b
	if(n == 1)
	{
		cout << a << "->" << n << "->" << b << endl;
		return;
	}
	// �ݹ���� hanoi ������������� n-1 �����Ӵ� a ���� b �ƶ��� c
	hanoi(n - 1, a, c, b);
	// ������µ�һ�����Ӵ� a �ƶ��� b
	cout << a << "->" << n << "->" << b << endl;
	// �ݹ���� hanoi �������� c �ϵ� n-1 �����Ӿ��� a �ƶ��� b
	hanoi(n - 1, c, b, a);
}

int main()
{
	int n; // n ��ʾ���ӵĸ���
	char a, b, c; // a��b��c �ֱ��ʾ�������ӵ�����
	cin >> n >> a >> b >> c; // �ӱ�׼������� n��a��b��c ��ֵ
	hanoi(n, a, b, c); // ���� hanoi ������ʵ�ֽ� n �����Ӵ� a �ƶ��� b
}

