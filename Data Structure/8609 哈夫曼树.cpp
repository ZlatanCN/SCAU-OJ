#include "stdio.h"
#include "string.h"
#include <iostream>
using namespace std;

typedef struct
{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
} HTNode,*HuffmanTree;

typedef char **HuffmanCode;

void select(HuffmanTree &HT, int n, int &s1, int &s2)
{
	//��HT[1..n]��ѡ��parentΪ0��weight��С��������㣬 ����ŷֱ�Ϊs1����С����s2����С����
	int i,min1=0x3f3f3f3f,min2=0x3f3f3f3f;//�������ֵ
	for(i=1; i<=n; i++)
	{
		if(HT[i].weight<min1&&HT[i].parent==0)
		{
			min1=HT[i].weight;
			s1=i;
		}
	}
	int temp=HT[s1].weight;//��ԭֵ���������Ȼ�������ֵ����ֹs1���ظ�ѡ��
	HT[s1].weight=0x3f3f3f3f;
	for(i=1; i<=n; i++)
	{
		if(HT[i].weight<min2&&HT[i].parent==0)
		{
			min2=HT[i].weight;
			s2=i;
		}
	}
	HT[s1].weight=temp;
}

void createHuffmanTree(HuffmanTree &HT, int n)
{
	//�����������HT
	int i, m, s1, s2;
	if (n<=1) return;
	m = 2 * n - 1;
	HT = new HTNode[m+1];  // 0�ŵ�Ԫδ��
	for (i=1; i<=m; i++)   //��ʼ��HT����
	{
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for (i=1; i<=n; i++)
		cin>>HT[i].weight;
	for (i=n+1; i<=m; i++)    // ����������
	{
		//��HT[1..i-1]��ѡ��parentΪ0��weight��С��������㣬 ����ŷֱ�Ϊs1(��С)��s2(��С)
		select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	return;
}

void createHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
	//--- ��Ҷ�ӵ���������ÿ���ַ��Ĺ��������� ---
	char *cd = new char[n];    // ���������Ĺ����ռ�
	cd[n-1] = '\0';  // �����������
	int i,c,f,start;
	for (i=1; i<=n; ++i)
	{
		start = n-1;
		c=i, f=HT[i].parent;
		while(f)// ��Ҷ�ӵ������������
		{
			--start;
			if (HT[f].lchild==c) cd[start] = '0';
			else cd[start] = '1';
			c=f,f=HT[f].parent;
		}
		HC[i] = new char[n-start];// Ϊ��i���ַ��������ռ�
		strcpy(HC[i], &cd[start]);    // ��cd���Ʊ���(��)��HC
	}
}

int main()
{
	int i,n;
	int *w;
	HuffmanTree HT;
	HuffmanCode HC;
	scanf("%d",&n);  //Ȩֵ����
	HC=new char*[n+1]; //0�ռ�δ��
	createHuffmanTree(HT,n);
	createHuffmanCode(HT,HC,n);
	for (i = 1; i<=n; i++)
		printf("%s\n",HC[i]);  //�������������
}
