
/*	Original Source: http://cunit.sourceforge.net/example.html
 *
 *  Simple example of a CUnit unit test.
 */

#include <stdio.h>
#include "CUnit/Basic.h"
#include <math.h>

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

/*Test multiple aspects of IEEE aithmetic on sqrt*/
void test_IEEE_sqrt(void)
{
	CU_ASSERT(sqrt(4.0) == 2.0);
	CU_ASSERT(sqrt(25.0) == 5.0);
	CU_ASSERT(sqrt(9.0) != 3.000000000001);
   CU_ASSERT(sqrt(0.0) == 0.0);
   CU_ASSERT(sqrt(+0.0) == +0.0);
   CU_ASSERT(sqrt(-0.0) == -0.0);
   CU_ASSERT(isnan(sqrt(-1)) != 0);
   CU_ASSERT(isnan(sqrt(NAN)) != 0);
   CU_ASSERT(isinf(sqrt(INFINITY)) == 1);
   CU_ASSERT(isnan(sqrt(-INFINITY)) != 0);
   
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
   if (NULL == CU_add_test(pSuite, "test of IEEE sqrt", test_IEEE_sqrt))
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