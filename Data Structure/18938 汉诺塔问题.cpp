#include <stdio.h>
#include <iostream>

using namespace std;

void hanoi(int n, char a, char b, char c)
{
	// 如果只有一个盘子，直接从 a 移动到 b
	if(n == 1)
	{
		cout << a << "->" << n << "->" << b << endl;
		return;
	}
	// 递归调用 hanoi 函数，将上面的 n-1 个盘子从 a 经过 b 移动到 c
	hanoi(n - 1, a, c, b);
	// 将最底下的一个盘子从 a 移动到 b
	cout << a << "->" << n << "->" << b << endl;
	// 递归调用 hanoi 函数，将 c 上的 n-1 个盘子经过 a 移动到 b
	hanoi(n - 1, c, b, a);
}

int main()
{
	int n; // n 表示盘子的个数
	char a, b, c; // a、b、c 分别表示三根柱子的名称
	cin >> n >> a >> b >> c; // 从标准输入读入 n、a、b、c 的值
	hanoi(n, a, b, c); // 调用 hanoi 函数，实现将 n 个盘子从 a 移动到 b
}

