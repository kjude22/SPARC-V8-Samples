
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
const char rtems_test_name[] = "STRUCT EXAMPLE";
struct S1 {
    char c;
    int i[2];
    double v;
};
rtems_task Init(rtems_task_argument ignored)
{
(void) ignored;
TEST_BEGIN();
volatile struct S1 s;
s.c='a';
s.i[0]=10;
s.i[1]=20;
s.v=3.14;
TEST_END();
exit(0);
}
