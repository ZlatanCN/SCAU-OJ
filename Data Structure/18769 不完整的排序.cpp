#include <stdio.h>

/**
 * @brief �������еĸ������������ǰ�벿�֣���������������ĺ�벿��
 * @param Num ����ָ��
 * @param length ���鳤��
 */
void Reorder(int Num[], int length)
{
	// ������鳤��Ϊ1��0������Ҫ��������
	if (length <= 1)
		return;

	// ��ʼ������ָ�룬�ֱ�ָ���������ʼ�ͽ�β
	int low = 0, high = length - 1;

	// ��ʼɨ������
	while (low < high)
	{
		// ���lowָ��ָ���Ԫ���Ǹ�������ָ������ƶ�
		while (Num[low] < 0 && low < high)
			low++;

		// ���highָ��ָ���Ԫ������������ָ����ǰ�ƶ�
		while (Num[high] > 0 && low < high)
			high--;

		// ���lowָ��ָ���Ԫ����������highָ��ָ���Ԫ���Ǹ������򽻻�������Ԫ��
		int temp = Num[low];
		Num[low] = Num[high];
		Num[high] = temp;
	}
}

int main()
{
	int T, length;
	scanf("%d", &T);

	// ѭ����ȡÿ������
	for (int i = 1; i <= T; i++)
	{
		scanf("%d", &length);
		int Num[length];
		for (int j = 0; j < length; j++)
			scanf("%d", &Num[j]);

		// ����Reorder����������������
		Reorder(Num, length);

		// ����������к������
		for (int j = 0; j < length; j++)
			printf("%d ", Num[j]);
		printf("\n");
	}
	return 0;
}

