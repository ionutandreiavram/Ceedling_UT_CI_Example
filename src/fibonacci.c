#ifndef FIBONACCI_H
#define FIBONACCI_H
#include "fibonacci.h"
#include <stdint.h>

uint64_t fibonacci_calculator(uint64_t n)
{
    if (0 >= n || 1 == n) return 0;

    uint64_t a = 0, b = 1, c;
    for (uint64_t i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
#endif
