#include <stdio.h>
#include <assert.h>
#include "CUnit/Console.h"

extern int AddTestMainModule();

int main()
{
   
	if( CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	assert(NULL != CU_get_registry());
	
	assert(!CU_is_test_running()); 

	if (0 != AddTestMainModule())
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_console_run_tests();

	/***......XML.....********
	CU_set_output_filename("TestMax");
        CU_list_tests_to_file();
	CU_automated_run_tests();
	***********************************/
	
	CU_cleanup_registry();
	
	return 0;
}
