/**
* 第九章 面试题6 编程实现堆排序
*
* @核心思想	如何构建堆，找出堆中的最大值。
*
* 如何构建堆？
*
* int a[] = { 88, 68, 46, 59, 39, 20, 45, 97 };
*
*					88(0)
*			68(1)			46(2)
*		59(3)   39(4)  	20(5)	45(6)
*	97(7)
*
* 堆中的某个元素的索引位index，那么它的左右分别为：index * 2 + 1，index * 2 + 2，0 < index <= index << 1 即可满足取完数组中的所有元素.
*/
#pragma once
#include <iostream>
using namespace std;

int heapSize = 0;

/** 返回左子节点索引 */
int Left(int index)
{
	return ((index << 1) + 1);
}

/** 返回右子节点索引 */
int Right(int index)
{
	return ((index << 1) + 2);
}

/** 交换a、b的值 */
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/** 
* array[index]与其左、右子树进行递归对比 
* 用最大值替换array[index], index表示堆顶索引
*/
void maxHeapify(int array[], int index)
{
	int largest = 0;			/** 最大数 */
	int left = Left(index);		/** 左子节点索引 */
	int right = Right(index);	/** 右子节点索引 */

	/** 把largest赋为堆顶与其左子节点的较大者 */
	if ((left <= heapSize) && (array[left] > array[index]))
		largest = left;
	else
		largest = index;

	/** 把largest与堆顶的右子节点比较，取较大者*/
	if ((right <= heapSize) && (array[right] > array[largest]))
		largest = right;

	/** 此时largest为堆顶、左子节点、右子节点中的最大者 */
	if (largest != index)
	{
		/** 如果堆顶不是最大者，则交换，并递归调整堆 */
		swap(&array[index], &array[largest]);
		maxHeapify(array, largest);

	}
}

/**
* 初始化堆，将数组中的每一个元素放到适当的位置 
* 完成之后，堆顶的元素为数组的最大值

* 核心思想是把一个数组构建成堆，然后找出堆中的最大值，交换到最后一个位置，和选择排序有点像
*
*/
void buildMaxHeap(int array[], int length)
{
	int i;
	heapSize = length;	/** 堆大小为数组长度 */
	for (i = (length >> 1); i >= 0; i--)
		maxHeapify(array, i);
}

void heapSort(int array[], int length)
{
	int i;

	/** 初始化堆 */
	buildMaxHeap(array, (length - 1));

	for (i = (length - 1); i >= 1; i--)
	{
		/** 堆顶元素array[0]（数组的最大值）被置换到数组的尾部array[i] */
		swap(&array[0], &array[i]);
		heapSize--;				/** 从堆中移除该元素 */
		maxHeapify(array, 0);	/** 重建堆 */
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