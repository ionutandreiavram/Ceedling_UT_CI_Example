#ifndef FIBONACCI_H
#define FIBONACCI_H
#include <stdint.h>
#include <stdio.h>
#include "fibonacci.h"

uint64_t fibonacci_calculator(int n)
{
    if (0 >= n || 1 == n) return 0;

    uint64_t a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    printf("For number %d fibonacci value is %u", n, b);
    return b;
}
#endif
