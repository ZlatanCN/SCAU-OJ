#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int n, pos = 0; // n为输入的十进制数，pos为该数的八进制数位数
	cin >> n;
	int a[n]; // 定义一个数组，用于存放八进制数的每一位
	for(int i = 0; n > 0; i++) // 通过不断除以8，将十进制数转化为八进制数，并将每一位存放在数组a中
	{
		a[i] = n % 8;
		n /= 8;
		pos++; // 记录八进制数的位数
	}
	//cout << pos << endl;
	for(int j = pos - 1; j >= 0; j--) // 从高位到低位输出数组a中的每一位
	{
		cout << a[j];
	}
}

