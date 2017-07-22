/**
* 本例主要是为了比较指针与数组的区别，以及不同定义方式的数组是指针还是数组
*
*/

#include <iostream>
#include <stdlib.h>

using namespace std;


void charArrPointerDiff()
{
	char arr1[] = "Hello World";
	char arr2[20] = "Hello World";

	char* parr1 = arr1;
	char* parr2 = arr2;

	char* parr1Incre = arr1 + 4;
	char* parr2Incre = arr2 + 4;

	cout << "parr1 = " << parr1 << " parr1 + 4 = " << parr1Incre << endl;
	cout << "parr2 = " << parr2 << " parr2 + 4 = " << parr2Incre << endl;
	cout << "arr1 = " << arr1 << " arr1 + 4 = " << arr1 + 4 << endl;
	cout << "arr2 = " << arr2 << " arr2 + 4 = " << arr2 + 4 << endl;


	int arr1IncreLen = (int)(arr1 + 4) - (int)(arr1);
	int arr2IncreLen = (int)(arr2 + 4) - (int)(arr2);
}

void intArrPointerDiff()
{
	int arr1[] = {0, 1, 2, 3, 4};
	int arr2[5];

	int* parr1 = arr1;
	int* parr2 = arr2;

	int* parr1Incre = arr1 + 4;
	int* parr2Incre = arr2 + 4;

	cout << "parr1 = " << parr1 << " parr1 + 4 = " << parr1Incre << endl;
	cout << "parr2 = " << parr2 << " parr2 + 4 = " << parr2Incre << endl;
	cout << "arr1 = " << arr1 << " arr1 + 4 = " << arr1 + 4 << endl;
	cout << "arr2 = " << arr2 << " arr2 + 4 = " << arr2 + 4 << endl;
}

/**
* 学习数组的特性
* @定义 int arr1[] = {0, 1, 2, 3, 4, 5}; int arr2[5]; 
*
* @结论 除了初始化部分，arr1和arr2都是指代数组名，并非arr1[]的定义方式就说arr1是指针。
* @结论 arr1 + 1、arr2 + 1的结构是数组地址增加一个元素步长。
* @结论 
*
*/
void intArrPointerPoniterDiff()
{
	/**
	* 非字符串数组定义的理解
	*/
	int iArr1[] = { 0, 1, 2, 3, 4 };
	int iArr2[5];

	cout << "sizeof(iArr1) = " << sizeof(iArr1) << endl;
	cout << "sizeof(iArr1) = " << sizeof(iArr2) << endl;

	cout << "下面的输出为十六进制：" << endl;
	cout << "iArr1 = " << iArr1 << ", iArr1 + 1 = " << iArr1 + 1 << ", &iArr1 + 1 = " << &iArr1 + 1 << endl;
	cout << "iArr2 = " << iArr2 << ", iArr2 + 1 = " << iArr2 + 1 << ", &iArr2 + 1 = " << &iArr2 + 1 << endl;


	/**
	* 字符串数组定义的理解
	*
	* @定义 char cArr1[] = "Hello"; char cArr2[10];
	* @结论 数组名cArr1与cArr2具有相同的特征，cArr1 + 1、cArr2 + 1效果一样，得到的结果都是数组地址增加一个元素步长的距离
	* @结论 size在计算字符串时会计算字符串结束符'\0'，strlen计算的是字符串的长度，从名字也可以理解他们的含义，sizeof是该数据对象占有的空大小，strlen只是计算字符串的长度，因为字符串是不含有'\0'的。
	*/

	char cArr1[] = "Hello";
	char cArr2[10];

	cout << "sizeof(cArr1) = " << sizeof(cArr1) << endl;
	cout << "sizeof(cArr2) = " << sizeof(cArr2) << endl;

	cout << "下面的输出为十进制：" << endl;
	cout << "cArr1 = " << (int)cArr1 << ", cArr1 + 1 = " << (int)(cArr1 + 1) << ", &cArr1 + 1 = " << (int)(&cArr1 + 1) << endl;
	cout << "cArr2 = " << (int)cArr1 << ", cArr2 + 1 = " << (int)(cArr2 + 1) << ", &cArr2 + 1 = " << (int)(&cArr2 + 1) << endl;
	

// 	int arr1Addr = (int)arr1;
// 	int arr2Addr = (int)arr2;

	//sizeof(数组)的大小
// 	int arr1Size = sizeof(arr1);
// 	int arr2Size = sizeof(arr2);
// 
// 	int stepLen1 = (int)(arr1Addr + arr1Size * power);
// 	int stepLen2 = (int)(arr2Addr + arr2Size * power);
// 
// 	int stepLen3 = (int)(arr1Addr + arr1Size * power);
// 	int stepLen4 = (int)(arr2Addr + arr2Size * power);
// 
// 	cout << arr1Addr << " " << (int)(&arr1 + power) << " " << stepLen1 << endl;
// 	cout << arr2Addr << " " << (int)(&arr2 + power) << " " << stepLen2 << endl;

// 	char chArr1[] = "Hello World";
// 	char chArr2[16] = "Hello World";
// 
// 	cout << (int)chArr1 << " " << (int)(&chArr1 + power) << " " << (int)(chArr1 + sizeof(chArr1) * power) << endl;
// 	cout << (int)chArr2 << " " << (int)(&chArr2 + power) << " " << (int)(chArr2 + sizeof(chArr2) * power) << endl;
}

/**
* 意外的收货, 十六进制 + 十进制 * 系数 = ？？， 得到的值有点诡异啊！！！！
* 懵逼了啊，为什么写了个hexAddDec函数又变得正常了？
*
*
*/
void hexAddDec()
{
	
	int hex = 0x10;		/** 16 */
	int dec = 10;


	int hexRt = hex + hex * 10;			/** 176 */
	int decRt = int(hex) + dec * 10;	/** 116 */
}


void main()
{
	//intArrPointerPoniterDiff();
	
	/**
	* 从intArrPointerDiff、charArrPointerDiff、intArrPointerPoniterDiff三个函数我们可知 char arr1[] = "Hello World";与char arr2[20] = "Hello World";的效果一样，
	* arr1[]、arr2[20]方式定义时arr1和arr2都是数组指针，以前我一直认为arr1[]的定义方式会把arr1当成指针(指针和数组是有区别的)，
	* 数组名 + 常量 = 数组[常量 - 1]; 我曾经认为：数组名 + 常量 = 数组[sizeof(数组) * sizeof(数组元素的宽度)]，其实我这么认为一直都是错误的，哎呀！！！！！！！
	* 取数组地址 + 常量 = 数组[sizeof(数组) * sizeof(数组元素的宽度)]， 这个才是对的呀！！！！！！一定要记住数组名只是一个单纯的指针，指针指向数组元素的首地址，
	* 而&arr1才是真正指向整个数组。
	*/

	//intArrPointerDiff();
	//charArrPointerDiff();


	hexAddDec();




	system("pause");
}