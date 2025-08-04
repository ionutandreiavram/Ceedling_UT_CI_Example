#include "unity.h"
#include "concatenate.h"

void setUp(void) {}
    
void tearDown(void) {}

void test_concatenate(void) {

    uint8_t test_input1[5]={0x12, 0x99, 0xFF,  0xF1, 0x00};
    uint8_t test_input2[5]={0x00, 0x11, 0x12,  0x13, 0x14};
    int size = (sizeof(test_input1)/sizeof(test_input1[0]));
	uint16_t current_result[size];
    uint16_t expected_result[5]={0x1200, 0x9911, 0xFF12, 0xF113, 0x0014};
    Concatenate_arrays(test_input1, test_input2, current_result, size);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(expected_result, current_result, size);

    uint8_t test_input11[1]={0x12};
    uint8_t test_input21[1]={0x14};
    int size1 = (sizeof(test_input11)/sizeof(test_input11[0]));
	uint16_t current_result1[size1];
    uint16_t expected_result1[1]={0x1214};
    Concatenate_arrays(test_input11, test_input21, current_result1, size1);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(expected_result1, current_result1, size1);
}