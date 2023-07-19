#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long n,m,v[2005],d[2005],e[2005][2005];
/*n����ʾͼ�нڵ��������
m����ʾͼ�бߵ�������
v����ʾÿ���ڵ�ı�ǣ����ڱ�ǽڵ��Ƿ��Ѿ�������С��������
d����ʾ�ڵ�֮�����̾��롣
e����ʾͼ���ڽӾ������� e[i][j] ��ʾ�ڵ� i �ͽڵ� j ֮��ıߵ�Ȩֵ��*/

int GetMin()
{
	int i, mini = 0; //��ʼ��Ϊ0��d[0]�ܴ�
	for(i = 1; i <= n; i++)
	{
		if(d[mini] > d[i] && v[i] == 0) //�ҵ�δ����ǵľ�����С�Ķ���
		{
			mini = i;
		}
	}
	return mini; //���ظö���ı��
}

long long prim()
{
	memset(d, 127 / 3, sizeof d); //��d�����ʼ��Ϊ�����
	v[1] = 1; //����1��������Ϊ�Ѽ�����С������
	long long ans = 0; //��С��������Ȩֵ֮��
	for(int i = 1; i <= n; i++)
	{
		d[i] = e[1][i]; //����1��������ľ���
	}
	for(int j = 1; j < n; j++) //��С��������n-1����
	{
		int minnode = GetMin(); //�ҵ�������С��δ��Ƕ���
		v[minnode] = 1; //��Ǹö����Ѿ�������С������
		ans += d[minnode]; //���ö���ľ��������С��������Ȩֵ֮��
		for(int i = 1; i <= n; i++)
		{
			d[i] = min(d[i], e[minnode][i]); //������̾���
		}
	}
	return ans; //������С��������Ȩֵ֮��
}

int main()
{
	long long i, x, y, z;
	memset(e, 127 / 3, sizeof e); //���ڽӾ����ʼ��Ϊ�����
	cin >> n >> m; //���붥�����ͱ���
	for(i = 1; i <= m; i++)
	{
		cin >> x >> y >> z; //����ߵ������˵�ͱ�Ȩ
		if(x == y) //��ֹ�Ի�
		{
			continue;
		}
		e[x][y] = e[y][x] = min(e[x][y], z); //����ߣ���ֹ�ر�
	}
	cout << prim(); //������С��������Ȩֵ֮�Ͳ����
	return 0;
}
