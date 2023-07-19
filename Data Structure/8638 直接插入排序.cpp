#include <iostream>
#include <algorithm>

using namespace std;

int n; // 数组长度
int a[100000]; // 定义一个长度为100000的整型数组来存储待排序的整数

void InsertSort() // 插入排序
{
    int i, j, k; // 循环计数器
    for (i = 0; i < n - 1; i++) // 外层循环，控制插入排序的轮数
    {
        if (a[i + 1] < a[i]) // 如果后一个元素小于前一个元素，则需要进行插入排序
        {
            for (j = i; a[j] > a[j + 1]; j--) // 内层循环，将当前元素插入到合适的位置
            {
                swap(a[j], a[j + 1]); // 如果前一个元素大于后一个元素，则交换它们的位置
            }
        }
        for (k = 0; k < n; k++) // 输出当前轮的排序结果
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n; // 输入数组长度
    for (int i = 0; i < n; i++) // 输入待排序的整数
    {
        cin >> a[i];
    }
    InsertSort(); // 调用插入排序函数
    return 0;
}
