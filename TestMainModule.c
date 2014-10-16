#include <stdio.h>
#include <assert.h>
#include <CUnit/Console.h>
#include "Triangle.h"

int InitSuite()
{
	return 0;
} 

int EndSuite()
{
	return 0;
}

int Test_IsEquilateral(int a, int b, int c)
{
	int result;

	result = triangle(a, b, c);
	if(result == IsEquilateral)
	{
		return 1;
	}
	return 0;
}

int Test_IsIsosceles(int a, int b, int c)
{
	int result;

	result = triangle(a, b, c);
	if(result == IsIsosceles)
	{
		return 1;
	}
	return 0;
}

int Test_NotATriangle(int a, int b, int c)
{
	int result = triangle(a, b, c);
	if(result == NotTriangle)
		return 1;
	return 0;
}

void OneBoundary()
{
	//Normal Boundary Value
	CU_ASSERT(Test_IsIsosceles(1, 100, 100));
	CU_ASSERT(Test_NotATriangle(200, 100, 100));
	CU_ASSERT(Test_IsIsosceles(100, 1, 100));
	CU_ASSERT(Test_NotATriangle(100, 200, 100));
	CU_ASSERT(Test_IsIsosceles(100, 100, 1));
	CU_ASSERT(Test_NotATriangle(100, 100, 200));
}

void TwoBoundary()
{
	CU_ASSERT(Test_NotATriangle(100, 1, 1));
	CU_ASSERT(Test_NotATriangle(100, 1, 200));
        CU_ASSERT(Test_NotATriangle(100, 200, 1));
	CU_ASSERT(Test_IsIsosceles(100, 200, 200));
        CU_ASSERT(Test_NotATriangle(1, 100, 1));
	CU_ASSERT(Test_NotATriangle(1, 100, 200));
        CU_ASSERT(Test_NotATriangle(200, 100, 1));
	CU_ASSERT(Test_IsIsosceles(200, 100, 200));
        CU_ASSERT(Test_NotATriangle(1, 1, 100));
	CU_ASSERT(Test_NotATriangle(1, 200, 100));
        CU_ASSERT(Test_NotATriangle(200, 1, 100));
	CU_ASSERT(Test_IsIsosceles(200, 200, 100));
}

void ThreeBoundary()
{
	CU_ASSERT(Test_NotATriangle(1, 1, 1));
	CU_ASSERT(Test_NotATriangle(200, 200, 200));
}


int AddTestMainModule()
{
	CU_pSuite pSuite = NULL;

	pSuite = CU_add_suite("BoundaryValueTest", InitSuite, EndSuite);  
	CU_add_test(pSuite, "OneBoundary", OneBoundary);
	CU_add_test(pSuite, "TwoBoundary", TwoBoundary);
	CU_add_test(pSuite, "ThreeBoundary", ThreeBoundary);
	
	return 0;
}
