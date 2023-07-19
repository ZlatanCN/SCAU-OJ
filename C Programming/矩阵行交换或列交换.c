#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*����һ��4*4���󣬱�д���������ֱ�ʵ�ֶԶ�ά����Ԫ�ص������н��н������Լ������н��н���

�����ʽ
����һ��4*4����

�����ʽ
��������任�ľ���

��������
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

�������
6 8 5 7
14 16 13 15
2 4 1 3
10 12 9 11*/

void swap(int *a, int *b)
{
    int temp;
    temp=*a;*a=*b;*b=temp;
}

void col(int a[][4], int i, int j)
{
    int k;
	for(k=0;k<4;k++)
	{
		swap(&a[i][k],&a[j][k]);
	}
}

void row(int a[][4], int i, int j)
{
	int k;
	for(k=0;k<4;k++)
	{
		swap(&a[k][i],&a[k][j]);
	}
}

int main()
{
    int a[4][4];
    int i,j;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            scanf("%d", &a[i][j]);
    col(a,0,2);
    row(a,0,2);
    col(a,1,3);
    row(a,1,3);
    col(a,0,3);
    row(a,0,3);
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}


