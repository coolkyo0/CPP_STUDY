/**
* ѧϰҪ��
*
* @Ҫ��һ �ں�������ʵ�ֲ������ļӷ�
* @Ҫ��� �ں�������ʵ�ֲ������ļӷ��Ƿ��뺯������Ч��һ���أ�
* @see http://www.cnblogs.com/cutepig/archive/2009/01/14/1375930.html
* @answer1 ����������Ҫ1�������Ϳ����ˣ���Ϊ�౾��Ҳ�������㣬Ҳ�൱��һ��������
* @answer2 ��ֵ�����"="�ǲ������������صġ�
* @answer3 ����������ǧ��𷵻����ã���Ϊ���õĵ�ַ������������ڴ������ջ�ϵľֲ�������ֵ���в���Ԥ֪�ԣ��������������Ҫ������Ķ���
*/

#pragma once
#include <iostream>
using namespace std;

class COverLoad
{
public:
	COverLoad();
	COverLoad(int i1, int i2);
	COverLoad(const COverLoad& col);

	virtual ~COverLoad();

	/**
	* �ں����������ز�����+
	*
	*/
	COverLoad operator + (const COverLoad& rhs);

	/**
	* �ں����������ظ�ֵ������ = 
	*/
	COverLoad& operator = (const COverLoad& rhs);

	/**
	* �ں����������ظ�ֵ������ -

	* @note ���������ڻ������������ز����������ܷ������ð�������������
	*
	*/
	COverLoad operator - (const COverLoad& rhs);

	int a;
	int b;
};

/**
* �ں����������ز����� =����ʵ��COverLoad�ĸ�ֵ����
*
* @note ���Ƿ��֣����������ظ�ֵ������ʱ����ִ�����ʾ�������ǳ�Ա����

* @question ������������ظ�ֵ��������
*/



/**
* �ں����������ز����� *����ʵ��COverLoad�ĳ˷�����
*
* @NOTE ������ʵ�ֳ˷������������ֻ��Ҫһ����������������ʵ�ֳ˷��������������Ҫ2������
*/
COverLoad operator * (const COverLoad& c1, const COverLoad& c2);

void fun13_3overloadTest();