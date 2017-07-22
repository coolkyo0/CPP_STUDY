/**
* �ھ��� ������6 ���ʵ�ֶ�����
*
* @����˼��	��ι����ѣ��ҳ����е����ֵ��
*
* ��ι����ѣ�
*
* int a[] = { 88, 68, 46, 59, 39, 20, 45, 97 };
*
*					88(0)
*			68(1)			46(2)
*		59(3)   39(4)  	20(5)	45(6)
*	97(7)
*
* ���е�ĳ��Ԫ�ص�����λindex����ô�������ҷֱ�Ϊ��index * 2 + 1��index * 2 + 2��0 < index <= index << 1 ��������ȡ�������е�����Ԫ��.
*/
#pragma once
#include <iostream>
using namespace std;

int heapSize = 0;

/** �������ӽڵ����� */
int Left(int index)
{
	return ((index << 1) + 1);
}

/** �������ӽڵ����� */
int Right(int index)
{
	return ((index << 1) + 2);
}

/** ����a��b��ֵ */
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/** 
* array[index]���������������еݹ�Ա� 
* �����ֵ�滻array[index], index��ʾ�Ѷ�����
*/
void maxHeapify(int array[], int index)
{
	int largest = 0;			/** ����� */
	int left = Left(index);		/** ���ӽڵ����� */
	int right = Right(index);	/** ���ӽڵ����� */

	/** ��largest��Ϊ�Ѷ��������ӽڵ�Ľϴ��� */
	if ((left <= heapSize) && (array[left] > array[index]))
		largest = left;
	else
		largest = index;

	/** ��largest��Ѷ������ӽڵ�Ƚϣ�ȡ�ϴ���*/
	if ((right <= heapSize) && (array[right] > array[largest]))
		largest = right;

	/** ��ʱlargestΪ�Ѷ������ӽڵ㡢���ӽڵ��е������ */
	if (largest != index)
	{
		/** ����Ѷ���������ߣ��򽻻������ݹ������ */
		swap(&array[index], &array[largest]);
		maxHeapify(array, largest);

	}
}

/**
* ��ʼ���ѣ��������е�ÿһ��Ԫ�طŵ��ʵ���λ�� 
* ���֮�󣬶Ѷ���Ԫ��Ϊ��������ֵ

* ����˼���ǰ�һ�����鹹���ɶѣ�Ȼ���ҳ����е����ֵ�����������һ��λ�ã���ѡ�������е���
*
*/
void buildMaxHeap(int array[], int length)
{
	int i;
	heapSize = length;	/** �Ѵ�СΪ���鳤�� */
	for (i = (length >> 1); i >= 0; i--)
		maxHeapify(array, i);
}

void heapSort(int array[], int length)
{
	int i;

	/** ��ʼ���� */
	buildMaxHeap(array, (length - 1));

	for (i = (length - 1); i >= 1; i--)
	{
		/** �Ѷ�Ԫ��array[0]����������ֵ�����û��������β��array[i] */
		swap(&array[0], &array[i]);
		heapSize--;				/** �Ӷ����Ƴ���Ԫ�� */
		maxHeapify(array, 0);	/** �ؽ��� */
	}
}

void fun9_6heapSort()
{
	int a[8] = { 45, 68, 20, 39, 88, 97, 46, 59 };
	int maxIndex = sizeof(a) / sizeof(a[0]);
	heapSort(a, 8);
	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}