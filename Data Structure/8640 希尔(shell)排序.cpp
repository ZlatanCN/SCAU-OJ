#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n;
int a[N] = {0};

// 希尔排序函数
void ShellSort()
{
	int d = n / 2;  // 初始增量
	while (d > 0)  // 增量d不断减小，直到为1结束
	{
		// 算法核心：对每个子序列进行插入排序
		for (int i = 0; i + d < n; i++)  // 对每个子序列进行插入排序
		{
			for (int j = 0; j + d < n; j++)  // 插入排序
			{
				if (a[j] > a[j + d])  // 如果前一个数大于后一个数
				{
					swap(a[j], a[j + d]);  // 交换两个数的位置
				}
			}
		}

		// 输出每次排序后的结果
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';

		d /= 2;  // 增量减半
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ShellSort();  // 调用希尔排序函数
	return 0;
}

