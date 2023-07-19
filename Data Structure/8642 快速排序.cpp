#include <iostream>

using namespace std;

int n;  // �����С
int a[100000];  // �洢����Ԫ�ص�����

void QuickSort(int left, int right)
{
	int key = a[left];  // ѡ���һ��Ԫ����Ϊ����
	int l = left;  // ��¼��߽�
	int r = right;  // ��¼�ұ߽�
	if (left >= right)  // �����߽���ڵ����ұ߽磬����
	{
		return;
	}
	while (left < right)  // ����߽�С���ұ߽�ʱ����������
	{
		// ���������ҵ���һ��С�������Ԫ��
		while (a[right] >= key && left < right)
		{
			right--;
		}
		a[left] = a[right];  // ����Ԫ���Ƶ����
		// ���������ҵ���һ�����������Ԫ��
		while (a[left] <= key && left < right)
		{
			left++;
		}
		a[right] = a[left];  // ����Ԫ���Ƶ��ұ�
	}
	a[left] = key;  // ������ŵ���ȷ��λ����
	for (int i = 0; i < n; i++)  // �����ǰ��������
	{
		cout << a[i] << " ";
	}
	cout << endl;
	QuickSort(l, right - 1);  // ����ߵ������н�������
	QuickSort(right + 1, r);  // ���ұߵ������н�������
}

int main()
{
	cin >> n;  // ���������С
	for (int i = 0; i < n; i++)  // ��������Ԫ��
	{
		cin >> a[i];
	}
	QuickSort(0, n - 1);  // ��������
	return 0;
}

