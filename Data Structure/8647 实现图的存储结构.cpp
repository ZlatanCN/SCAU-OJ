#include "iostream"

using namespace std;

int main()
{
	int n, m, i, j;
	cin >> n >> m; // ����ͼ�Ľ������ͱߵĸ���
	int a[100][100] = {0}; // �����ڽӾ������ڴ洢ͼ
	for (i = 1; i <= m; i++) // ����ÿ���ߵ�������㣬���ߴ洢���ڽӾ�����
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = 1; // ����д�x��y�ıߣ���a[x][y]=1
	}
	for (i = 1; i <= n; i++) // �����ڽӾ������ͼ���ڽӾ���
	{
		for (j = 1; j <= n; j++)
		{
			cout << a[i][j] << " "; // ���a[i][j]
			if (j == n) // ����Ѿ����˵�n�У���������з�
			{
				cout << endl;
			}
		}
	}
}

