/**
* ���麯������Ĵ�С��ϵ
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
* @���� ���ܸ��ࡢ�������ж����麯�������麯�����麯������ͳһ���麯�����У����sizeֻ�����ĸ��ֽ�
*/
void for7_17PureFunClassAndSubClassSize()
{
	cout << "sizeof(GeneralClass) = " << sizeof(GeneralClass) << endl;
	cout << "sizeof(PureVirtualClass) = " << sizeof(PureVirtualClass) << endl;
	cout << "sizeof(PureVAndVClass) = " << sizeof(PureVAndVClass) << endl;
	cout << "sizeof(A) = " << sizeof(A7_17) << endl;
	cout << "sizeof(B) = " << sizeof(B7_17) << endl;
}