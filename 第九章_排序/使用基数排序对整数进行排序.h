/**
* �ھ��� ������7 ʹ�û��������������������
*
* @
*
*/
#include <iostream>
#include <math.h>
#include "ϣ������.h"
using namespace std;

/**
* ���ҳ���Ϊlen����������Ԫ��
*/
int findMax(int a[], int len)
{
	int max = a[0];		/** max��a[0]��ʼ */
	for (int i = 1; i < len; i++)
	{
		if (max < a[i])		/** �������Ԫ�ر�max�� */
		{
			max = a[i];		/** �����¸�max��ֵ */
		}
	}
	return max;
}

/**
* ��������number�ж���λ
*/
int digitBits(int number)
{
	int digit = 0;
	do 
	{
		number /= 10;
		digit++;
	} while (number != 0);

	return digit;
}

/**
* ��������number�ϵ�Kthλ������
*
*/
int kthDigit(int number, int Kth)
{
	number /= pow(10, Kth);

	return number % 10;
}

/**
* �Գ���Ϊlen��������л�������
*/
void radixSort(int a[], int len)
{
	int* temp[10];		/** ָ�����飬ÿһ��ָ���ʾһ������ */
	int count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };	/** ���ڴ洢ÿ������װ����Ԫ�� */
	int max = findMax(a, len);		/** ȡ�������е�������� */
	int maxDigit = digitBits(max);	/** �õ����������λ�� */
	int i, j, k;
	for (i = 0; i < 10; i++)
	{
		temp[i] = new int[len];		/** ʹÿһ��������װ��len��intԪ�� */
		memset(temp[i], 0, sizeof(int) * len);	/** ��ʼ��Ϊ0 */
	}

	for (i = 0; i < maxDigit; i++)
	{
		memset(count, 0, sizeof(int) * 10);		/** ÿ��װ��ǰ��count��� */
		for (j = 0; j < len; j++)
		{
			int xx = kthDigit(a[j], i);		/** �����ݰ�װλ�����뵽�ݴ������� */
			temp[xx][count[xx]] = a[j];
			count[xx]++;					/** �����ӵļ������� */
		}
		int index = 0;
		for (j = 0; j < 10; j++)			/** ��������ݴ�������ȡ�أ�����ԭʼ������ */
		{
			for (k = 0; k < count[j]; k++)	/** �����������е�Ԫ�ض�ȡ�ص�ԭʼ���� */
			{
				a[index++] = temp[j][k];
			}
		}
	}

}

void fun9_8radixSort()
{
	int a[] = { 22, 32, 19, 53, 47, 29 };
	int aLen = sizeof(a) / sizeof(a[0]);
	radixSort(a, aLen);

	printArray_9_2(a, aLen);
}