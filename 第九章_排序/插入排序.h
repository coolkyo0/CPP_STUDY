/**
* �ھ��� ������1 ���ʵ��ֱ�Ӳ�������
*
*
*/
#pragma once
#include <iostream>
using namespace std;

/** ֱ�Ӳ������� */
void insertSort(int a[], int n)
{
	int moveCnt = 0;	/** �ƶ����� */
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		/**
		* �ݴ��±�Ϊi�������±��1��ʼ����Ϊ��ʼʱ�±�Ϊ0������
		* ǰ��û���κ�������ʱ��Ϊ�����ź�˳���
		*/
		temp = a[i];
		for (j = i - 1; j >= 0 && temp < a[j]; j--)
		{
			a[j + 1] = a[j];
			moveCnt += 1;
		}

		/** �ҵ��±�Ϊi�����ķ���λ�� */
		a[j + 1] = temp;		
	}

	cout << "ֱ�Ӳ�������Ĵ���Ϊ�� " << moveCnt << endl;
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
	insertSort(a, aLen);	/** ����ֱ�Ӳ������� */

	cout << "after insert sort: ";
	printArray(a, aLen);
}