/**
* 第九章 面试题1 编程实现直接插入排序
*
*
*/
#pragma once
#include <iostream>
using namespace std;

/** 直接插入排序 */
void insertSort(int a[], int n)
{
	int moveCnt = 0;	/** 移动次数 */
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		/**
		* 暂存下标为i的数。下标从1开始，因为开始时下标为0的数，
		* 前面没有任何数，此时认为它是排好顺序的
		*/
		temp = a[i];
		for (j = i - 1; j >= 0 && temp < a[j]; j--)
		{
			a[j + 1] = a[j];
			moveCnt += 1;
		}

		/** 找到下标为i的数的放置位置 */
		a[j + 1] = temp;		
	}

	cout << "直接插入排序的次数为： " << moveCnt << endl;
}

void printArray(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void fun9_1insertSort()
{
	int a[] = { 7, 3, 5, 8, 9, 1, 2, 4, 6, 10, 11, 4, 3, 89, 10, 2, 3, 6, 7, 3, 1, 7, 9, 11, 31, 21, 54, 46, 74, 37 };
	int aLen = sizeof(a) / sizeof(a[0]);
	cout << "before insert sort: ";
	printArray(a, aLen);
	insertSort(a, aLen);	/** 进行直接插入排序 */

	cout << "after insert sort: ";
	printArray(a, aLen);
}