/**
* ��������.h
* �ھ��� ������4 ���ʵ�ֿ�������
*
*/
#pragma once
#include <iostream>
using namespace std;

#include "��������.h"

/**
* ��������
* @����˼�� ȡ��һ������Ϊ��ˮ��pivot���Ѵ���pivot���Ƶ����棬С���Ƶ�����
* @
*/
void quickSort(int a[], int low, int high)
{
	/**
	* pivot ���ࡢ����
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
				a[i++] = a[j];				/** ����pivotС�ĵ�Ԫ���Ƶ��Ͷ� */

			while (i < j && a[i] <= pivot)
				i++;
			if (i < j)
				a[j--] = a[i];				/** ����pivot���Ԫ���Ƶ��߶� */
		}
		a[i] = pivot;						/** pivot�Ƶ�����λ�� */

		printArray(a, high - low + 1);

		quickSort(a, low, i - 1);			/** ��������ݹ����� */
		quickSort(a, i + 1, high);			/** ��������������� */
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
