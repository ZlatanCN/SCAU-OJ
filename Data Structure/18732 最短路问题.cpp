#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct
{
	int arcs_value[150][1500];  // �洢��Ȩֵ�Ķ�ά����
	int vexnum;                // �洢������
	int arcnum;                // �洢����
} AMGraph;

const int INF = 0x3f;           // ����һ������ֵ�����ڱ�ʾ�����
int D[150][1500];                // �洢��Դ�㵽�����������̾���

// ����������
void CreatUDN(AMGraph &G)
{
	int i, j, k, n;
	memset(G.arcs_value, INF, sizeof(G.arcs_value));  // ��ʼ����ȨֵΪ�����
	cin >> G.vexnum >> G.arcnum;                      // ���붥�����ͱ���
	n = G.arcnum;
	while(n)                                          // ���������
	{
		cin >> i >> j >> k;                           // ����ߵ���㡢�յ��Ȩֵ
		if(k < G.arcs_value[i][j])                    // ����ñߵ�Ȩֵ��֮ǰ����ı�ȨֵС
		{
			G.arcs_value[i][j] = k;                   // ���±�Ȩֵ
			G.arcs_value[j][i] = k;                   // ����������ͼ�����ԶԳƵı�ҲҪ����
		}
		n--;
	}
	for(i = 1; i <= G.vexnum; ++i)                     // �Խ����ϵı�ȨֵΪ0
	{
		G.arcs_value[i][i] = 0;
	}
}

// Floyd�㷨�����·��
void ShortestPath_Floyd(AMGraph G)
{
	int i, j, k;
	for(i = 1; i <= G.vexnum; ++i)
	{
		for(j = 1; j <= G.vexnum; ++j)
		{
			D[i][j] = G.arcs_value[i][j];             // ��ʼ����̾���Ϊ��Ȩֵ
		}
	}
	for(k = 1; k <= G.vexnum; ++k)                    // ö���м��
	{
		for(i = 1; i <= G.vexnum; ++i)                // ö�����
		{
			for(j = 1; j <= G.vexnum; ++j)            // ö���յ�
			{
				if(D[i][k] + D[k][j] < D[i][j])      // ��������м��k��·����ֱ������i��j��·������
				{
					D[i][j] = D[i][k] + D[k][j];     // �������·��
				}
			}
		}
	}
	if(D[1][G.vexnum] >= INF)                        // ����޷������1�����յ�n
	{
		cout << "-1";
	}
	else                                            // ����������·������
	{
		cout << D[1][G.vexnum];
	}
}

int main()
{
	AMGraph G;
	CreatUDN(G);                                    // ����������
	ShortestPath_Floyd(G);                          // ������·��
}

