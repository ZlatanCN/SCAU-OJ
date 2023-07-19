#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	// 定义变量
	int i;
	int n;
	// 输入列表的长度
	cin >> n;
	// 定义列表，并逐个输入元素
	int list[n];
	for(i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	// 输出原始列表
	cout << "The List is:";
	for(i = 0; i < n; i++)
	{
		cout << list[i] << ' ';
	}
	// 换行
	cout << "\n";
	// 输出翻转后的列表
	cout << "The turned List is:";
	// 从列表的最后一个元素开始输出，直到第一个元素
	for(i = n - 1; i >= 0; i--)
	{
		cout << list[i] << ' ';
	}
}
