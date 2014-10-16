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

void Test1()
{
	//Normal Boundary Value
	CU_ASSERT(Test_IsEquilateral(3, 4, 7));
}

void Test2()
{
	CU_ASSERT(Test_IsIsosceles(4, 5, 10));
}

int AddTestMainModule()
{
	CU_pSuite pSuite = NULL;

	pSuite = CU_add_suite("BoundaryValueTest", InitSuite, EndSuite);  

	if(NULL == pSuite)
	{
		//return 1;
	}
	
	if( NULL == CU_add_test(pSuite, "Test1", Test1) ||
		NULL == CU_add_test(pSuite, "Test2", Test2))
	{
		return 1;
	}
	
	/***........***************/
	/*
	CU_TestInfo testcases[] = {
        {"Test1:", Test1},
        {"Test2:", Test2},
        CU_TEST_INFO_NULL
	};

	CU_SuiteInfo suites[] = {
		{"Testing the function cal_num:", InitSuite, EndSuite, testcases},
        CU_SUITE_INFO_NULL
	};

	if(CUE_SUCCESS != CU_register_suites(suites))
	{
		return 1;
	}
	*/
	/************************************/

	return 0;
}
