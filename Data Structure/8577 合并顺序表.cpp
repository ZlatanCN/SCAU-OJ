#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// 定义变量
	int i;
	int n;
	// 输入列表 A 的长度
	cin >> n;
	// 定义列表 A，并逐个输入元素
	int lista[n];
	for(i = 0; i < n; i++)
	{
		cin >> lista[i];
	}
	// 输入列表 B 的长度
	int m;
	cin >> m;
	// 定义列表 B，并逐个输入元素
	int listb[m];
	for(i = 0; i < m; i++)
	{
		cin >> listb[i];
	}
	// 定义列表 C，长度为 A 和 B 的长度之和
	int listc[n + m];
	// 将列表 A 的元素复制到列表 C 中
	for(i = 0; i < n; i++)
	{
		listc[i] = lista[i];
	}
	// 将列表 B 的元素复制到列表 C 中
	for(i = 0; i < m; i++)
	{
		listc[i + n] = listb[i];
	}
	// 输出列表 A 的元素
	cout << "List A:";
	for(i = 0; i < n; i++)
	{
		cout << lista[i] << ' ';
	}
	// 换行
	cout << "\n";
	// 输出列表 B 的元素
	cout << "List B:";
	for(i = 0; i < m; i++)
	{
		cout << listb[i] << ' ';
	}
	// 换行
	cout << "\n";
	// 对列表 C 进行排序
	sort(listc, listc + n + m);
	// 输出列表 C 的元素
	cout << "List C:";
	for(i = 0; i < n + m; i++)
	{
		cout << listc[i] << ' ';
	}
}
