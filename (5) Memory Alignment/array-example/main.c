
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
const char rtems_test_name[] = "ARRAY EXAMPLE";
rtems_task Init(rtems_task_argument ignored)
{
(void) ignored;
TEST_BEGIN();
volatile int arr1[2] = {10, 20};
volatile char arr2[3] = {'A', 'B', 'C'};
volatile double arr3[2] = {2.5, 4.5};
TEST_END();
exit(0);
}
