#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 获取数字 num 的位数
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

// 输出数组 a
void Output(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%03d ",a[i]);
	}
	printf("\n");
}

// 基数排序函数
void Radixsort(int n, int a[])
{
	int b[10][10];  // 定义辅助数组 b
	int max = a[0];  // 获取数组中的最大值
	for(int i = 1; i < n; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}
	int digit = Digit(max);  // 获取最大值的位数
	int index = 1;
	for(int i = 1; i <= digit; i++)  // 从低位到高位依次排序
	{
		memset(b, 0, sizeof(b));  // 清空辅助数组 b
		for(int j = 0; j < n; j++)  // 将数组 a 中的元素按照当前位数的值放到辅助数组 b 中
		{
			int num = a[j] / index % 10;  // 获取当前位数的值
			b[num][++b[num][0]] = a[j];  // 将元素放入对应的桶中
		}
		int a_len = 0;
		// 将辅助数组 b 中的元素按顺序放回数组 a 中
		for(int t = 0; t < 10; t++)
		{
			for(int s = 1; s <= b[t][0]; s++)
			{
				a[a_len++] = b[t][s];
			}
		}
		Output(a, n);  // 输出排序后的数组 a
		index *= 10;  // 更新位数
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
	Radixsort(n, a);  // 调用基数排序函数
}
