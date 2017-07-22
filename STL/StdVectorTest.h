#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class CStdVectorTest
{
public:
	struct tagFieldInfo
	{
		unsigned int	nFieldIndex;
		int				nFieldType;
		int				nIndex;
		int				nBrief;
	};

public:
	CStdVectorTest();
	~CStdVectorTest();
};

void Test();

void TestMap();

void TestStdChronoMilliseconds();


