#pragma once

class CA
{
public:
	CA();
	~CA();


	static int m;


	/** Ϊʲô��ľ�̬��Ա�������������н��г�ʼ��������� */
	const static int n = 0;
};

/**
* ��̬��Ա�����Ժ�����ʼ�����������ִ���error LNK2001: �޷��������ⲿ���� "public: static int CA::m" (?m@CA@@2HA)
* error LNK1120: 1 ���޷��������ⲿ����	D:\STUDY\CPP_STUDY\Debug\classStaticMemStoreWhere.exe	classStaticMemStoreWhere
* @note ��ʼ������Ϊstatic int CA::m = 0;
* @note ��ʼ�����ܷ���ͷ�ļ��У��������ִ���	1	error LNK2005: "public: static int CA::m" (?m@CA@@2HA) �Ѿ��� A.obj �ж���	
* @note ����	2	error LNK1169: �ҵ�һ���������ض���ķ���	D:\STUDY\CPP_STUDY\Debug\classStaticMemStoreWhere.exe	classStaticMemStoreWhere
*/