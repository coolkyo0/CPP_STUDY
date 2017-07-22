/**
* 弄清楚赋值运算符参数与返回采用引用的好处。
*
* @结论 
*/
#pragma once

#include <iostream>
using namespace std;

#define RT_QUOTA_PAR_NOTQUOTA


class CAssignQuota
{
public:
	int m_test;
	static int ci;
	int temp;
public:
	CAssignQuota()
	{
		ci += 1;
		temp = ci;
		//cout << "默认构造, num = " << ci << endl;
		cout << "默认构造, num = " << ci << endl;
		m_test = 0;
	}
	CAssignQuota(int par) : m_test(par)
	{
		ci += 1;
		temp = ci;
		m_test = par;
		//cout << "整形构造, num = " << ci << endl;
		cout << "整形构造, num = " << ci << endl;
	}
	CAssignQuota(CAssignQuota& par)
	{
		ci += 1;
		temp = ci;
		if (&par != this)
		{
			m_test = par.m_test;
		}

		//cout << "赋值构造, this = " << this << ", num = " << ci << endl;
		cout << "赋值构造， num = " << ci << endl;
	}

	~CAssignQuota()
	{
		//cout << "析构函数, this = " << this << ", num = " << temp << endl;
		cout << "~~~析构函数, num = " << temp << endl;
	}

	/**
	* 
	* @返回值不为引用时，return会以*this作为对象重新构造一个返回
	*
	*/
	CAssignQuota& operator = (CAssignQuota& par)
	{
		if (&par != this)
		{
			m_test = par.m_test;
		}

		//cout << "重载'=', this = " << this << endl;
		return *this;
	}
};
int CAssignQuota::ci = 0;


CAssignQuota printMemberRt(CAssignQuota cqa)
{
	//cout << "cqa = " << &cqa << endl;
	//cout << "m_test = " << cqa.m_test << endl;
	return cqa;
}

void printMember(CAssignQuota& cqa)
{
	//cout << "m_test = " << cqa.m_test << endl;
}

void funTestQuotaAdvantage()
{
	/**
	* CAssignQuota& operator = (CAssignQuota& par)
	* 
	* @结论1 当入参和返回值都为引用时，下面的代码执行2次构造：整形构造、赋值构造
	* @结论2 当入参为引用，返回值不为引用时，下面的代码执行2次构造：整形构造、赋值构造
	* @结论3 下面的代码不会触发重载的赋值操作符，只会触发构造函数。
	*/
	
//  	CAssignQuota cq1(1);
//  	CAssignQuota cq2 = cq1;
	

	/**
	* CAssignQuota& operator = (CAssignQuota& par)
	*
	* @结论1 当入参和返回值都为引用时，下面的代码只执行2次构，整形构造、默认构造、重载'='
	* @结论2 当入参为引用，返回值不为引用时，下面的代码执行2次构造：整形构造、默认构造、重载'='
	* @结论3 赋值的返回值是否为引用均不会触发构造函数。
	* @结论4 当入参不为引用时，函数会根据参数调用"赋值构造"生成一个一模一样的临时对象。

	* @疑问1 
	*/

// 	CAssignQuota cq1(1);
// 	CAssignQuota cq2;
// 	cq2 = cq1;

	/**
	* printMember调用时，入参是否为引用的好处研究
	*
	* @结论 printMember入参不为引用时，会以cq1为对象调用赋值构造函数生成一个临时对象。
	* @结论 printMember入参为引用时，入参相当于传了cq1的指针。
	* @
	*/
	
// 	CAssignQuota cq1(1);
// 	printMember(cq1);

	/**
	* printMemberRt调用时，入参与返回值是否为引用的好处研究
	*
	* @结论 当入参为引用、返回值不为引用时，调用2次构造函数：1，cq1的构造。2，函数返回值时以cq1引用为对象调用赋值构造。
	* @结论 当入参为引用、返回值为引用时，调用1次构造函数：1，cq1的构造。 注：入参使用的是cq1的引用，返回值也是cq1的引用。
	* @结论 当入参不为引用、返回值为引用时，调用2次构造函数：1，cq1的构造。 2，以cq1为对象调用赋值构造函数作为入参。 注：返回值即是以形参作为引用返回的。
	* @结论 当入参不为引用、返回值不为引用时，调用3次构造函数：1，cq1的构造。2，以cq1为对象调用赋值构造函数作为入参。3，以形参为对象调用赋值构造函数返回。
	*/
// 	CAssignQuota cq1(1);
// 	cout << "cq1 = " << &cq1 << endl;
// 	printMemberRt(cq1);



	/**
	* printMemberRt调用时，入参与返回值是否为引用的好处研究
	*
	* @结论 当入参不为引用、返回值不为引用时，调用3次构造函数：1，cq1的构造。2，函数返回值时以cq1引用为对象调用赋值构造。3，cq2的构造。
	* @结论 当入参、返回值均不为引用时，不论返回值有没有变量接收，返回时都会调用赋值构造函数生成一个对象，不论这个对象是否有对象接收，如果有对象接收，像下面这样的就是调用赋值构造接收。

// 	* @结论 当入参为引用、返回值为引用时，调用1次构造函数：1，cq1的构造。 注：入参使用的是cq1的引用，返回值也是cq1的引用。
// 	* @结论 当入参不为引用、返回值为引用时，调用2次构造函数：1，cq1的构造。 2，以cq1为对象调用赋值构造函数作为入参。 注：返回值即是以形参作为引用返回的。
// 	* @结论 当入参不为引用、返回值不为引用时，调用3次构造函数：1，cq1的构造。2，以cq1为对象调用赋值构造函数作为入参。3，以形参为对象调用赋值构造函数返回。
	*/
// 	CAssignQuota cq1(1);
// 	CAssignQuota cq2 = printMemberRt(cq1);



	/**
	* printMemberRt
	* @结论 入参返回值均不为构造时，系统调用了五次构造，这五次构造分别是
	* @1次	cq1 整形构造	CAssignQuota cq1(1);
	* @2次	cq2 默认构造	CAssignQuota cq2;
	* @3次	以cq1调用赋值构造生成一个对象作为入参 printMemberRt(cq1);
	* @4次	return时以第三次构造的对象为参数调用赋值构造生成对象返回
	* @5次	赋值构造哪里来的？很诡异啊！答：重载的赋值运算符没有返回引用，返回时会构造一个对象。
	*/
	CAssignQuota cq1(1);
	//CAssignQuota cq2;
	printMemberRt(cq1);



// 	CAssignQuota cq1(1);
// 	CAssignQuota cq2 = printMemberRt(cq1);









// 	CAssignQuota cq1;
// 	CAssignQuota cq2;
// 	cq2 = printMemberRt(cq1);








	//cout << "&cq1 = " << &cq1 << endl;
	//cout << "&cq2 = " << &cq2 << endl;
}