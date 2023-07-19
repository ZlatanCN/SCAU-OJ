#include "iostream"

using namespace std;

int main()
{
	int n, m, i, j;
	cin >> n >> m; // 输入图的结点个数和边的个数
	int a[100][100] = {0}; // 定义邻接矩阵，用于存储图
	for (i = 1; i <= m; i++) // 输入每条边的两个结点，将边存储在邻接矩阵中
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = 1; // 如果有从x到y的边，则a[x][y]=1
	}
	for (i = 1; i <= n; i++) // 遍历邻接矩阵，输出图的邻接矩阵
	{
		for (j = 1; j <= n; j++)
		{
			cout << a[i][j] << " "; // 输出a[i][j]
			if (j == n) // 如果已经到了第n列，则输出换行符
			{
				cout << endl;
			}
		}
	}
}

