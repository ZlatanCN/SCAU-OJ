#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#define TRUE  1
#define FALSE  0
#define OK  1
#define ERROR  0
#define INFEASLBLE  -1
#define OVERFLOW  -2
#define MAXSTRLEN  255  //�û�����255���ڶ�����󴮳�
typedef unsigned char SString[MAXSTRLEN+1]; //0�ŵ�Ԫ��Ŵ��ĳ���
using namespace  std;

void get_next(SString T,int next[])
{
// �㷨4.7
// ��ģʽ��T��next����ֵ����������next
	int i=1,j=0;
	next[1]=0; //��ʼ��next[1]=0
	while(i<=T[0])
	{
		if(j==0||T[i]==T[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else j=next[j];
	}
}

int Index_KMP(SString S,SString T,int pos)
{
// �㷨4.6
// ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ��
// KMP�㷨��
	int next[MAXSTRLEN+1]; //����next����
	get_next(T,next); //���T��next����
	int i=pos,j=0; //i���ڱ�������S��j���ڱ���ģʽ��T
	while(i<=S[0]&&j<=T[0]) //����S��T
	{
		if(j==0||S[i]==T[j]) //���S[i]��T[j]��ȣ�����j�Ѿ��˻ص�ģʽ���ĵ�һ���ַ�
		{
			++i; //i��j����1
			++j;
		}
		else
		{
			j=next[j]; //j�˻ص�next[j]
		}
	}
	if(j >= T[0]) return i-T[0]; //���ƥ��ɹ�������ƥ��λ��
	else return 0; //���򣬷���0
}

int main()
{
	SString T,S; //���������ַ���
	int i,j,n;
	char ch;
	int pos; //����ƥ��λ�ñ���
	scanf("%d",&n);    // ָ��n�������ģʽƥ����ַ���
	ch=getchar(); //���뻻�з�
	for(j=1; j<=n; j++) //ѭ������n���ַ���
	{
		ch=getchar(); //�����һ���ַ�
		for( i=1; i<=MAXSTRLEN&&(ch!='\n'); i++)  // ¼������
		{
			S[i]=ch; //���ַ���������
			ch=getchar(); //����������һ���ַ�
		}
		S[0]=i-1;    // S[0]���ڴ洢�������ַ�����
		ch=getchar(); //���뻻�з�
		for( i=1; i<=MAXSTRLEN&&(ch!='\n'); i++)  // ¼��ģʽ��
		{
			T[i]=ch; //���ַ�����ģʽ��
			ch=getchar(); //����������һ���ַ�
		}
		T[0]=i-1;    // T[0]���ڴ洢ģʽ�����ַ�����
		pos=  Index_KMP(S,T,0)     ;    // ����KMP�㷨��ģʽ���������е�ƥ��λ��
		printf("%d\n",pos); //���ƥ��λ��
	}
}

