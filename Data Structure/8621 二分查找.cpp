#include"malloc.h" /* malloc()�� */
#include"stdio.h"
#include"stdlib.h"

typedef int ElemType;
typedef struct /*��̬���ұ��˳��洢�ṹ */
{
	ElemType *elem; /* ����Ԫ�ش洢�ռ��ַ������ʱ��ʵ�ʳ��ȷ��䣬0�ŵ�Ԫ���� */
	int length; /* ���� */
} SSTable;

void Creat_Seq(SSTable &ST,int n)
{
	/* �������: ����һ����n������Ԫ�صľ�̬˳����ұ�ST(������������r) */
	int i,temp;
	ST.elem=(ElemType *)malloc((n+1) * sizeof(ElemType)); /* ��̬����n������Ԫ�ؿռ�(0�ŵ�Ԫ����) */
	if(!(ST).elem)
	{
		printf("ERROR\n");
		exit(0);
	} /*�ڴ����ʧ�ܽ�������*/
	for(i=1; i<=n; i++)
	{
		scanf("%d",&temp);
		*(ST.elem+i)=temp; /* ���θ�ֵ��ST */
	}
	ST.length=n;
}

int Search_Bin1(SSTable &ST, ElemType key)	//�ǵݹ��㷨
{
	/* ��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ */
	/* ��Ԫ���ڱ��е�λ�ã�����Ϊ0���㷨9.1 */
	int low = 1, high = ST.length, mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(ST.elem[mid] == key)
		{
			return mid - 1;
		}
		else if(key < ST.elem[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

int Search_Bin2(SSTable &ST, ElemType key, int low, int high)
{
	if(low >high)
	{
		return -1;
	}
	int mid = (low + high) / 2;
	if(key == ST.elem[mid])
	{
		return mid - 1;
	}
	else if(key < ST.elem[mid])
	{
		return Search_Bin2(ST, key, low, mid - 1);
	}
	else
	{
		return Search_Bin2(ST, key, mid + 1, high);
	}
}

int main()
{
	SSTable ST;
	int loc,key;
	int n;
	scanf("%d",&n);
	Creat_Seq(ST,n);
	//printf("Please input the key value��");
	scanf("%d",&key);
	//loc = Search_Bin1(ST,key);
	loc = Search_Bin2(ST,key,1,ST.length);
	if(loc >= 0)
		printf("The element position is %d.\n",loc);
	else
		printf("The element is not exist.\n");
}

