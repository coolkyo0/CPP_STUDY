/**
* ��ʮ�� ������2 ����ģ�����ģ��ֱ���ʲô��
*
* @ѧϰ ����ѧϰ����ĸ�ֵ�����ΪʲôҪ�������ã��������ã� �봫�롢���ط����õ�������ʲô��
*
* @ע�� ������Ԫ������������� + ��"�޷��������ⲿ����"����ԭ���ǣ�http://blog.csdn.net/sinat_35261315/article/details/52852791
* @2017��4��23��00:50:03 �������������о�����Ԫ�����͸�ֵ�����뷵�����õĺô�~~~~~~~~~~~~������μ���Ŀ������֪ʶ���á�->�����Ը�ֵ������������õĺô���
*/
#pragma once
#include <iostream>
using namespace std;

template <class T1, class T2>
class Point_T
{
public:
	T1 a;		/** ��ԱaΪT1���� */
	T2 b;		/** ��ԱbΪT2���� */

public:
	Point_T() : a(0), b(0) {}							/** Ĭ�Ϲ��캯�� */
	Point_T(T1 ta, T2 tb) : a(ta), b(tb) {}				/** �������Ĺ��캯�� */
	Point_T<T1, T2>& operator = (Point_T<T1, T2>& pt);	/** ��ֵ���� */

	/**
	* ��Ԫ�����ĺô�
	*
	* @�ô� 
	*/
	template <class T1, class T2>
	friend Point_T<T1, T2> operator + (Point_T<T1, T2>& pt1, Point_T<T1, T2>& pt2);	/** ����+ */
};

template <class T1, class T2>
Point_T<T1, T2>& Point_T<T1, T2>::operator = (Point_T<T1, T2>& pt)
{
	if (this != &pt)
	{
		a = pt.a;
		b = pt.b;
	}

	return *this;
}

template <class T1, class T2>
Point_T<T1, T2> operator +(Point_T<T1, T2> &pt1, Point_T<T1, T2> &pt2)
{
	Point_T<T1, T2> temp;
	temp.a = pt1.a + pt2.a;
	temp.b = pt1.b + pt2.b;
	return temp;
	//return Point_T<T1, T2>(pt1.a + pt2.a, pt1.b + pt2.b);
}

template <class T1, class T2>
ostream& operator << (ostream& out, Point_T<T1, T2>& pt)	/** ��������������� */
{
	out << "(" << pt.a << ", " << pt.b << ")" << endl;
	return out;
}

void fun10_2funTemplateAndClassTemplate()
{
	Point_T<int, int> intPt1(1, 2);				/** T1��T2����int */
	Point_T<int, int> intPt2(3, 4);				/** T1��T2����int */
	Point_T<float, float> floatPt1(1.1f, 2.2f);	/** T1��T2����float */
	Point_T<float, float> floatPt2(3.3f, 4.4f);	/** T1��T2����float */
	
	Point_T<int, int> intTotalPt;
	Point_T < float, float > floatTotalPt;

	intTotalPt = intPt1 + intPt2;				/** ����ΪPoint_T<int, int>�Ķ������ */
	floatTotalPt = floatPt1 + floatPt2;			/** ����ΪPoint_T<float, float>�Ķ������ */

	cout << intTotalPt << endl;					/** ���Point_T<int, int>�Ķ��� */
	cout << floatTotalPt << endl;				/** ���Point_T<float, float>�Ķ��� */

	/**
	* ��֪����Ԫ�����Ƿ��ռ��Ŀռ��С��
	*
	* @���� ��û��ӡ���ǰ�Ȳ²���Ԫ������ռ�ĸ��ֽڣ���ôsizeof(Point_T<int, int>) = 12
	* @��֤	��ʵ֤����Ԫ�����ǲ�ռ���κοռ�ģ����������sizeof(Point_T<int, int>) = 8
	*/
	cout << "sizeof(Point_T<int, int>) = " << sizeof(Point_T<int, int>) << endl;
}