
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
const char rtems_test_name[] = "POINTER EXAMPLE";
int add(int x, int y) { return x + y; }
rtems_task Init(rtems_task_argument ignored) {
(void) ignored;
TEST_BEGIN();
volatile int (*f)(int, int) = add;
volatile int A1[3];
volatile int *A2[3];
volatile char (*A3)[3];
volatile char *A4[3][5];
volatile double (*A5)[3][5];
volatile double (*A6[3])[5];
TEST_END();
exit(0);
}