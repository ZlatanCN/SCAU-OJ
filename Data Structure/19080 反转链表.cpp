#include <iostream>//C++标准输入输出头文件
using namespace std;
struct LNode // 定义链表结点
{
	int data; // 数据域
	LNode * next; // 指向下一个结点的指针
};

void createList(LNode * &L,int n) // 创建含有n个元素的单链表
{
	LNode *r, *p; // 定义尾指针r和临时指针p
	r = L = new LNode; // 创建头结点
	L->next = NULL; // 头结点的next指针指向NULL
	for (int i = 1; i <= n; i++)
	{
		p = new LNode; // 生成新结点
		cin >> p->data; // 输入元素的值
		p->next = NULL; // 新结点的next指针指向NULL
		r->next = p; // 将新结点插入到链表的尾部
		r = p; // 将尾指针r指向新结点
	}
}

void trv(LNode * L) // 遍历链表
{
	L = L->next; // 指向链表的第一个结点
	while (L)
	{
		cout << L->data << ' '; // 输出结点的值
		L = L->next; // 指向下一个结点
	}
}

void reverseList(LNode * &L) // 翻转链表
{
	LNode *pre = NULL; // 定义前驱指针pre
	LNode *cur = L->next; // 定义当前指针cur，初始值为第一个结点
	LNode *nex = NULL; // 定义后继指针nex
	while (cur)
	{
		nex = cur;//将当前节点保存在nex中
		cur = cur->next;//将cur指向下一个节点
		nex->next = pre;//将当前节点的next指针指向前一个节点，从而实现将链表翻转
		pre = nex;//将前一个节点指向当前节点，为下一次循环做准备
	}
	L->next = pre; // 将头结点的next指针指向新的第一个结点
}

int main()
{
	int n; // 定义链表长度
	LNode *L; // 定义链表头结点指针
	cin >> n; // 输入链表长度
	createList(L, n); // 创建链表
	reverseList(L); // 翻转链表
	trv(L); // 遍历链表
	return 0;
}

