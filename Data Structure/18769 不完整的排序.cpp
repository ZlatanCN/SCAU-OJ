#include <stdio.h>

/**
 * @brief 将数组中的负数放在数组的前半部分，将正数放在数组的后半部分
 * @param Num 数组指针
 * @param length 数组长度
 */
void Reorder(int Num[], int length)
{
	// 如果数组长度为1或0，则不需要重新排列
	if (length <= 1)
		return;

	// 初始化两个指针，分别指向数组的起始和结尾
	int low = 0, high = length - 1;

	// 开始扫描数组
	while (low < high)
	{
		// 如果low指针指向的元素是负数，则指针向后移动
		while (Num[low] < 0 && low < high)
			low++;

		// 如果high指针指向的元素是正数，则指针向前移动
		while (Num[high] > 0 && low < high)
			high--;

		// 如果low指针指向的元素是正数，high指针指向的元素是负数，则交换这两个元素
		int temp = Num[low];
		Num[low] = Num[high];
		Num[high] = temp;
	}
}

int main()
{
	int T, length;
	scanf("%d", &T);

	// 循环读取每组数据
	for (int i = 1; i <= T; i++)
	{
		scanf("%d", &length);
		int Num[length];
		for (int j = 0; j < length; j++)
			scanf("%d", &Num[j]);

		// 调用Reorder函数重新排列数组
		Reorder(Num, length);

		// 输出重新排列后的数组
		for (int j = 0; j < length; j++)
			printf("%d ", Num[j]);
		printf("\n");
	}
	return 0;
}

