#include <iostream>
#include <algorithm>

using namespace std;

int n; // ���鳤��
int a[100000]; // ����һ������Ϊ100000�������������洢�����������

void InsertSort() // ��������
{
    int i, j, k; // ѭ��������
    for (i = 0; i < n - 1; i++) // ���ѭ�������Ʋ������������
    {
        if (a[i + 1] < a[i]) // �����һ��Ԫ��С��ǰһ��Ԫ�أ�����Ҫ���в�������
        {
            for (j = i; a[j] > a[j + 1]; j--) // �ڲ�ѭ��������ǰԪ�ز��뵽���ʵ�λ��
            {
                swap(a[j], a[j + 1]); // ���ǰһ��Ԫ�ش��ں�һ��Ԫ�أ��򽻻����ǵ�λ��
            }
        }
        for (k = 0; k < n; k++) // �����ǰ�ֵ�������
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n; // �������鳤��
    for (int i = 0; i < n; i++) // ��������������
    {
        cin >> a[i];
    }
    InsertSort(); // ���ò���������
    return 0;
}
