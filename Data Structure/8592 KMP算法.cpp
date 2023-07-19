#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#define TRUE  1
#define FALSE  0
#define OK  1
#define ERROR  0
#define INFEASLBLE  -1
#define OVERFLOW  -2
#define MAXSTRLEN  255  //用户可在255以内定义最大串长
typedef unsigned char SString[MAXSTRLEN+1]; //0号单元存放串的长度
using namespace  std;

void get_next(SString T,int next[])
{
// 算法4.7
// 求模式串T的next函数值并存入数组next
	int i=1,j=0;
	next[1]=0; //初始化next[1]=0
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
// 算法4.6
// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置
// KMP算法。
	int next[MAXSTRLEN+1]; //声明next数组
	get_next(T,next); //求出T的next数组
	int i=pos,j=0; //i用于遍历主串S，j用于遍历模式串T
	while(i<=S[0]&&j<=T[0]) //遍历S和T
	{
		if(j==0||S[i]==T[j]) //如果S[i]和T[j]相等，或者j已经退回到模式串的第一个字符
		{
			++i; //i和j都加1
			++j;
		}
		else
		{
			j=next[j]; //j退回到next[j]
		}
	}
	if(j >= T[0]) return i-T[0]; //如果匹配成功，返回匹配位置
	else return 0; //否则，返回0
}

int main()
{
	SString T,S; //声明两个字符串
	int i,j,n;
	char ch;
	int pos; //声明匹配位置变量
	scanf("%d",&n);    // 指定n对需进行模式匹配的字符串
	ch=getchar(); //读入换行符
	for(j=1; j<=n; j++) //循环读入n对字符串
	{
		ch=getchar(); //读入第一个字符
		for( i=1; i<=MAXSTRLEN&&(ch!='\n'); i++)  // 录入主串
		{
			S[i]=ch; //将字符存入主串
			ch=getchar(); //继续读入下一个字符
		}
		S[0]=i-1;    // S[0]用于存储主串中字符个数
		ch=getchar(); //读入换行符
		for( i=1; i<=MAXSTRLEN&&(ch!='\n'); i++)  // 录入模式串
		{
			T[i]=ch; //将字符存入模式串
			ch=getchar(); //继续读入下一个字符
		}
		T[0]=i-1;    // T[0]用于存储模式串中字符个数
		pos=  Index_KMP(S,T,0)     ;    // 调用KMP算法求模式串在主串中的匹配位置
		printf("%d\n",pos); //输出匹配位置
	}
}

