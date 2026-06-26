#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <stdlib.h>
#include <buffer_test_io.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
const char rtems_test_name[] = "ARITH EXAMPLE";
volatile int compute_add_sub(int a, int b, int c){
volatile int r1 = a + b;
volatile int r2 = r1 - c;
volatile int r3 = r2 + 7;
volatile int r4 = r3 - 5;
volatile int r5 = r4 + a;
return r5;
}

rtems_task Init(rtems_task_argument ignored)
{
(void) ignored;
TEST_BEGIN();
volatile int a = 10;
    volatile int b = 3;
    volatile int c = 4;
    volatile int result = compute_add_sub(a, b, c);
    printf("IU add/sub result = %d\n", result);
TEST_END();
exit(0);
}

