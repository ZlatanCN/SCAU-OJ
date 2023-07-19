#include <iostream>
#include <algorithm>  // 包含 swap 函数

using namespace std;

int n;  // 数组大小
int a[100000];  // 存储数组元素的数组

void SelectSort()
{
	int i, j, k, min;
	for (i = 0; i < n - 1; i++)  // 外层循环，控制轮数
	{
		min = i;  // min 存储未排序部分中最小元素的下标
		for (j = i + 1; j < n; j++)  // 内层循环，找到未排序部分中的最小元素下标
		{
			if (a[j] < a[min])  // 如果找到比当前最小元素还小的元素，则更新最小元素下标
			{
				min = j;
			}
		}
		swap(a[i], a[min]);  // 将未排序部分中最小元素与当前元素进行交换
		for (k = 0; k < n; k++)  // 输出每次排序后的数组
		{
			cout << a[k] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cin >> n;  // 输入数组大小
	for (int i = 0; i < n; i++)  // 输入数组元素
	{
		cin >> a[i];
	}
	SelectSort();  // 调用选择排序函数
}

