#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct
{
	int arcs_value[150][150]; // �ڽӾ���
	int vexnum; // ������
	int arcnum; // ����
} AMGraph;

const int INF = -0x3f; // ����һ�������������ʾ��������֮��û�б�

int D[150][150]; // ��¼�·��

// ����������
void CreatUDN(AMGraph &G)
{
	int i, j, k, n;
	memset(G.arcs_value, INF, sizeof(G.arcs_value)); // ��ʼ���ڽӾ���
	cin >> G.vexnum >> G.arcnum; // ���붥�����ͱ���
	n = G.arcnum;
	while(n)
	{
		cin >> i >> j >> k; // �����(i,j)��Ȩֵk
		G.arcs_value[i][j] = k; // ����(i,j)��Ȩֵ�����ڽӾ���
		n--;
	}
}

// ���·��
void LongestPath(AMGraph G)
{
	int i, j, k;
	for(i = 1; i <=G.vexnum; i++)
	{
		for(j = 1; j <= G.vexnum; j++)
		{
			D[i][j] = G.arcs_value[i][j]; // ��ʼ���·������
		}
	}
	for(j = 2; j <= G.vexnum - 1; j++)
	{
		for(k = j + 1; k <= G.vexnum; k++)
		{
			if(D[1][j] + D[j][k] > D[1][k]) // ���1->j->k��·�����ȴ���1->k��·������
			{
				D[1][k] = D[1][j] + D[j][k]; // ����1->k��·������
			}
		}
	}
	cout << D[1][G.vexnum]; // ����·������
}

int main()
{
	AMGraph  G;
	CreatUDN(G); // ����������
	LongestPath(G); // ���·��
}
