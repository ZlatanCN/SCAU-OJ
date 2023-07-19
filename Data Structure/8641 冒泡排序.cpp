#include <iostream>
#include <algorithm> // 包含 swap 函数

using namespace std;

int n; // 数组长度
int a[100000]; // 定义数组 a，长度为 100000

/*
 * 冒泡排序函数
 */
void BubbleSort()
{
	int i = 1, j, k; // 定义 i, j, k 三个变量
	while (i) // 如果上一轮有交换，继续循环
	{
		i = 0; // 初始化 i 为 0
		for (j = 0; j < n - 1; j++) // 外层循环
		{
			if (a[j + 1] < a[j]) // 如果后面的数比前面的数小
			{
				swap(a[j], a[j + 1]); // 交换两个数的位置
				i = 1; // 记录本轮有交换
			}
		}
		for (k = 0; k < n; k++) // 输出每轮排序后的结果
		{
			cout << a[k] << " "; // 输出数组中的每一个数
		}
		cout << endl; // 换行
	}
}

/*
 * 主函数
 */
int main()
{
	cin >> n; // 输入数组长度
	for (int i = 0; i < n; i++) // 输入数组的每一个数
	{
		cin >> a[i];
	}
	BubbleSort(); // 调用冒泡排序函数
	return 0; // 返回 0，表示程序正常结束
}

