#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int n, pos = 0; // nΪ�����ʮ��������posΪ�����İ˽�����λ��
	cin >> n;
	int a[n]; // ����һ�����飬���ڴ�Ű˽�������ÿһλ
	for(int i = 0; n > 0; i++) // ͨ�����ϳ���8����ʮ������ת��Ϊ�˽�����������ÿһλ���������a��
	{
		a[i] = n % 8;
		n /= 8;
		pos++; // ��¼�˽�������λ��
	}
	//cout << pos << endl;
	for(int j = pos - 1; j >= 0; j--) // �Ӹ�λ����λ�������a�е�ÿһλ
	{
		cout << a[j];
	}
}

