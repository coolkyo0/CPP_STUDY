/**
* 纯虚函数与类的大小关系
*
*
*/
#pragma once
#include <iostream>
using namespace std;

/** size = 1 */
class GeneralClass
{
public:
	GeneralClass(){}
	~GeneralClass(){}

private:

};

/** size = 1 */
class PureVirtualClass
{
public:
	PureVirtualClass(){}
	~PureVirtualClass(){}

	virtual void eat() = 0;
private:

};

/** size = 4 */
class PureVAndVClass
{
public:
	PureVAndVClass(){}
	~PureVAndVClass(){}

	//virtual void eat() = 0;
	virtual void sleep(){}
private:

};

/** size = 4 */
class A7_17 : public PureVirtualClass
{
public:
	virtual void afun() = 0;

private:

};

/** size = 4 */
class B7_17 : public PureVAndVClass
{
public:
	virtual void bfun(){}
private:

};

/**
* @结论 不管父类、子类中有多少虚函数、纯虚函数，虚函数都在统一的虚函数表中，类的size只增加四个字节
*/
void for7_17PureFunClassAndSubClassSize()
{
	cout << "sizeof(GeneralClass) = " << sizeof(GeneralClass) << endl;
	cout << "sizeof(PureVirtualClass) = " << sizeof(PureVirtualClass) << endl;
	cout << "sizeof(PureVAndVClass) = " << sizeof(PureVAndVClass) << endl;
	cout << "sizeof(A) = " << sizeof(A7_17) << endl;
	cout << "sizeof(B) = " << sizeof(B7_17) << endl;
}