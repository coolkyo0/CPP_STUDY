/**
* 第九章 面试题7 归并排序（自顶向下）
* 
* @核心思想 1，排序需要一定得空间。2，拆分成2个数组。3，排序好的数组从缓冲数组拷贝回原数组。4，递归进行排序。
*/
#include <iostream>
using namespace std;

#include "插入排序.h"

/**
* 将分治的两端按大小次序填入临时数组，最后把临时数组拷贝到原始数组中
* lPos到rPos-1为一端，rPos到rEnd为另一端。
* lPos = left
* rPos = middle
* rEnd = right
*/
void merge(int a[], int tmp[], int lPos, int rPos, int rEnd)
{
	/**
	* i:			用于for循环访问数组成员的索引
	* lEnd:			分段数据右边的最小索引
	* NumElements:	参与排序的元素个数，数组索引right - left + 1
	* tmpPos:		复制到缓冲区的起始索引，也就是接收复制过来数据的起始数组索引
	*/
	int i, lEnd, NumElements, tmpPos;
	lEnd = rPos - 1;
	tmpPos = lPos;					/** 从左端开始 */
	NumElements = rEnd - lPos + 1;	/** 数组长度 */

	while (lPos <= lEnd && rPos <= rEnd)
	{
		//if (a[lPos] <= a[lPos++])
		if (a[lPos] <= a[rPos])		/** 比较两端的元素值 */
			tmp[tmpPos++] = a[lPos++];	/** 把较小的值先放入tmp临时数组 */
		else
			tmp[tmpPos++] = a[rPos++];
	}

	/** 到这里，左端或右端只能有一端还可能含有剩余元素 */
	while (lPos <= lEnd)
	{
		tmp[tmpPos++] = a[lPos++];	/** 把左端剩余的元素放入tmp */
	}

	while (rPos <= rEnd)
	{
		tmp[tmpPos++] = a[rPos++];	/** 把右端剩余的元素放入tmp */
	}

	/** 把tmp中的数据拷贝回数组a中 */
	for (i = 0; i < NumElements; i++, rEnd--)
	{
		a[rEnd] = tmp[rEnd];
	}
}

void msort(int a[], int tmp[], int low, int high)
{
	if (low >= high)						/** 结束条件，原子节点return */
	{
		return;
	}

	int middle = (low + high) / 2;			/** 计算分裂点 */
	msort(a, tmp, low, middle);				/** 对子区间[low, middle]递归做归并排序 */
	msort(a, tmp, middle + 1, high);		/** 对子区间[middle+1,high]递归做归并排序 */
	merge(a, tmp, low, middle + 1, high);	/** 组合，把两个有序区合并为一个有序区 */
}

void mergeSort(int a[], int len)
{
	int* tmp = NULL;
	tmp = new int[len];					/** 分配临时数组空间 */
	if (tmp != NULL)
	{
		msort(a, tmp, 0, len - 1);		/** 调用msort归并排序 */
		delete []tmp;					/** 释放临时数组内存 */
	}
}

void fun9_7mergeSort()
{
	int a[8] = { 8, 6, 1, 3, 5, 2, 7, 4 };
	int aLen = sizeof(a) / sizeof(a[0]);
	mergeSort(a, 8);
	printArray_9_2(a, aLen);
}