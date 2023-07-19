#include <iostream>
#include <algorithm>  // ���� swap ����

using namespace std;

int n;  // �����С
int a[100000];  // �洢����Ԫ�ص�����

void SelectSort()
{
	int i, j, k, min;
	for (i = 0; i < n - 1; i++)  // ���ѭ������������
	{
		min = i;  // min �洢δ���򲿷�����СԪ�ص��±�
		for (j = i + 1; j < n; j++)  // �ڲ�ѭ�����ҵ�δ���򲿷��е���СԪ���±�
		{
			if (a[j] < a[min])  // ����ҵ��ȵ�ǰ��СԪ�ػ�С��Ԫ�أ��������СԪ���±�
			{
				min = j;
			}
		}
		swap(a[i], a[min]);  // ��δ���򲿷�����СԪ���뵱ǰԪ�ؽ��н���
		for (k = 0; k < n; k++)  // ���ÿ������������
		{
			cout << a[k] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cin >> n;  // ���������С
	for (int i = 0; i < n; i++)  // ��������Ԫ��
	{
		cin >> a[i];
	}
	SelectSort();  // ����ѡ��������
}

