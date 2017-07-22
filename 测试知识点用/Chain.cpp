#include "Chain.h"


CChainItem::CChainItem()
{
	m_pHead = NULL;
}


CChainItem::~CChainItem()
{
}

void CChainItem::SetHead(CChainItem* pCi)
{
	m_pHead = static_cast<CChainHeader*>(pCi);
}

CChainHeader::CChainHeader()
{
	m_pHead = NULL;
}

CChainHeader::~CChainHeader()
{

}

void CChainHeader::SetHead(CChainItem* pItem)
{
	/*给自己的成员变量赋值*/
	m_pHead = pItem;	

	/*如果给父类赋值则调用父类的函数*/
	CChainItem::SetHead(pItem);
}

void fun_13_8_ChainItemChainHeader()
{
	CChainHeader ch;
	CChainItem* pCi = new CChainItem;
	ch.SetHead(pCi);

	cout << "Hello World" << endl;
	delete pCi;
}
