/**
* 第十章 面试题2 函数模板和类模板分别是什么？
*
* @学习 巩固学习下类的赋值运算符为什么要传入引用，返回引用？ 与传入、返回非引用的区别是什么？
*
* @注意 类中友元函数重载运算符 + 报"无法解析的外部符号"错误，原因是：http://blog.csdn.net/sinat_35261315/article/details/52852791
* @2017年4月23日00:50:03 早上起来继续研究下友元函数和赋值传入与返回引用的好处~~~~~~~~~~~~，详情参见项目《测试知识点用》->《测试赋值运算符传入引用的好处》
*/
#pragma once
#include <iostream>
using namespace std;

template <class T1, class T2>
class Point_T
{
public:
	T1 a;		/** 成员a为T1类型 */
	T2 b;		/** 成员b为T2类型 */

public:
	Point_T() : a(0), b(0) {}							/** 默认构造函数 */
	Point_T(T1 ta, T2 tb) : a(ta), b(tb) {}				/** 带参数的构造函数 */
	Point_T<T1, T2>& operator = (Point_T<T1, T2>& pt);	/** 赋值函数 */

	/**
	* 友元函数的好处
	*
	* @好处 
	*/
	template <class T1, class T2>
	friend Point_T<T1, T2> operator + (Point_T<T1, T2>& pt1, Point_T<T1, T2>& pt2);	/** 重载+ */
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
ostream& operator << (ostream& out, Point_T<T1, T2>& pt)	/** 重载输出流操作符 */
{
	out << "(" << pt.a << ", " << pt.b << ")" << endl;
	return out;
}

void fun10_2funTemplateAndClassTemplate()
{
	Point_T<int, int> intPt1(1, 2);				/** T1和T2都是int */
	Point_T<int, int> intPt2(3, 4);				/** T1和T2都是int */
	Point_T<float, float> floatPt1(1.1f, 2.2f);	/** T1和T2都是float */
	Point_T<float, float> floatPt2(3.3f, 4.4f);	/** T1和T2都是float */
	
	Point_T<int, int> intTotalPt;
	Point_T < float, float > floatTotalPt;

	intTotalPt = intPt1 + intPt2;				/** 类型为Point_T<int, int>的对象相加 */
	floatTotalPt = floatPt1 + floatPt2;			/** 类型为Point_T<float, float>的对象相加 */

	cout << intTotalPt << endl;					/** 输出Point_T<int, int>的对象 */
	cout << floatTotalPt << endl;				/** 输出Point_T<float, float>的对象 */

	/**
	* 不知道友元函数是否会占类的空间大小？
	*
	* @？？ 在没打印结果前先猜测友元函数会占四个字节，那么sizeof(Point_T<int, int>) = 12
	* @论证	事实证明友元函数是不占用任何空间的，我们输出的sizeof(Point_T<int, int>) = 8
	*/
	cout << "sizeof(Point_T<int, int>) = " << sizeof(Point_T<int, int>) << endl;
}