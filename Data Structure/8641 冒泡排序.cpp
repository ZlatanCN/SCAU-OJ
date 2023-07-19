#include <iostream>
#include <algorithm> // ���� swap ����

using namespace std;

int n; // ���鳤��
int a[100000]; // �������� a������Ϊ 100000

/*
 * ð��������
 */
void BubbleSort()
{
	int i = 1, j, k; // ���� i, j, k ��������
	while (i) // �����һ���н���������ѭ��
	{
		i = 0; // ��ʼ�� i Ϊ 0
		for (j = 0; j < n - 1; j++) // ���ѭ��
		{
			if (a[j + 1] < a[j]) // ������������ǰ�����С
			{
				swap(a[j], a[j + 1]); // ������������λ��
				i = 1; // ��¼�����н���
			}
		}
		for (k = 0; k < n; k++) // ���ÿ�������Ľ��
		{
			cout << a[k] << " "; // ��������е�ÿһ����
		}
		cout << endl; // ����
	}
}

/*
 * ������
 */
int main()
{
	cin >> n; // �������鳤��
	for (int i = 0; i < n; i++) // ���������ÿһ����
	{
		cin >> a[i];
	}
	BubbleSort(); // ����ð��������
	return 0; // ���� 0����ʾ������������
}

