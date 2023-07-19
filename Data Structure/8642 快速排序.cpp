#include <iostream>

using namespace std;

int n;  // 数组大小
int a[100000];  // 存储数组元素的数组

void QuickSort(int left, int right)
{
	int key = a[left];  // 选择第一个元素作为枢轴
	int l = left;  // 记录左边界
	int r = right;  // 记录右边界
	if (left >= right)  // 如果左边界大于等于右边界，返回
	{
		return;
	}
	while (left < right)  // 当左边界小于右边界时，继续排序
	{
		// 从右往左找到第一个小于枢轴的元素
		while (a[right] >= key && left < right)
		{
			right--;
		}
		a[left] = a[right];  // 将该元素移到左边
		// 从左往右找到第一个大于枢轴的元素
		while (a[left] <= key && left < right)
		{
			left++;
		}
		a[right] = a[left];  // 将该元素移到右边
	}
	a[left] = key;  // 将枢轴放到正确的位置上
	for (int i = 0; i < n; i++)  // 输出当前的排序结果
	{
		cout << a[i] << " ";
	}
	cout << endl;
	QuickSort(l, right - 1);  // 对左边的子序列进行排序
	QuickSort(right + 1, r);  // 对右边的子序列进行排序
}

int main()
{
	cin >> n;  // 输入数组大小
	for (int i = 0; i < n; i++)  // 输入数组元素
	{
		cin >> a[i];
	}
	QuickSort(0, n - 1);  // 快速排序
	return 0;
}

