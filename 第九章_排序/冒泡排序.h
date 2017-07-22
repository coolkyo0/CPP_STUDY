/**
* �ھ��� ������3 ���ʵ��ð������
*
*
*
*/
#pragma once

#include "��������.h"
#include <iostream>

using namespace std;

/**
* �Ż���Ĵ���
* @note �Ż���ĺ�����ѡ������
*/
void bubbleSort1Optimize(int a[], int len)
{
	/**
	* temp���ڽ���
	* exchange���ڼ�¼ÿ��ɨ��ʱ�Ƿ�������
	* ��Сֵ��С��
	*/
	int i = 0, j = 0, temp = 0, minIndex = 0;

	for (i = 0; i <= len - 1; i++)		/** ����n-1��ɨ�� */
	{
		minIndex = len - 1;
		for (j = len - 1; j >= i; j--)	/** �Ӻ���ǰ������������С��ֵð�ݵ���ͷ�Ĳ��� */
		{
			if (a[j] < a[minIndex])		/** ���a[j]С��a[j + 1]����������Ԫ�ص�ֵ */
			{
				/** ��¼����Сֵ���±��ֵ */
				minIndex = j;
			}
		}

		/** �±�Ϊi����j���� */
		if (i != minIndex)
		{
			temp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = temp;
		}
	}

}

/**
* ���ϵ�ԭ����룬��BUG
*/
void bubbleSort2(int a[], int len)
{
	/**
	* temp���ڽ���
	* exchange���ڼ�¼ÿ��ɨ��ʱ�Ƿ�������
	*/
	int i = 0, j = 0, temp = 0, exchange = 0;

	for (i = 0; i < len - 1; i++)		/** ����n-1��ɨ�� */
	{
		exchange = 0;					/** ÿ��ɨ��֮ǰ��exchange��0 */
		for (j = len - 1; j >= i; j--)	/** �Ӻ���ǰ������������С��ֵð�ݵ���ͷ�Ĳ��� */
		{
			if (a[j + 1] < a[j])		/** ���a[j]С��a[j + 1]����������Ԫ�ص�ֵ */
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				exchange = 1;			/** ����������exchange��1 */
			}
		}

		if (exchange != 1)				/** ����ɨ��û�з����������� ˵���Ѿ������� */
			return;						/** ����Ҫ�����´�ɨ�� */
	}

}

/**
* ���ϵĴ��룬�޸�BUG���
*/
void bubbleSort1(int a[], int len)
{
	/**
	* temp���ڽ���
	* exchange���ڼ�¼ÿ��ɨ��ʱ�Ƿ�������
	*/
	int i = 0, j = 0, temp = 0, exchange = 0;

	for (i = 0; i <= len - 1; i++)		/** ����n-1��ɨ�� */
	{
		exchange = 0;					/** ÿ��ɨ��֮ǰ��exchange��0 */
		for (j = len - 1; j > i; j--)	/** �Ӻ���ǰ������������С��ֵð�ݵ���ͷ�Ĳ��� */
		{
			if (a[j] < a[j - 1])		/** ���a[j]С��a[j + 1]����������Ԫ�ص�ֵ */
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				exchange = 1;			/** ����������exchange��1 */
			}
		}

		if (exchange != 1)				/** ����ɨ��û�з����������� ˵���Ѿ������� */
			return;						/** ����Ҫ�����´�ɨ�� */
	}

}

void fun9_3bubbleSort()
{
	//int a[] = { 7, 3, 5, 8, 9, 1, 2, 4, 6 };
	int a[] = { 7, 3, 5, 8, 9, 1, 2, 4, 6, 10, 11, 4, 3, 89, 10, 2, 3, 6, 7, 3, 1, 7, 9, 11, 31, 21, 54, 46, 74, 37 };
	int aLen = sizeof(a) / sizeof(a[0]);
	cout << "before bubble sort: ";
	printArray(a, aLen);
	//bubbleSort1(a, aLen);					/** �Ľ���ð������ */
	//bubbleSort2(a, aLen);
	bubbleSort1Optimize(a, aLen);
	cout << "after bubble sort: ";
	printArray(a, aLen);
}