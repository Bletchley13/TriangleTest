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

int Test_IsScalene(int a, int b, int c)
{
        int result;

        result = triangle(a, b, c);
        if(result == IsScalene)
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

int Test_IsInvalidInput(int a, int b, int c)
{
        int result = triangle(a, b, c);
        if(result == InvalidInput)
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
	CU_ASSERT(Test_IsEquilateral(1, 1, 1));
	CU_ASSERT(Test_IsEquilateral(200, 200, 200));
}

void IsoscelesClass()
{
	CU_ASSERT(Test_IsIsosceles(2, 2, 3));
	CU_ASSERT(Test_IsIsosceles(4, 5, 4));
	CU_ASSERT(Test_IsIsosceles(7, 3, 7));
}

void IsoscelesEdgeClass()
{
        CU_ASSERT(Test_IsInvalidInput(-1, -1, 2));
        CU_ASSERT(Test_IsInvalidInput(201, 5, 201));
        CU_ASSERT(Test_IsInvalidInput(-3, -3, 201));
	CU_ASSERT(Test_IsIsosceles(2, 2, 3));
	CU_ASSERT(Test_IsIsosceles(200, 199, 200));
}

void EquilateralClass()
{
        CU_ASSERT(Test_IsEquilateral(2, 2, 2));
        CU_ASSERT(Test_IsEquilateral(101, 101, 101));
        CU_ASSERT(Test_IsEquilateral(199, 199, 199));
}

void EquilateralEdgeClass()
{
        CU_ASSERT(Test_IsInvalidInput(-2, -2, -2));
        CU_ASSERT(Test_IsInvalidInput(201, 201, 201));
        CU_ASSERT(Test_IsEquilateral(199, 199, 199));
	CU_ASSERT(Test_IsEquilateral(1, 1, 1));
}

void ScaleneClass()
{
	CU_ASSERT(Test_IsScalene(2, 3, 4));
	CU_ASSERT(Test_IsScalene(2, 198, 199));
	CU_ASSERT(Test_IsScalene(10, 11, 12));
}

void ScaleneEdgeClass()
{
        CU_ASSERT(Test_IsInvalidInput(-2, 3, 4));
        CU_ASSERT(Test_IsInvalidInput(2, 198, 201));
        CU_ASSERT(Test_IsScalene(2, 3, 4));
}

void NotTriangleClass()
{
	CU_ASSERT(Test_NotATriangle(1, 2, 3));
	CU_ASSERT(Test_NotATriangle(1, 4, 5));
	CU_ASSERT(Test_NotATriangle(1, 4, 200));
}

void NotTriangleEdgeClass()
{
        CU_ASSERT(Test_IsInvalidInput(-1, 2, 3));
        CU_ASSERT(Test_NotATriangle(1, 2, 3));
        CU_ASSERT(Test_NotATriangle(1, 4, 201));
	CU_ASSERT(Test_IsIsosceles(1, 200, 200));
}


void InvalidInputClass()
{
	CU_ASSERT(Test_IsInvalidInput(-1, 1, 4));
	CU_ASSERT(Test_IsInvalidInput(1, -1, 4));
	CU_ASSERT(Test_IsInvalidInput(2, 1, -4));
	CU_ASSERT(Test_IsInvalidInput(201, 1, 4));
        CU_ASSERT(Test_IsInvalidInput(1, 201, 4));
        CU_ASSERT(Test_IsInvalidInput(2, 1, 202));
	CU_ASSERT(Test_IsInvalidInput(-1, 1, 400));
        CU_ASSERT(Test_IsInvalidInput(1, -1, 400));
        CU_ASSERT(Test_IsInvalidInput(200, 1, -4));
	CU_ASSERT(Test_IsInvalidInput(200, -1, -4));
}

int AddTestMainModule()
{
	CU_pSuite pSuite = NULL;

	pSuite = CU_add_suite("BoundaryValueTest", InitSuite, EndSuite);  
	CU_add_test(pSuite, "OneBoundary", OneBoundary);
	CU_add_test(pSuite, "TwoBoundary", TwoBoundary);
	CU_add_test(pSuite, "ThreeBoundary", ThreeBoundary);
	
	pSuite = CU_add_suite("EquivalenceClassTest", InitSuite, EndSuite);
	CU_add_test(pSuite, "IsoscelesClass", IsoscelesClass);
	CU_add_test(pSuite, "EquilateralClass", EquilateralClass);
	CU_add_test(pSuite, "ScaleneClass", ScaleneClass);
	CU_add_test(pSuite, "NotTriangleClass", NotTriangleClass);
	CU_add_test(pSuite, "InvalidInputClass", InvalidInputClass);

	pSuite = CU_add_suite("EdgeTest", InitSuite, EndSuite);
	CU_add_test(pSuite, "IsoscelesEdgeClass", IsoscelesClass);
        CU_add_test(pSuite, "EquilateralEdgeClass", EquilateralClass);
        CU_add_test(pSuite, "ScaleneEdgeClass", ScaleneClass);
        CU_add_test(pSuite, "NotTriangleEdgeClass", NotTriangleClass);
	return 0;
}
