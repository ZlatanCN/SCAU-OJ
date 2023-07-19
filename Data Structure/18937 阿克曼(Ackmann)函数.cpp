#include <stdio.h>
#include <iostream>

using namespace std;

int Ackmann(int m, int n)
{
	int res;  // 定义变量res，存储Ackermann函数的返回值

	// 如果m等于0，返回n+1
	if (m == 0)
	{
		res = n + 1;
	}
	// 如果m>0且n等于0，返回Ackmann(m-1,1)
	else if (m > 0 && n == 0)
	{
		res = Ackmann(m - 1, 1);
	}
	// 如果m>0且n>0，返回Ackmann(m-1, Ackmann(m,n-1))
	else if (m > 0 && n > 0)
	{
		res = Ackmann(m - 1, Ackmann(m, n - 1));
	}

	// 返回Ackermann函数的返回值
	return res;
}

int main()
{
	int m, n;  // 定义变量m和n，表示要计算的Ackermann函数的两个参数
	cin >> m >> n;  // 输入两个参数
	cout << Ackmann(m, n);  // 输出Ackermann函数的返回值
}

