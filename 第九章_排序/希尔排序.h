/**
* 第九章 第二节 希尔排序
*
*/
#pragma once
#include <iostream>
using namespace std;




void shellSort(int a[], int len)
{
	int h, i, j, temp;
	int insertCnt = 0;

	for (h = len / 2; h > 0; h = h / 2)	/** 控制增量 */
	{
		for (i = h; i < len; i++)		/** 这个for循环就是前面的直接插入排序 */
		{
			temp = a[i];
			for (j = i - h; j >= 0 && temp < a[j]; j -= h)
			{
				a[j + h] = a[j];
				insertCnt += 1;
			}
			a[j + h] = temp;
		}
	}

	cout << "插入排序的次数： " << insertCnt << endl;
}

void printArray_9_2(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void fun9_2_shellSort()
{
	//int a[] = { 7, 3, 5, 8, 9, 1, 2, 4, 6, 10, 11, 4, 3, 89, 10, 2, 3, 6, 7, 3, 1, 7, 9, 11, 31, 21, 54, 46, 74, 37 };
	//int a[] = { 7, 3, 5, 8, 9, 1, 2, 4 };
	//int a[] = { 3, 1, 4, 3, 1 };
	int a[] = { 3, 1, 4, 3, 1, 3, 1, 4, 3, 1 };
	int aLen = sizeof(a) / sizeof(a[0]);
	cout << "before insert sort: ";
	printArray_9_2(a, aLen);
	shellSort(a, aLen);	/** 进行直接插入排序 */

	cout << "after insert sort: ";
	printArray_9_2(a, aLen);
}