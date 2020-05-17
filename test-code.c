#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "CuTest.h"

// NOTE: your functions that you write must go BEFORE the test functions. Alternatively, to keep things more organized, compile them separately - have real code and test code in separate files and have the real code compiled BEFORE the test code to avoid "implicit declaration" errors.
int add_numbers(int* a, int* b) {
    return *a + *b;
}

void test_add_numbers(CuTest *tc) {
   int a = 20;
   int b = 32;
   CuAssertIntEquals(tc, 52, add_numbers(&a, &b));
   CuAssertIntEquals(tc, 64, add_numbers(&b, &b));
}

int main(int argc, char *argv[]) {

    // These allocate memory for the test suite and output respectively. These functions act like **malloc()** in the malloc()/free() methods for C memory allocation
    CuSuite* suite = CuSuiteNew();
    CuString *output = CuStringNew();

    SUITE_ADD_TEST(suite, test_add_numbers);
    // add other tests with SUITE_ADD_TEST(suite, method_name)

    CuSuiteRun(suite); // runs the "test suite"
    CuSuiteSummary(suite, output); // prints test summaries
    CuSuiteDetails(suite, output); // prints details
    printf("%s\n", output->buffer); // prints output from other C code (not part of the test suite)
    // (Why we have to do these deletes? To free up memory. These functions act like **free()** in the malloc()/free() methods for C memory allocation)
    CuStringDelete(output); // free memory for the output
    CuSuiteDelete(suite); // free memory for the test suite 
}
 
