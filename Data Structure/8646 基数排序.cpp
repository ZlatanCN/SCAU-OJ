#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ��ȡ���� num ��λ��
int Digit(int num)
{
	int k = 0;
	while(num != 0)
	{
		num /= 10;
		k++;
	}
	return k;
}

// ������� a
void Output(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%03d ",a[i]);
	}
	printf("\n");
}

// ����������
void Radixsort(int n, int a[])
{
	int b[10][10];  // ���帨������ b
	int max = a[0];  // ��ȡ�����е����ֵ
	for(int i = 1; i < n; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}
	int digit = Digit(max);  // ��ȡ���ֵ��λ��
	int index = 1;
	for(int i = 1; i <= digit; i++)  // �ӵ�λ����λ��������
	{
		memset(b, 0, sizeof(b));  // ��ո������� b
		for(int j = 0; j < n; j++)  // ������ a �е�Ԫ�ذ��յ�ǰλ����ֵ�ŵ��������� b ��
		{
			int num = a[j] / index % 10;  // ��ȡ��ǰλ����ֵ
			b[num][++b[num][0]] = a[j];  // ��Ԫ�ط����Ӧ��Ͱ��
		}
		int a_len = 0;
		// ���������� b �е�Ԫ�ذ�˳��Ż����� a ��
		for(int t = 0; t < 10; t++)
		{
			for(int s = 1; s <= b[t][0]; s++)
			{
				a[a_len++] = b[t][s];
			}
		}
		Output(a, n);  // ������������� a
		index *= 10;  // ����λ��
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	Radixsort(n, a);  // ���û���������
}
