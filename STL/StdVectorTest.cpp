#include "StdVectorTest.h"
#include <chrono>


CStdVectorTest::CStdVectorTest()
{

}


CStdVectorTest::~CStdVectorTest()
{
}

void Test()
{
	vector<CStdVectorTest*> vTest(100, NULL);
	CStdVectorTest* &v = vTest[0];

	v = new CStdVectorTest;

	cout << "Hello World!" << endl;
	cout << vTest[0] << endl;
}

void TestMap()
{
	map<string, CStdVectorTest::tagFieldInfo> M;
	M["H"];
	M["e"];
	M["l"];
	M["l"];
	M["o"];
}

void TestStdChronoMilliseconds()
{
	//std::chrono::milliseconds t(1);

}