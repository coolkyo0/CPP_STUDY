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

/** ��������ǰ����h1��Ϊ�������п�������һ��human_h1 */
human f1(human x)
{
	x.print(NULL);
	return x;	
	/** 
	return����ִ��һ�ο������죬
	�����������Ĺ�������human_h1��Ϊ�������п������죬
	�ѿ�������Ķ���ֵ��h2��ʵ���ϼ�ʹû��h2���շ���ֵ��return��Ȼ�ṹ��һ���������з��ء�
	*/

	/**
	* �����β���return֮��Ĺ�ϵ
	* @���� ��������β�Ϊ������һ�����󣬹��췽ʽ��λ�����Ƹ��ƣ����Թ���Ķ����������ǳ�����ͻ����Σ�գ�
	* @���� returnʱ����return�Ķ�����һ���������죬Ȼ�������������Ķ��󣬰ѿ�������Ķ��󷵻ء�
	*/

	/**
	* return human rt(x);
	* ����x
	*/
}

void staticVarAndCopyConstruct()
{
	human h1;				/**��������һ�Ρ�*/
	h1.print(NULL);
	//human h2 = f1(h1);		
	f1(h1);

	//h2.print(NULL);


	/**
	* ����human rt(x)
	* ����h1
	*/
}