#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	int graph[50][50] = {0}; //����һ��50*50�Ķ�ά���飬��ʾ����ͼ���ڽӾ��󣨳�ʼֵ��Ϊ0��
	int list[50] = {0}; //����һ����СΪ50��һά���飬��ʾÿ�����Ƿ��Ѿ��������ʼֵ��Ϊ0��
	int vexnum, arcnum; //vexnum��ʾ��ĸ�����arcnum��ʾ�ߵĸ���
	cin >> vexnum >> arcnum; //�����ĸ����ͱߵĸ���
	for(int i = 0; i < arcnum; i++) //ѭ������ÿһ����
	{
		int v1, v2;
		cin >> v1 >> v2; //����ߵ������յ�
		graph[v1][v2] = 1; //���ڽӾ����б�Ǹñ�
	}
	int count = 1, i = 1; //count��ʾ�Ѿ�����ĵ�ĸ�������ʼֵΪ1����i��ʾ��ǰɨ�����������ʼֵΪ1��
	while(count <= vexnum) //�����е㶼�����Ϻ����ѭ��
	{
		int flag = 1; //flag��ʾ��ǰ���Ƿ�ȫΪ0����ʼֵΪ1��
		for(int j = 1; j <= vexnum; j++) //ѭ��������i��
		{
			if(graph[j][i]) //�����i�������κ�һ��Ԫ�ز�Ϊ0��˵�������
			{
				flag = 0; //��flag��Ϊ0
				break;
			}
		}
		if(flag && list[i] != 1) //�����i��ȫΪ0���Ҹõ�δ���
		{
			cout << i << ' '; //����õ�ı��
			list[i] = 1; //���õ���Ϊ�����
			for(int j = 1; j <= vexnum; j++) //ѭ�������õ�ĳ���
			{
				graph[i][j] = {0}; //���õ�ĳ���ɾ���������õ�����������Լ��ϵ�����
			}
			i = 0; //�ӵ�һ�п�ʼɨ��
			count++; //��������������1
		}
		i++; //ɨ����һ��
	}
}

