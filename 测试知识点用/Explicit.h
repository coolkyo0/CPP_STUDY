/**
* ѧϰ��ʾ���õ��÷��Լ��ô�
*

�����http://www.cnblogs.com/this-543273659/archive/2011/08/02/2124596.html
explicit �ؼ���ֻ���������ڲ��Ĺ��캯�������ϡ�
explicit �ؼ��������ڵ��������Ĺ��캯����
��C++�У�explicit�ؼ�������������Ĺ��캯���������εĹ��캯�����࣬���ܷ�����Ӧ����ʽ����ת��

http://blog.csdn.net/luomoshusheng/article/details/47133603

*/
#pragma once
class Explicit
{
public:
	explicit Explicit();

	/** ʹ��explicit���ξͲ�����ʽת���ˣ�������ʾ�ĵ��� */
	explicit	
		Explicit(int i);
	~Explicit();

	int m_i;
};

void fun13_4explicitTest();