/**
* 学习要点 类中的const、static、const static成员变量在什么时候初始化？
*
* @结论 const 可以在类中定义时初始化或初始化列表中进行初始化。
* @结论 static 在实现文件中初始化，在类中定义只是什么哦，在实现文件中国要进行定义，可以不声明。
* @结论 const static 在类成员中进行初始化。

*
*/
#pragma once
#include <iostream>
using namespace std;

class VarWhenInit
{
public:
	VarWhenInit();
	virtual ~VarWhenInit();

	/**
	* 下面的3个变量就是本章要探讨的内容，初始化时间以及在哪里初始化？

	* @提示 刚看到提示：带有类内初始值的变量必须为常量
	*/
	const int m_i1 = 1;				/** 可以在类里初始化或初始化列表 */
	static int m_i2;				/** static变量在类中定义只是声明，需要在实现文件中定义，否则会出现ERROR LNK2001， 这个错误也就是找不到实现文件，意思就是只有定义没有实现！  */
	const static int m_i3 = 3;		/** 只能在类内进行初始化，可以在实现文件中定义，但是不可以初始化，因为const必须在构造时初始化，不能在初始化列表，因为static不属于类的对象 */
};

void fun13_4whenToInitVar();
