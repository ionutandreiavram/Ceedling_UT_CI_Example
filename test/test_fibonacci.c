#include "unity.h"
#include "fibonacci.h"

void setUp(void) {}
    
void tearDown(void) {}

void test_fibonacci(void){

	TEST_ASSERT_EQUAL_UINT64(0, fibonacci_calculator(0));
	TEST_ASSERT_EQUAL_UINT64(0, fibonacci_calculator(1));
	TEST_ASSERT_EQUAL_UINT64(1, fibonacci_calculator(2)); 
    TEST_ASSERT_EQUAL_UINT64(2, fibonacci_calculator(3)); 
    TEST_ASSERT_EQUAL_UINT64(3, fibonacci_calculator(4)); 
    TEST_ASSERT_EQUAL_UINT64(5, fibonacci_calculator(5)); 
    TEST_ASSERT_EQUAL_UINT64(12200160415121876738, fibonacci_calculator(93));
// F(94) will overflow
}
