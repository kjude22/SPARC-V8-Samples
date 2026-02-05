
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
volatile float f1 = 1.0f;
volatile float f2 = 1.5f;
volatile double d1 = 2.75;
volatile double d2 = 5.25;
TEST_END();
exit(0);
}

