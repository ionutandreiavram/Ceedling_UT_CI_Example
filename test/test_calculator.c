#include "unity.h"
#include "calculator.h"
#include "mock_dummy_value.h"  // <-- this should be mocked or get_value function

void setUp(void) {}
    
void tearDown(void) {}

void test_add_numbers(void) {
    get_value_ExpectAndReturn(0);
    get_value_ExpectAndReturn(0);
    TEST_ASSERT_EQUAL_INT(5, add_numbers(3, 4));
    
    get_value_ExpectAndReturn(1);
    get_value_ExpectAndReturn(0);
    TEST_ASSERT_EQUAL_INT(7, add_numbers(3, 4));
}

void test_sub_numbers(void){
    get_value_ExpectAndReturn(0);
    TEST_ASSERT_EQUAL_INT(4, sub_numbers(8, 4));
    get_value_ExpectAndReturn(0);
    TEST_ASSERT_EQUAL_INT(-4, sub_numbers(0, 4));
}


    
