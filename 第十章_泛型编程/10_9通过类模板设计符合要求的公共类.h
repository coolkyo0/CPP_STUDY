/**
* ��ʮ�� ������9 ͨ����ģ��ʵ�ַ���Ҫ��Ĺ�����
*
*/
#pragma once
#include <assert.h>
#include <iostream>
using namespace std;

template <class T>
bool ascend(T& a, T& b)		/** ����a��bСʱ����true */
{
	return a < b ? true : false;
}

template <class T>
bool descend(T& a, T& b)	/** ����a��b��ʱ����true */
{
	return a > b ? true : false;
}

template <class T>
class MyRect;

/** ���ز����� << */
template <class T>
ostream& operator << (ostream& out, MyRect<T>& rct)
{
	out << "(" << rct.len() << ", " << rct.wid() << ")";

	return out;
}

template <class T>
class Test
{
public:
	/**
	* ���������*�ڱ���ǰ�� void (*fun)()
	*/
	static void sort(T* array, int len, bool (*compare)(T& a, T& b))
	{
		T temp;		/** ����ð������Ľ��� */
		assert(len >= 1);	/** len�������1 */

		for (int i = 0; i < len - 1; i++)
		{
			for (int j = len - 1; j > i; j--)
			{
				/** ʹ��compare����ָ��ķ�ʽ�Ƚ� */
				if (compare(array[j], array[j - 1]))
				{
					temp = array[j - 1]; /** �������������Ҫ�������� */
					array[j - 1] = array[j];
					array[j] = temp;
				}
			}
		}
		
		printArray(array, len);
	}

	static void printArray(T* array, int len)
	{
		for (int i = 0; i < len; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

/**
* ��ģ������Ի�
*/
template <>
class Test<MyRect<int>>
{
public:
	static void sort(MyRect<int>* array, int len, bool(*compare)(MyRect<int>& a, MyRect<int>& b))
	{

	}
};

template <class T>
class MyRect
{
public:
	MyRect() : length(0), width(0){}
	MyRect(T len, T wid) : length(len), width(wid){}
	T  area(){ return length * width; }
	T len(){ return length; }
	T wid(){ return width; }
private:
	T length;
	T width;
};

/**
* ���� > ������Ҫ�з���ֵ
*/
template <class T>
bool operator > (MyRect<T>& rect1, MyRect<T>& rect2)
{
	return rect1.area() > rect2.area() ? true : false;
}

/**
* ���� < ������Ҫ�з���ֵ
*/
template <class T>
bool operator < (MyRect<T>& rect1, MyRect<T>& rect2)
{
	return rect1.area() < rect2.area() ? true : false;
}

template <class T>
void fun10_9printArray(T* array, int aLen)
{
	for (int i = 0; i < aLen; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

void fun10_9genericProgramming()
{
	int iArray[10] = { 4, 3, 7, 6, 2, 1, 9, 8, 5, 10 };
	float fArray[10] = { 4.0f, 3.0f, 7.0f, 6.0f, 2.0f, 1.0f, 9.0f, 8.0f, 5.0f, 10.0f };
	MyRect<int> rectArray[4] = { MyRect<int>(3, 4), MyRect<int>(5, 6), MyRect<int>(4, 6), MyRect<int>(3, 5) };

	Test<int>::sort(iArray, ARRAY_SIZE(iArray), ascend<int>);
	Test<float>::sort(fArray, ARRAY_SIZE(fArray), ascend<float>);
	Test<MyRect<int>>::sort(rectArray, ARRAY_SIZE(rectArray), ascend<MyRect<int>>);
}