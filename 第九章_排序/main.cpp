/**
* 主要是学习第九章排序算法
*
*
*
*
*/

#include <iostream>
using namespace std;
#include "插入排序.h"
#include "希尔排序.h"
#include "冒泡排序.h"
#include "快速排序.h"
#include "6堆排序.h"
#include "7归并排序.h"
#include "使用基数排序对整数进行排序.h"
#include "C++群里的题目.h"

/**
* 想明白inline函数是否会增加类的大小
* @结论 inline函数不会增加类的大小
*
*/
class A
{
public:
	A(){}
	~A(){}

	inline void print()
	{

	}

private:
	int a;
};

void main()
{
	//fun9_1insertSort();
	//fun9_2_shellSort();

	//fun9_3bubbleSort();

	//fun9_4fastSort();

	//fun9_6heapSort();

	//fun();
	//arraySize();

	//cout << sizeof(A) << endl;

	//printf("%X, %#x, %#x\n", 11, 10, 111);

	//fun9_7mergeSort();

	fun9_8radixSort();

	system("pause");
}