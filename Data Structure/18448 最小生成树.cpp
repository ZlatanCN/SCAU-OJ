#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long n,m,v[2005],d[2005],e[2005][2005];
/*n：表示图中节点的数量。
m：表示图中边的数量。
v：表示每个节点的标记，用于标记节点是否已经加入最小生成树。
d：表示节点之间的最短距离。
e：表示图的邻接矩阵，其中 e[i][j] 表示节点 i 和节点 j 之间的边的权值。*/

int GetMin()
{
	int i, mini = 0; //初始化为0，d[0]很大
	for(i = 1; i <= n; i++)
	{
		if(d[mini] > d[i] && v[i] == 0) //找到未被标记的距离最小的顶点
		{
			mini = i;
		}
	}
	return mini; //返回该顶点的编号
}

long long prim()
{
	memset(d, 127 / 3, sizeof d); //将d数组初始化为无穷大
	v[1] = 1; //将第1个顶点标记为已加入最小生成树
	long long ans = 0; //最小生成树的权值之和
	for(int i = 1; i <= n; i++)
	{
		d[i] = e[1][i]; //顶点1到其它点的距离
	}
	for(int j = 1; j < n; j++) //最小生成树有n-1条边
	{
		int minnode = GetMin(); //找到距离最小的未标记顶点
		v[minnode] = 1; //标记该顶点已经加入最小生成树
		ans += d[minnode]; //将该顶点的距离加入最小生成树的权值之和
		for(int i = 1; i <= n; i++)
		{
			d[i] = min(d[i], e[minnode][i]); //更新最短距离
		}
	}
	return ans; //返回最小生成树的权值之和
}

int main()
{
	long long i, x, y, z;
	memset(e, 127 / 3, sizeof e); //将邻接矩阵初始化为无穷大
	cin >> n >> m; //输入顶点数和边数
	for(i = 1; i <= m; i++)
	{
		cin >> x >> y >> z; //输入边的两个端点和边权
		if(x == y) //防止自环
		{
			continue;
		}
		e[x][y] = e[y][x] = min(e[x][y], z); //加入边，防止重边
	}
	cout << prim(); //计算最小生成树的权值之和并输出
	return 0;
}
