
/*	Original Source: http://cunit.sourceforge.net/example.html
 *
 *  Simple example of a CUnit unit test.
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "./qsolve/qsolve.h"

/* Pointer to the files used by the tests. */
static FILE* input_file = NULL;
static FILE* input_check = NULL;
static FILE* input_vars = NULL;

/* The suite initialization function.
 * Opens the temporary files used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{
   if (NULL == (input_file = fopen("mainLog.txt", "r")) 
   	|| NULL == (input_check = fopen("output.txt", "r"))
    || NULL == (input_vars = fopen("input.txt", "r"))) {
      return -1;
   }
   else {
      return 0;
   }
}


/* The suite cleanup function.
 * Closes the temporary files used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
   if (0 != fclose(input_file) 
   	|| 0 != fclose(input_check)
    || 0 != fclose(input_vars)) {
      return -1;
   }
   else {
      input_file = NULL;
      input_check = NULL;
      input_vars = NULL;
      return 0;
   }
}


/*Testing system*/
void test_System(void)
{
	//Run Input.c with input.txt, then check against expected results
	//Code taken from https://stackoverflow.com/questions/30811325/read-from-stdin-with-fgets-bug-if-input-is-greater-than-size
	int MAXLINE = 256; //For Now, accept this many chars in a line. THIS SHOULD BE HANDLED IN A SEPARATE PROGRAM LOOP
	int logicBoolean = 1; //whether or not to move on

	char str[MAXLINE];
	for (;;) {
		logicBoolean = 1; //reset boolean

  		if (fgets(str, MAXLINE, input_file) == NULL) 
  		{
	    	// No more to read or IO error
	    	break;
  		}
  		/**/

  		int len1 = strcspn(str, "\n");
  		int len2 = strcspn(str, "\0");

  		if(len1 == len2)//Error if EOF == newline, because then newline was never actually read- so consume chars until next newline
  		{
  			int ch;
  			if((ch = fgetc(input_file)) == '\n' || ch == EOF)
  			{
  				//If EOF/newline is only 1 char further, then it's ok

  			}
  			else
  			{
  				//printf("Input too long for %s! moving to next line\n", str);
  				logicBoolean = 0;//Invalid input

  				while ((ch = fgetc(input_file)) != '\n' && ch != EOF) 
  				{
  					//just consume extra chars
    			}
  			}
  		}
  		else//need to strip away last \n
  		{
  			str[strlen(str) - 1] = 0; //set to null
  		}

		if(logicBoolean == 1)
		{
			/*do actual test logic*/
			//printf("FINAL VALUE: %s;\n", str);

			int ret = atoi(str);
			char expected[5]; //expected return code from file
			fgets(expected, 5, input_check);
			printf("expected: %s; got: %i\n\n", expected, ret);
			CU_ASSERT(ret == atoi(expected));
		}
	}
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
   if (NULL == CU_add_test(pSuite, "System testing", test_System))
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
