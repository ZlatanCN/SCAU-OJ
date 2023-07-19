#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	int graph[50][50] = {0}; //定义一个50*50的二维数组，表示有向图的邻接矩阵（初始值都为0）
	int list[50] = {0}; //定义一个大小为50的一维数组，表示每个点是否已经输出（初始值都为0）
	int vexnum, arcnum; //vexnum表示点的个数，arcnum表示边的个数
	cin >> vexnum >> arcnum; //输入点的个数和边的个数
	for(int i = 0; i < arcnum; i++) //循环输入每一条边
	{
		int v1, v2;
		cin >> v1 >> v2; //输入边的起点和终点
		graph[v1][v2] = 1; //在邻接矩阵中标记该边
	}
	int count = 1, i = 1; //count表示已经输出的点的个数（初始值为1），i表示当前扫描的列数（初始值为1）
	while(count <= vexnum) //当所有点都输出完毕后结束循环
	{
		int flag = 1; //flag表示当前列是否全为0（初始值为1）
		for(int j = 1; j <= vexnum; j++) //循环遍历第i列
		{
			if(graph[j][i]) //如果第i列中有任何一个元素不为0，说明有入度
			{
				flag = 0; //将flag置为0
				break;
			}
		}
		if(flag && list[i] != 1) //如果第i列全为0，且该点未输出
		{
			cout << i << ' '; //输出该点的编号
			list[i] = 1; //将该点标记为已输出
			for(int j = 1; j <= vexnum; j++) //循环遍历该点的出度
			{
				graph[i][j] = {0}; //将该点的出度删除（即将该点对其他点的制约关系解除）
			}
			i = 0; //从第一列开始扫描
			count++; //已输出点的数量加1
		}
		i++; //扫描下一列
	}
}

