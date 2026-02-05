
#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <stdlib.h>
#include <buffer_test_io.h>
#include <stdio.h>
#include <math.h>
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
const char rtems_test_name[] = "NORMALIZED EXAMPLE";
rtems_task Init(rtems_task_argument ignored)
{
(void) ignored;
TEST_BEGIN();
volatile double d = 0.0;
volatile double d1 = INFINITY;
volatile double d2 = -INFINITY;
volatile double d3 = NAN;
volatile double d4 = -NAN;
volatile double d5 = 1.0/0.0;
volatile double d6 = sqrt(-1);
TEST_END();
exit(0);
}

