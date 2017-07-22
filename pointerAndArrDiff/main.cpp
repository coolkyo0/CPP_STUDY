/**
* ������Ҫ��Ϊ�˱Ƚ�ָ��������������Լ���ͬ���巽ʽ��������ָ�뻹������
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
* ѧϰ���������
* @���� int arr1[] = {0, 1, 2, 3, 4, 5}; int arr2[5]; 
*
* @���� ���˳�ʼ�����֣�arr1��arr2����ָ��������������arr1[]�Ķ��巽ʽ��˵arr1��ָ�롣
* @���� arr1 + 1��arr2 + 1�Ľṹ�������ַ����һ��Ԫ�ز�����
* @���� 
*
*/
void intArrPointerPoniterDiff()
{
	/**
	* ���ַ������鶨������
	*/
	int iArr1[] = { 0, 1, 2, 3, 4 };
	int iArr2[5];

	cout << "sizeof(iArr1) = " << sizeof(iArr1) << endl;
	cout << "sizeof(iArr1) = " << sizeof(iArr2) << endl;

	cout << "��������Ϊʮ�����ƣ�" << endl;
	cout << "iArr1 = " << iArr1 << ", iArr1 + 1 = " << iArr1 + 1 << ", &iArr1 + 1 = " << &iArr1 + 1 << endl;
	cout << "iArr2 = " << iArr2 << ", iArr2 + 1 = " << iArr2 + 1 << ", &iArr2 + 1 = " << &iArr2 + 1 << endl;


	/**
	* �ַ������鶨������
	*
	* @���� char cArr1[] = "Hello"; char cArr2[10];
	* @���� ������cArr1��cArr2������ͬ��������cArr1 + 1��cArr2 + 1Ч��һ�����õ��Ľ�����������ַ����һ��Ԫ�ز����ľ���
	* @���� size�ڼ����ַ���ʱ������ַ���������'\0'��strlen��������ַ����ĳ��ȣ�������Ҳ����������ǵĺ��壬sizeof�Ǹ����ݶ���ռ�еĿմ�С��strlenֻ�Ǽ����ַ����ĳ��ȣ���Ϊ�ַ����ǲ�����'\0'�ġ�
	*/

	char cArr1[] = "Hello";
	char cArr2[10];

	cout << "sizeof(cArr1) = " << sizeof(cArr1) << endl;
	cout << "sizeof(cArr2) = " << sizeof(cArr2) << endl;

	cout << "��������Ϊʮ���ƣ�" << endl;
	cout << "cArr1 = " << (int)cArr1 << ", cArr1 + 1 = " << (int)(cArr1 + 1) << ", &cArr1 + 1 = " << (int)(&cArr1 + 1) << endl;
	cout << "cArr2 = " << (int)cArr1 << ", cArr2 + 1 = " << (int)(cArr2 + 1) << ", &cArr2 + 1 = " << (int)(&cArr2 + 1) << endl;
	

// 	int arr1Addr = (int)arr1;
// 	int arr2Addr = (int)arr2;

	//sizeof(����)�Ĵ�С
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
* ������ջ�, ʮ������ + ʮ���� * ϵ�� = ������ �õ���ֵ�е���찡��������
* �±��˰���Ϊʲôд�˸�hexAddDec�����ֱ�������ˣ�
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
	* ��intArrPointerDiff��charArrPointerDiff��intArrPointerPoniterDiff�����������ǿ�֪ char arr1[] = "Hello World";��char arr2[20] = "Hello World";��Ч��һ����
	* arr1[]��arr2[20]��ʽ����ʱarr1��arr2��������ָ�룬��ǰ��һֱ��Ϊarr1[]�Ķ��巽ʽ���arr1����ָ��(ָ����������������)��
	* ������ + ���� = ����[���� - 1]; ��������Ϊ�������� + ���� = ����[sizeof(����) * sizeof(����Ԫ�صĿ��)]����ʵ����ô��Ϊһֱ���Ǵ���ģ���ѽ��������������
	* ȡ�����ַ + ���� = ����[sizeof(����) * sizeof(����Ԫ�صĿ��)]�� ������ǶԵ�ѽ������������һ��Ҫ��ס������ֻ��һ��������ָ�룬ָ��ָ������Ԫ�ص��׵�ַ��
	* ��&arr1��������ָ���������顣
	*/

	//intArrPointerDiff();
	//charArrPointerDiff();


	hexAddDec();




	system("pause");
}