#pragma once

#include <iostream>

using namespace std;

class human
{
public:
	human()
	{
		human_num++;
		OutputDebugString("\nhuman()\n");
		cout << "human()" << endl;
	}
	human(const human& h)
	{
		OutputDebugString("\nhuman(const human& h)\n");
		cout << "human(const human& h)" << endl;
	}
	~human()
	{
		human_num--;
		cout << "~human()" << endl;
	}
	void print(const char* pcstr)
	{
		char ch[100];
		sprintf_s(ch, "\n%s human_num is %d\n", pcstr, human_num);
		OutputDebugString(ch);
		//cout << "human_num is " << human_num << endl;
	}

	static int human_num;
};

int human::human_num = 0;

/** 函数调用前会用h1对为参数进行拷贝构造一个human_h1 */
human f1(human x)
{
	x.print(NULL);
	return x;	
	/** 
	return语句会执行一次拷贝构造，
	这个拷贝构造的过程是以human_h1作为蓝本进行拷贝构造，
	把拷贝构造的对象赋值给h2，实际上即使没有h2接收返回值，return依然会构造一个副本进行返回。
	*/

	/**
	* 关于形参与return之间的关系
	* @结论 函数会把形参为对象构造一个对象，构造方式是位二进制复制，所以构造的对象如果存在浅拷贝就会存在危险！
	* @结论 return时会以return的对象做一个拷贝构造，然后析构被拷贝的对象，把拷贝构造的对象返回。
	*/

	/**
	* return human rt(x);
	* 析构x
	*/
}

void staticVarAndCopyConstruct()
{
	human h1;				/**　构造了一次　*/
	h1.print(NULL);
	//human h2 = f1(h1);		
	f1(h1);

	//h2.print(NULL);


	/**
	* 析构human rt(x)
	* 析构h1
	*/
}