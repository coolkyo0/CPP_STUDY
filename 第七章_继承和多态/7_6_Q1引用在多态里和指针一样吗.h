/**
* ���������Ƿ���ָ��һ��Ҳ���Խ��ж�̬���ã�
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
* ���ÿɷ���ָ��һ��ʵ�ֶ�̬�أ�
*
* @���� ���ú�ָ��һ������ʵ�ֶ�̬���ԣ�������������ָ�룡
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
	* ��ӡI'm a Person
	*
	* @���� ��Ȼָ�����ʵ�ֶ�̬�����Ƕ����ǿ��ת���޷�ʵ�ֶ�̬����Ϊʲô�أ�
	* @���� ��Ϊ��ֵ�ķ�ʽ���ɵ������࣬�����ָ������������ʵ�ֶ�̬��
	*/
	p.print();

	/**
	* c1 = p1;
	* @���� ��ֵ�ķ�ʽת������������޷���ֵת�������࣬�ᱨ���������Ϊ����ȱ����������������
	*/
}

