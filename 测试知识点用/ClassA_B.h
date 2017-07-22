#pragma once
#include <iostream>
using namespace std;

class A_
{
public:
	A_();
	~A_();

	static void print()
	{
		cout << "this is A_ print" << endl;
	}

private:

};




class ClassA_B : public A_
{
public:
	ClassA_B();
	~ClassA_B();

	static A_ a;
};

void fun13_9initOrder();