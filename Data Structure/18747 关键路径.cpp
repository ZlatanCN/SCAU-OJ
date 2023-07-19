#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct
{
	int arcs_value[150][150]; // 邻接矩阵
	int vexnum; // 顶点数
	int arcnum; // 边数
} AMGraph;

const int INF = -0x3f; // 定义一个负无穷，用来表示两个顶点之间没有边

int D[150][150]; // 记录最长路径

// 创建无向网
void CreatUDN(AMGraph &G)
{
	int i, j, k, n;
	memset(G.arcs_value, INF, sizeof(G.arcs_value)); // 初始化邻接矩阵
	cin >> G.vexnum >> G.arcnum; // 输入顶点数和边数
	n = G.arcnum;
	while(n)
	{
		cin >> i >> j >> k; // 输入边(i,j)的权值k
		G.arcs_value[i][j] = k; // 将边(i,j)的权值存入邻接矩阵
		n--;
	}
}

// 求最长路径
void LongestPath(AMGraph G)
{
	int i, j, k;
	for(i = 1; i <=G.vexnum; i++)
	{
		for(j = 1; j <= G.vexnum; j++)
		{
			D[i][j] = G.arcs_value[i][j]; // 初始化最长路径矩阵
		}
	}
	for(j = 2; j <= G.vexnum - 1; j++)
	{
		for(k = j + 1; k <= G.vexnum; k++)
		{
			if(D[1][j] + D[j][k] > D[1][k]) // 如果1->j->k的路径长度大于1->k的路径长度
			{
				D[1][k] = D[1][j] + D[j][k]; // 更新1->k的路径长度
			}
		}
	}
	cout << D[1][G.vexnum]; // 输出最长路径长度
}

int main()
{
	AMGraph  G;
	CreatUDN(G); // 创建无向网
	LongestPath(G); // 求最长路径
}
