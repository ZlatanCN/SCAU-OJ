#include <stdlib.h>
#include <stdio.h>

void Merge(int a[], int left, int mid, int right, int tmp[]) // 归并操作，将左右两个有序序列合并成一个有序序列
{
	int i = left, j = mid + 1, k = left; // i指向左序列的起始位置，j指向右序列的起始位置，k指向临时数组的起始位置
	while(i <= mid && j <= right) // 左右序列都没遍历完
	{
		if(a[i] < a[j]) // 左序列当前元素小于右序列当前元素
		{
			tmp[k++] = a[i++]; // 将左序列当前元素放入临时数组，i和k都加1
		}
		else // 左序列当前元素大于等于右序列当前元素
		{
			tmp[k++] = a[j++]; // 将右序列当前元素放入临时数组，j和k都加1
		}
	}
	while(i <= mid) // 左序列还有剩余元素
	{
		tmp[k++] = a[i++]; // 将剩余元素全部放入临时数组，i和k都加1
	}
	while(j <= right) // 右序列还有剩余元素
	{
		tmp[k++] = a[j++]; // 将剩余元素全部放入临时数组，j和k都加1
	}
	for(i = left; i <= right; i++) // 将临时数组中的有序序列复制回原数组
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int a[], int n) // 非递归归并排序
{
	int *tmp = (int*)malloc(sizeof(int) * n); // 分配一个临时数组
	int gap = 1; // gap表示当前归并的有序序列的长度，初始为1
	while(gap < n) // 归并的有序序列的长度不断增加，直到整个序列有序
	{
		for(int i = 0; i < n; i += 2 * gap) // 每次归并两个长度为gap的有序序列
		{
			int left = i, mid = i + gap, right = i + 2 * gap - 1; // 左序列的起始位置为i，右序列的终止位置为i+2*gap-1，中间位置为i+gap
			if(mid >= n) // 如果左序列已经遍历完，直接退出循环
			{
				break;
			}
			if(right >= n) // 如果右序列不足gap个元素，将右序列的终止位置设为n-1
			{
				right = n - 1;
			}
			Merge(a, left, mid - 1, right, tmp); // 归并左右序列
		}
		gap *= 2; // 归并的有序序列长度翻倍
		for(int i = 0; i < n; i++) // 打印每次归并后的结果
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	free(tmp); // 释放临时数组
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
