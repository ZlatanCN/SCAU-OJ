#include <stdlib.h>
#include <stdio.h>

void Merge(int a[], int left, int mid, int right, int tmp[]) // �鲢�����������������������кϲ���һ����������
{
	int i = left, j = mid + 1, k = left; // iָ�������е���ʼλ�ã�jָ�������е���ʼλ�ã�kָ����ʱ�������ʼλ��
	while(i <= mid && j <= right) // �������ж�û������
	{
		if(a[i] < a[j]) // �����е�ǰԪ��С�������е�ǰԪ��
		{
			tmp[k++] = a[i++]; // �������е�ǰԪ�ط�����ʱ���飬i��k����1
		}
		else // �����е�ǰԪ�ش��ڵ��������е�ǰԪ��
		{
			tmp[k++] = a[j++]; // �������е�ǰԪ�ط�����ʱ���飬j��k����1
		}
	}
	while(i <= mid) // �����л���ʣ��Ԫ��
	{
		tmp[k++] = a[i++]; // ��ʣ��Ԫ��ȫ��������ʱ���飬i��k����1
	}
	while(j <= right) // �����л���ʣ��Ԫ��
	{
		tmp[k++] = a[j++]; // ��ʣ��Ԫ��ȫ��������ʱ���飬j��k����1
	}
	for(i = left; i <= right; i++) // ����ʱ�����е��������и��ƻ�ԭ����
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int a[], int n) // �ǵݹ�鲢����
{
	int *tmp = (int*)malloc(sizeof(int) * n); // ����һ����ʱ����
	int gap = 1; // gap��ʾ��ǰ�鲢���������еĳ��ȣ���ʼΪ1
	while(gap < n) // �鲢���������еĳ��Ȳ������ӣ�ֱ��������������
	{
		for(int i = 0; i < n; i += 2 * gap) // ÿ�ι鲢��������Ϊgap����������
		{
			int left = i, mid = i + gap, right = i + 2 * gap - 1; // �����е���ʼλ��Ϊi�������е���ֹλ��Ϊi+2*gap-1���м�λ��Ϊi+gap
			if(mid >= n) // ����������Ѿ������ֱ꣬���˳�ѭ��
			{
				break;
			}
			if(right >= n) // ��������в���gap��Ԫ�أ��������е���ֹλ����Ϊn-1
			{
				right = n - 1;
			}
			Merge(a, left, mid - 1, right, tmp); // �鲢��������
		}
		gap *= 2; // �鲢���������г��ȷ���
		for(int i = 0; i < n; i++) // ��ӡÿ�ι鲢��Ľ��
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	free(tmp); // �ͷ���ʱ����
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
	MergeSort(a, n);
}
