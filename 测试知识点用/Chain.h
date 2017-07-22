#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

class CChainHeader;
class CChainItem
{
public:
	CChainItem();
	~CChainItem();

	void SetHead(CChainItem* pCi);
private:
	CChainHeader*		m_pHead;
};

class CChainHeader : public CChainItem
{
	friend class CChainItem;
private:

	CChainItem*			m_pHead;

public:
	CChainHeader();
	virtual ~CChainHeader();

	void SetHead(CChainItem* pItem);

};

void fun_13_8_ChainItemChainHeader();