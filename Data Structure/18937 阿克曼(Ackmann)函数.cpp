#include <stdio.h>
#include <iostream>

using namespace std;

int Ackmann(int m, int n)
{
	int res;  // �������res���洢Ackermann�����ķ���ֵ

	// ���m����0������n+1
	if (m == 0)
	{
		res = n + 1;
	}
	// ���m>0��n����0������Ackmann(m-1,1)
	else if (m > 0 && n == 0)
	{
		res = Ackmann(m - 1, 1);
	}
	// ���m>0��n>0������Ackmann(m-1, Ackmann(m,n-1))
	else if (m > 0 && n > 0)
	{
		res = Ackmann(m - 1, Ackmann(m, n - 1));
	}

	// ����Ackermann�����ķ���ֵ
	return res;
}

int main()
{
	int m, n;  // �������m��n����ʾҪ�����Ackermann��������������
	cin >> m >> n;  // ������������
	cout << Ackmann(m, n);  // ���Ackermann�����ķ���ֵ
}

