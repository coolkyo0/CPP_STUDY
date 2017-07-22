/**
* 调查引用是否与指针一样也可以进行多态调用？
*
*/
#pragma once
#include <iostream>
using namespace std;

class Person
{
public:
	virtual void print() const{ cout << "I'm a person" << endl; }
};

class China : public Person
{
public:
	void print() const{ cout << "I'm a China" << endl; }
};

class American : public Person
{
public:
	void print() const{ cout << "I'm a American" << endl; }
};

/**
* 引用可否像指针一样实现多态呢？
*
* @结论 引用和指针一样可以实现多态特性，引用是狭隘的指针！
*/
void printPerson(const Person& p)
{
	p.print();
}

void for7_6Q1()
{
	Person p;
	China c;
	American a;

	printPerson(p);
	printPerson(c);
	printPerson(a);
}


void for7_9Test()
{
	Person p, p1;
	China c, c1;

	p = c;

	/**
	* 打印I'm a Person
	*
	* @结论 虽然指针可以实现多态，但是对象的强行转化无法实现多态！！为什么呢？
	* @结论 因为传值的方式生成的是子类，如果是指针或引用则可以实现多态！
	*/
	p.print();

	/**
	* c1 = p1;
	* @结论 以值的方式转化，父类对象无法将值转化成子类，会报编译错误，因为父类缺少子类的零件！！！
	*/
}

