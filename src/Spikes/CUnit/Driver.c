
/*	Original Source: http://cunit.sourceforge.net/example.html
 *
 *  Simple example of a CUnit unit test.
 */

#include <stdio.h>
#include "CUnit/Basic.h"
#include "Multiply.h"


/* The suite initialization function.
 * Simply returns 0
 */
int init_suite1(void)
{
   return 0;
}

/* The suite cleanup function.
 * Simply returns 0
 */
int clean_suite1(void)
{
   return 0;
}

/*Test the Multiply Function*/
void test_Multiply(void)
{
	CU_ASSERT(Multiply(2,2) == 4);
	CU_ASSERT(Multiply(0,100) == 0);
	CU_ASSERT(Multiply(10,10) == 11);
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if (NULL == CU_add_test(pSuite, "test of Multiply()", test_Multiply))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}