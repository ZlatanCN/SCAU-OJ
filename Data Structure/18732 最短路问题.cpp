#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct
{
	int arcs_value[150][1500];  // 存储边权值的二维数组
	int vexnum;                // 存储顶点数
	int arcnum;                // 存储边数
} AMGraph;

const int INF = 0x3f;           // 定义一个极大值，用于表示无穷大
int D[150][1500];                // 存储从源点到各个顶点的最短距离

// 创建无向网
void CreatUDN(AMGraph &G)
{
	int i, j, k, n;
	memset(G.arcs_value, INF, sizeof(G.arcs_value));  // 初始化边权值为无穷大
	cin >> G.vexnum >> G.arcnum;                      // 输入顶点数和边数
	n = G.arcnum;
	while(n)                                          // 逐条输入边
	{
		cin >> i >> j >> k;                           // 输入边的起点、终点和权值
		if(k < G.arcs_value[i][j])                    // 如果该边的权值比之前输入的边权值小
		{
			G.arcs_value[i][j] = k;                   // 更新边权值
			G.arcs_value[j][i] = k;                   // 由于是无向图，所以对称的边也要更新
		}
		n--;
	}
	for(i = 1; i <= G.vexnum; ++i)                     // 对角线上的边权值为0
	{
		G.arcs_value[i][i] = 0;
	}
}

// Floyd算法求最短路径
void ShortestPath_Floyd(AMGraph G)
{
	int i, j, k;
	for(i = 1; i <= G.vexnum; ++i)
	{
		for(j = 1; j <= G.vexnum; ++j)
		{
			D[i][j] = G.arcs_value[i][j];             // 初始化最短距离为边权值
		}
	}
	for(k = 1; k <= G.vexnum; ++k)                    // 枚举中间点
	{
		for(i = 1; i <= G.vexnum; ++i)                // 枚举起点
		{
			for(j = 1; j <= G.vexnum; ++j)            // 枚举终点
			{
				if(D[i][k] + D[k][j] < D[i][j])      // 如果经过中间点k的路径比直接连接i和j的路径更短
				{
					D[i][j] = D[i][k] + D[k][j];     // 更新最短路径
				}
			}
		}
	}
	if(D[1][G.vexnum] >= INF)                        // 如果无法从起点1到达终点n
	{
		cout << "-1";
	}
	else                                            // 否则输出最短路径长度
	{
		cout << D[1][G.vexnum];
	}
}

int main()
{
	AMGraph G;
	CreatUDN(G);                                    // 创建无向网
	ShortestPath_Floyd(G);                          // 求解最短路径
}

