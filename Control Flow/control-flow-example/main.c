#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

const char rtems_test_name[] = "CONTROL FLOW 1";

__attribute__((noinline)) static uint32_t get_runtime_seed(void)
{
    return rtems_clock_get_ticks_since_boot();
}

__attribute__((noinline)) static void int_if_else_demo(uint32_t seed)
{
    int a = (int)(seed & 0x1fU);
    int b = (int)((seed >> 3) & 0x0fU) + 1;
    int sum = a + b;

    if ((sum & 1) == 0) {
        printf("[1] int if-else: %d + %d = %d (even)\n", a, b, sum);
    } else {
        printf("[1] int if-else: %d + %d = %d (odd)\n", a, b, sum);
    }
}

__attribute__((noinline)) static void float_if_else_demo(uint32_t seed)
{
    double x = (double)((seed % 50U) + 1U);
    double y = (double)(((seed / 3U) % 9U) + 1U);
    double ratio = x / y;
    double threshold = (double)(((seed / 5U) % 4U) + 1U);

    if (ratio >= threshold) {
        printf("[2] float if-else: %.2f / %.2f = %.2f (ratio >= %.2f)\n", x, y, ratio, threshold);
    } else {
        printf("[2] float if-else: %.2f / %.2f = %.2f (ratio < %.2f)\n", x, y, ratio, threshold);
    }
}

__attribute__((noinline)) static void int_for_while_demo(uint32_t seed)
{
    int n = (int)(seed % 8U) + 3;
    int for_sum = 0;
    int while_sum = 0;
    int i = 1;

    for (i = 1; i <= n; ++i) {
        for_sum += i;
    }
    printf("[3] for loop:   sum(1..%d) = %d\n", n, for_sum);

    i = 1;
    while (i <= n) {
        while_sum += i;
        ++i;
    }
    printf("[3] while loop: sum(1..%d) = %d\n", n, while_sum);
}

rtems_task Init(rtems_task_argument ignored)
{
    (void)ignored;
    TEST_BEGIN();

    /* Runtime seed from system ticks; prevents compile-time branch folding. */
    uint32_t seed = get_runtime_seed();
    int_if_else_demo(seed);
    float_if_else_demo(seed + 1U);
    int_for_while_demo(seed + 2U);

    TEST_END();
    exit(0);
}
