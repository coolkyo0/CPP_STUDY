/**
* �ھ��� ������7 �鲢�����Զ����£�
* 
* @����˼�� 1��������Ҫһ���ÿռ䡣2����ֳ�2�����顣3������õ�����ӻ������鿽����ԭ���顣4���ݹ��������
*/
#include <iostream>
using namespace std;

#include "��������.h"

/**
* �����ε����˰���С����������ʱ���飬������ʱ���鿽����ԭʼ������
* lPos��rPos-1Ϊһ�ˣ�rPos��rEndΪ��һ�ˡ�
* lPos = left
* rPos = middle
* rEnd = right
*/
void merge(int a[], int tmp[], int lPos, int rPos, int rEnd)
{
	/**
	* i:			����forѭ�����������Ա������
	* lEnd:			�ֶ������ұߵ���С����
	* NumElements:	���������Ԫ�ظ�������������right - left + 1
	* tmpPos:		���Ƶ�����������ʼ������Ҳ���ǽ��ո��ƹ������ݵ���ʼ��������
	*/
	int i, lEnd, NumElements, tmpPos;
	lEnd = rPos - 1;
	tmpPos = lPos;					/** ����˿�ʼ */
	NumElements = rEnd - lPos + 1;	/** ���鳤�� */

	while (lPos <= lEnd && rPos <= rEnd)
	{
		//if (a[lPos] <= a[lPos++])
		if (a[lPos] <= a[rPos])		/** �Ƚ����˵�Ԫ��ֵ */
			tmp[tmpPos++] = a[lPos++];	/** �ѽ�С��ֵ�ȷ���tmp��ʱ���� */
		else
			tmp[tmpPos++] = a[rPos++];
	}

	/** �������˻��Ҷ�ֻ����һ�˻����ܺ���ʣ��Ԫ�� */
	while (lPos <= lEnd)
	{
		tmp[tmpPos++] = a[lPos++];	/** �����ʣ���Ԫ�ط���tmp */
	}

	while (rPos <= rEnd)
	{
		tmp[tmpPos++] = a[rPos++];	/** ���Ҷ�ʣ���Ԫ�ط���tmp */
	}

	/** ��tmp�е����ݿ���������a�� */
	for (i = 0; i < NumElements; i++, rEnd--)
	{
		a[rEnd] = tmp[rEnd];
	}
}

void msort(int a[], int tmp[], int low, int high)
{
	if (low >= high)						/** ����������ԭ�ӽڵ�return */
	{
		return;
	}

	int middle = (low + high) / 2;			/** ������ѵ� */
	msort(a, tmp, low, middle);				/** ��������[low, middle]�ݹ����鲢���� */
	msort(a, tmp, middle + 1, high);		/** ��������[middle+1,high]�ݹ����鲢���� */
	merge(a, tmp, low, middle + 1, high);	/** ��ϣ��������������ϲ�Ϊһ�������� */
}

void mergeSort(int a[], int len)
{
	int* tmp = NULL;
	tmp = new int[len];					/** ������ʱ����ռ� */
	if (tmp != NULL)
	{
		msort(a, tmp, 0, len - 1);		/** ����msort�鲢���� */
		delete []tmp;					/** �ͷ���ʱ�����ڴ� */
	}
}

void fun9_7mergeSort()
{
	int a[8] = { 8, 6, 1, 3, 5, 2, 7, 4 };
	int aLen = sizeof(a) / sizeof(a[0]);
	mergeSort(a, 8);
	printArray_9_2(a, aLen);
}