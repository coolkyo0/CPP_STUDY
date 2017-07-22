/**
* 第九章 面试题3 编程实现冒泡排序
*
*
*
*/
#pragma once

#include "插入排序.h"
#include <iostream>

using namespace std;

/**
* 优化后的代码
* @note 优化后的函数是选择排序
*/
void bubbleSort1Optimize(int a[], int len)
{
	/**
	* temp用于交换
	* exchange用于记录每次扫描时是否发生交换
	* 最小值的小标
	*/
	int i = 0, j = 0, temp = 0, minIndex = 0;

	for (i = 0; i <= len - 1; i++)		/** 进行n-1趟扫描 */
	{
		minIndex = len - 1;
		for (j = len - 1; j >= i; j--)	/** 从后往前交换，这样最小的值冒泡到开头的部分 */
		{
			if (a[j] < a[minIndex])		/** 如果a[j]小于a[j + 1]，交换两个元素的值 */
			{
				/** 记录下最小值的下标和值 */
				minIndex = j;
			}
		}

		/** 下标为i的与j交换 */
		if (i != minIndex)
		{
			temp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = temp;
		}
	}

}

/**
* 书上的原版代码，有BUG
*/
void bubbleSort2(int a[], int len)
{
	/**
	* temp用于交换
	* exchange用于记录每次扫描时是否发生交换
	*/
	int i = 0, j = 0, temp = 0, exchange = 0;

	for (i = 0; i < len - 1; i++)		/** 进行n-1趟扫描 */
	{
		exchange = 0;					/** 每趟扫描之前对exchange置0 */
		for (j = len - 1; j >= i; j--)	/** 从后往前交换，这样最小的值冒泡到开头的部分 */
		{
			if (a[j + 1] < a[j])		/** 如果a[j]小于a[j + 1]，交换两个元素的值 */
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				exchange = 1;			/** 发生交换，exchange置1 */
			}
		}

		if (exchange != 1)				/** 此趟扫描没有发生过交换， 说明已经是排序 */
			return;						/** 不需要进行下次扫描 */
	}

}

/**
* 书上的代码，修复BUG后的
*/
void bubbleSort1(int a[], int len)
{
	/**
	* temp用于交换
	* exchange用于记录每次扫描时是否发生交换
	*/
	int i = 0, j = 0, temp = 0, exchange = 0;

	for (i = 0; i <= len - 1; i++)		/** 进行n-1趟扫描 */
	{
		exchange = 0;					/** 每趟扫描之前对exchange置0 */
		for (j = len - 1; j > i; j--)	/** 从后往前交换，这样最小的值冒泡到开头的部分 */
		{
			if (a[j] < a[j - 1])		/** 如果a[j]小于a[j + 1]，交换两个元素的值 */
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				exchange = 1;			/** 发生交换，exchange置1 */
			}
		}

		if (exchange != 1)				/** 此趟扫描没有发生过交换， 说明已经是排序 */
			return;						/** 不需要进行下次扫描 */
	}

}

void fun9_3bubbleSort()
{
	//int a[] = { 7, 3, 5, 8, 9, 1, 2, 4, 6 };
	int a[] = { 7, 3, 5, 8, 9, 1, 2, 4, 6, 10, 11, 4, 3, 89, 10, 2, 3, 6, 7, 3, 1, 7, 9, 11, 31, 21, 54, 46, 74, 37 };
	int aLen = sizeof(a) / sizeof(a[0]);
	cout << "before bubble sort: ";
	printArray(a, aLen);
	//bubbleSort1(a, aLen);					/** 改进的冒泡排序 */
	//bubbleSort2(a, aLen);
	bubbleSort1Optimize(a, aLen);
	cout << "after bubble sort: ";
	printArray(a, aLen);
}