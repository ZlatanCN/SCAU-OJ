#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n;
int a[N] = {0};

// ϣ��������
void ShellSort()
{
	int d = n / 2;  // ��ʼ����
	while (d > 0)  // ����d���ϼ�С��ֱ��Ϊ1����
	{
		// �㷨���ģ���ÿ�������н��в�������
		for (int i = 0; i + d < n; i++)  // ��ÿ�������н��в�������
		{
			for (int j = 0; j + d < n; j++)  // ��������
			{
				if (a[j] > a[j + d])  // ���ǰһ�������ں�һ����
				{
					swap(a[j], a[j + d]);  // ������������λ��
				}
			}
		}

		// ���ÿ�������Ľ��
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';

		d /= 2;  // ��������
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ShellSort();  // ����ϣ��������
	return 0;
}

