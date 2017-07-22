/**
* 快速排序.h
* 第九章 面试题4 编程实现快速排序
*
*/
#pragma once
#include <iostream>
using namespace std;

#include "插入排序.h"

/**
* 快速排序
* @核心思想 取第一个数作为分水岭pivot，把大于pivot的移到右面，小的移到左面
* @
*/
void quickSort(int a[], int low, int high)
{
	/**
	* pivot 中枢、枢轴
	*
	*/
	int i, j, pivot;
	if (low < high)
	{
		pivot = a[low];
		i = low;
		j = high;
		while (i < j)
		{
			while (i < j && a[j] >= pivot)
				j--;
			if (i < j)
				a[i++] = a[j];				/** 将比pivot小的的元素移到低端 */

			while (i < j && a[i] <= pivot)
				i++;
			if (i < j)
				a[j--] = a[i];				/** 将比pivot大的元素移到高端 */
		}
		a[i] = pivot;						/** pivot移到最终位置 */

		printArray(a, high - low + 1);

		quickSort(a, low, i - 1);			/** 对左区间递归排序 */
		quickSort(a, i + 1, high);			/** 对右区间进行排序 */
	}
}


void fun9_4fastSort()
{
	int data[9] = { 54, 38, 96, 23, 15, 72, 60, 45, 83 };
	//int data[9] = { 54, 38, 96, 23, 15, 72, 60, 45, 83 };
	//pivot = 54, i = 0,j = 7, { 54, 38, 96, 23, 15, 72, 60, 45, 83 }
	//pivot = 54, i = 1,j = 7, { 45, 38, 96, 23, 15, 72, 60, 45, 83 }
	//pivot = 54, i = 2,j = 7, { 45, 38, 96, 23, 15, 72, 60, 45, 83 }
	//pivot = 54, i = 2,j = 6, { 45, 38, 96, 23, 15, 72, 60, 96, 83 }
	//pivot = 54, i = 3,j = 4, { 45, 38, 15, 23, 15, 72, 60, 96, 83 }
	//pivot = 54, i = 4,j = 4, { 45, 38, 15, 23, 15, 72, 60, 96, 83 }
	//pivot = 54, i = 4,j = 4, { 45, 38, 15, 23, 54, 72, 60, 96, 83 }
	int maxIndex = sizeof(data) / sizeof(data[0]) - 1;
	quickSort(data, 0, maxIndex);
	for (int i = 0; i < 9; i++)
		cout << data[i] << " ";
}
