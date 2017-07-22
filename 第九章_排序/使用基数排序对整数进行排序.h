/**
* 第九章 面试题7 使用基数排序对整数进行排序
*
* @
*
*/
#include <iostream>
#include <math.h>
#include "希尔排序.h"
using namespace std;

/**
* 查找长度为len的数组的最大元素
*/
int findMax(int a[], int len)
{
	int max = a[0];		/** max从a[0]开始 */
	for (int i = 1; i < len; i++)
	{
		if (max < a[i])		/** 如果发现元素比max大 */
		{
			max = a[i];		/** 就重新给max赋值 */
		}
	}
	return max;
}

/**
* 计算整数number有多少位
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
* 返回整数number上第Kth位的数字
*
*/
int kthDigit(int number, int Kth)
{
	number /= pow(10, Kth);

	return number % 10;
}

/**
* 对长度为len的数组进行基数排序
*/
void radixSort(int a[], int len)
{
	int* temp[10];		/** 指针数组，每一个指针表示一个箱子 */
	int count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };	/** 用于存储每个箱子装多少元素 */
	int max = findMax(a, len);		/** 取得序列中的最大整数 */
	int maxDigit = digitBits(max);	/** 得到最大整数的位数 */
	int i, j, k;
	for (i = 0; i < 10; i++)
	{
		temp[i] = new int[len];		/** 使每一个箱子能装下len个int元素 */
		memset(temp[i], 0, sizeof(int) * len);	/** 初始化为0 */
	}

	for (i = 0; i < maxDigit; i++)
	{
		memset(count, 0, sizeof(int) * 10);		/** 每次装箱前把count清空 */
		for (j = 0; j < len; j++)
		{
			int xx = kthDigit(a[j], i);		/** 将数据安装位数放入到暂存数组中 */
			temp[xx][count[xx]] = a[j];
			count[xx]++;					/** 此箱子的计数递增 */
		}
		int index = 0;
		for (j = 0; j < 10; j++)			/** 将数组从暂存数组中取回，放入原始数组中 */
		{
			for (k = 0; k < count[j]; k++)	/** 把箱子里所有的元素都取回到原始数组 */
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